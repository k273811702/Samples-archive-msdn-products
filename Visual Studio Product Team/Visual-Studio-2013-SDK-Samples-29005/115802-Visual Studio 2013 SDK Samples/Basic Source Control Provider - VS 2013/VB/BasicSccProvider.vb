'**************************************************************************
'
'Copyright (c) Microsoft Corporation. All rights reserved.
'THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
'ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
'IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
'PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
'
'**************************************************************************

Imports Microsoft.VisualBasic
Imports System
Imports System.Diagnostics
Imports System.Globalization
Imports System.Runtime.InteropServices
Imports System.ComponentModel.Design
Imports Microsoft.Win32
Imports Microsoft.VisualStudio.Shell.Interop
Imports Microsoft.VisualStudio.OLE.Interop
Imports Microsoft.VisualStudio

Imports MsVsShell = Microsoft.VisualStudio.Shell
Imports ErrorHandler = Microsoft.VisualStudio.ErrorHandler

'///////////////////////////////////////////////////////////////////////////
' BasicSccProvider
' Declare that resources for the package are to be found in the managed assembly resources, and not in a satellite dll
' Register the resource ID of the CTMENU section (generated from compiling the VSCT file), so the IDE will know how to merge this package's menus with the rest of the IDE when "devenv /setup" is run
' The menu resource ID needs to match the ResourceName number defined in the csproj project file in the VSCTCompile section
' Everytime the version number changes VS will automatically update the menus on startup; if the version doesn't change, you will need to run manually "devenv /setup /rootsuffix:Exp" to see VSCT changes reflected in IDE
' Register the package to have information displayed in Help/About dialog box
' Register a sample options page visible as Tools/Options/SourceControl/SampleOptionsPage when the provider is active
' Register a sample tool window visible only when the provider is active
' Register the source control provider's service (implementing IVsScciProvider interface)
' Register the source control provider to be visible in Tools/Options/SourceControl/Plugin dropdown selector
' Pre-load the package when the command UI context is asserted (the provider will be automatically loaded after restarting the shell if it was active last time the shell was shutdown)
' Declare the package guid
<MsVsShell.DefaultRegistryRoot("Software\Microsoft\VisualStudio\12.0Exp"), _
MsVsShell.PackageRegistration(UseManagedResourcesOnly:=True), _
MsVsShell.ProvideMenuResource("Menus.ctmenu", 1), _
MsVsShell.InstalledProductRegistration("#100", "#101", "1.0", IconResourceID:=CommandIds.iiconProductIcon), _
MsVsShell.ProvideOptionPageAttribute(GetType(SccProviderOptions), "Source Control", "Sample Options Page Basic Provider", 106, 107, False), _
ProvideToolsOptionsPageVisibility("Source Control", "Sample Options Page Basic Provider", GuidStrings.GuidSccProvider), _
MsVsShell.ProvideToolWindow(GetType(SccProviderToolWindow)), _
MsVsShell.ProvideToolWindowVisibility(GetType(SccProviderToolWindow), GuidStrings.GuidSccProvider), _
MsVsShell.ProvideService(GetType(SccProviderService), ServiceName:="Source Control Sample Basic Provider Service"), _
ProvideSourceControlProvider("Managed Source Control Sample Basic Provider", "#100"), _
MsVsShell.ProvideAutoLoad(GuidStrings.GuidSccProvider), _
Guid(GuidStrings.GuidSccProviderPkg)> _
Public Class BasicSccProvider
    Inherits MsVsShell.Package
    Private sccService As SccProviderService = Nothing

    '///////////////////////////////////////////////////////////////////////////
    ' BasicSccProvider Package Implementation
#Region "Package Members"

    Protected Overrides Sub Initialize()
        ' Called when the package is loaded, performs package initialization tasks such as registering the source control provider
        MyBase.Initialize()

        ' Proffer the source control service implemented by the provider.
        sccService = New SccProviderService(Me)
        CType(Me, IServiceContainer).AddService(GetType(SccProviderService), sccService, True)

        ' Add our command handlers for menu (commands must exist in the .vsct file).
        Dim mcs As MsVsShell.OleMenuCommandService = TryCast(GetService(GetType(IMenuCommandService)), MsVsShell.OleMenuCommandService)
        If mcs IsNot Nothing Then
            Dim cmd As New CommandID(GuidList.guidSccProviderCmdSet, CommandIds.icmdSccCommand)
            Dim menuCmd As New MenuCommand(New EventHandler(AddressOf OnSccCommand), cmd)
            mcs.AddCommand(menuCmd)

            ' ToolWindow Command.
            cmd = New CommandID(GuidList.guidSccProviderCmdSet, CommandIds.icmdViewToolWindow)
            menuCmd = New MenuCommand(New EventHandler(AddressOf ViewToolWindow), cmd)
            mcs.AddCommand(menuCmd)

            ' ToolWindow's ToolBar Command.
            cmd = New CommandID(GuidList.guidSccProviderCmdSet, CommandIds.icmdToolWindowToolbarCommand)
            menuCmd = New MenuCommand(New EventHandler(AddressOf ToolWindowToolbarCommand), cmd)
            mcs.AddCommand(menuCmd)
        End If

        ' Register the provider with the source control manager.
        ' If the package is to become active, this will also callback on OnActiveStateChange and the menu commands will be enabled.
        Dim rscp As IVsRegisterScciProvider = CType(GetService(GetType(IVsRegisterScciProvider)), IVsRegisterScciProvider)
        rscp.RegisterSourceControlProvider(GuidList.guidSccProvider)
    End Sub

    Protected Overloads Overrides Sub Dispose(ByVal disposing As Boolean)
        ' Called when the package is closed
        MyBase.Dispose(disposing)
    End Sub

#End Region


    Private Sub OnSccCommand(ByVal sender As Object, ByVal e As EventArgs)
        ' Toggle the checked state of this command.
        Dim thisCommand As MenuCommand = TryCast(sender, MenuCommand)
        If thisCommand IsNot Nothing Then
            thisCommand.Checked = Not thisCommand.Checked
        End If
    End Sub

    ''' <summary>
    ''' The function can be used to bring back the provider's toolwindow if it was previously closed.
    ''' </summary>
    ''' <param name="sender"></param>
    ''' <param name="e"></param>
    Private Sub ViewToolWindow(ByVal sender As Object, ByVal e As EventArgs)
        Me.ShowSccProviderToolWindow()
    End Sub

    Private Sub ToolWindowToolbarCommand(ByVal sender As Object, ByVal e As EventArgs)
        Dim window As SccProviderToolWindow = CType(Me.FindToolWindow(GetType(SccProviderToolWindow), 0, True), SccProviderToolWindow)

        If window IsNot Nothing Then
            window.ToolWindowToolbarCommand()
        End If
    End Sub

    ' This function is called by the IVsSccProvider service implementation when the active state of the provider changes.
    ' The package needs to show or hide the scc-specific commands. 
    Public Overridable Sub OnActiveStateChange()
        Dim mcs As MsVsShell.OleMenuCommandService = TryCast(GetService(GetType(IMenuCommandService)), MsVsShell.OleMenuCommandService)
        If mcs IsNot Nothing Then
            Dim cmd As New CommandID(GuidList.guidSccProviderCmdSet, CommandIds.icmdSccCommand)
            Dim menuCmd As MenuCommand = mcs.FindCommand(cmd)
            menuCmd.Supported = True
            menuCmd.Enabled = sccService.Active
            menuCmd.Visible = sccService.Active

            cmd = New CommandID(GuidList.guidSccProviderCmdSet, CommandIds.icmdViewToolWindow)
            menuCmd = mcs.FindCommand(cmd)
            menuCmd.Supported = True
            menuCmd.Enabled = sccService.Active
            menuCmd.Visible = sccService.Active

            cmd = New CommandID(GuidList.guidSccProviderCmdSet, CommandIds.icmdToolWindowToolbarCommand)
            menuCmd = mcs.FindCommand(cmd)
            menuCmd.Supported = True
            menuCmd.Enabled = sccService.Active
            menuCmd.Visible = sccService.Active
        End If

        ShowSccProviderToolWindow()
    End Sub

    Private Sub ShowSccProviderToolWindow()
        Dim windowFrame As IVsWindowFrame = Nothing

        ' This function is called when the package is auto-loaded (as result of our command UI context 
        ' guidSccProvider being set active). This can happen on startup, if this scc provider was active 
        ' last time the shell was started.
        ' However, at that time we cannot create the toolwindow because the shell is not fully initialized
        ' and the window profile is not yet loaded. We need to protect
        Try
            Dim window As MsVsShell.ToolWindowPane = Me.FindToolWindow(GetType(SccProviderToolWindow), 0, True)
            If window IsNot Nothing AndAlso window.Frame IsNot Nothing Then
                windowFrame = CType(window.Frame, IVsWindowFrame)
            End If
        Catch ex As COMException
            If ex.ErrorCode <> VSConstants.E_UNEXPECTED Then
                Throw
            End If
        End Try

        If windowFrame Is Nothing Then
            Throw New InvalidOperationException("No valid window frame object was returned from Toolwindow pane")
        End If

        If sccService.Active Then
            ErrorHandler.ThrowOnFailure(windowFrame.Show())
        Else
            ErrorHandler.ThrowOnFailure(windowFrame.Hide())
        End If
    End Sub
End Class
