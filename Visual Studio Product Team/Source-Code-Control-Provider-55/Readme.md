# Source Code Control Provider
## Requires
* Visual Studio 2010
## License
* Apache License, Version 2.0
## Technologies
* Visual Studio 2010 SDK
## Topics
* MSBuild
* Visual Studio 2010 Project System
* Visual Studio 2010 MSDBuild
* VSX
## IsPublished
* True
## ModifiedDate
* 2011-03-03 12:30:07
## Description

<h2>Introduction</h2>
<p>This sample demonstrates how to create a source code control provider.</p>
<ul>
<li>Implement a source control provider package </li><li>Expose an Options page visible only when the provider is active </li><li>Expose a tool window visible only when the provider is active </li><li>Display menu items only when the provider is active </li><li>Expose a toolbar for source control commands. It cannot be hidden when the provider is not active, but the buttons should be disabled
</li><li>Add source control commands to shortcut menus in Solution Explorer </li><li>Enable persisting and reading solution properties </li><li>Enable persisting and reading user options in the .suo file </li><li>Implement basic QueryEditQuerySave service functionality </li><li>Demonstrate how to implement IVsTrackProjectDocumentsEvents2 functions </li><li>Provide basic source control functionality, such as add to source control, check in, check out, and work offline
</li></ul>
<p>&nbsp;</p>
<h2><strong>Quick Navigation</strong></h2>
<table>
<tbody>
<tr>
<td><span style="font-size:small">1 <a href="http://code.msdn.microsoft.com/SCCProvider#Req">
Requirements</a></span></td>
</tr>
<tr>
<td><span style="font-size:small">2 <a href="http://code.msdn.microsoft.com/SCCProvider#downloadAndInstall">
Download and Install</a></span></td>
</tr>
<tr>
<td><span style="font-size:small">3 <a href="http://code.msdn.microsoft.com/SCCProvider#BuildAndRun">
Building and Running</a></span></td>
</tr>
<tr>
<td><span style="font-size:small">4 <a href="http://code.msdn.microsoft.com/SCCProvider#GettingStarted">
Getting Started</a></span></td>
</tr>
<tr>
<td><span style="font-size:small">4.1 <a href="http://code.msdn.microsoft.com/SCCProvider#ProjFiles">
Project Files</a></span></td>
</tr>
<tr>
<td><span style="font-size:small">4.2 <a href="http://code.msdn.microsoft.com/SCCProvider#UnitTests">
Unit Tests</a></span></td>
</tr>
<tr>
<td><span style="font-size:small">4.3 <a href="http://code.msdn.microsoft.com/SCCProvider#FuncTests">
Functional Tests</a></span></td>
</tr>
<tr>
<td><span style="font-size:small">4.4 <a href="http://code.msdn.microsoft.com/SCCProvider#Status">
Status</a></span></td>
</tr>
<tr>
<td><span style="font-size:small">4.5 <a href="http://code.msdn.microsoft.com/SCCProvider#History">
History</a></span></td>
</tr>
<tr>
<td><span style="font-size:small">4.6 <a href="http://code.msdn.microsoft.com/SCCProvider#AddResx">
Additional Resources</a></span></td>
</tr>
</tbody>
</table>
<p><span id="ctl00_ctl00_Content_TabContentPanel_Content_wikiSourceLabel"><br>
</span></p>
<h2>Requirements</h2>
<p><a class="externalLink" href="http://msdn.com/vstudio">Visual Studio 2010 and Visual Studio 2010 SDK</a><br>
<br>
</p>
<h2>Download and Install</h2>
<ul>
<li>Go to the &quot;Downloads tab&quot; and download the zip file associated with this sample
</li><li>Unzip the sample to your machine </li><li>Double click on the .sln file to launch the solution </li></ul>
<p>&nbsp;</p>
<h2>Building and Running</h2>
<p>To build and execute the sample, press F5 after the sample is loaded. This will launch the experimental hive which will demonstrate the sample's function.<br>
<br>
</p>
<h2>Getting Started</h2>
<p>This sample has a package (SccProvider) and the source control service (SccProviderService). The sample exposes one tool window (SccProviderToolWindow) and one Options page (SccProviderOptions).<br>
<br>
The source control provider can be selected in the Tools, Options, Source Control, Plug-In Selection page as &quot;Managed Source Control Sample Provider&quot;. Selection will make it the active source control provider.<br>
<br>
When the provider is selected as the active source control provider, the &quot;Source control provider toolwindow&quot; command will become visible on the View menu, the Tools, Options, Source Control, Sample Options Page page will become visible, the shortcut menus
 in Solution Explorer will become visible (with the AddToSourceControl, Checkin, Checkout, Offline commands) if you have a solution created, and the source control toolbar buttons will appear if you access View, Toolbars, Sample Source Control Toolbar. When
 the &quot;View/Source control provider toolwindow&quot; command is clicked, the tool window will be created. The visibility of menu commands, tool window, and Options page is controlled by the active state of the provider. All of the UI elements except the toolbar will
 be hidden automatically when the provider is deactivated.<br>
<br>
The provider demonstrates basic source control functionality:</p>
<ol>
<li>The sample does not implement a real source control store. To track which files in a project are controlled, the sample will create a
<a href="http://code.msdn.microsoft.com/SCCProvider/Wiki/View.aspx?title=projectname&referringTitle=Home">
projectname</a>.storage text file on the hard drive that contains the list of controlled files in that project. To simplify things, if a project is added to the solution after the solution was added to source control, that project will not be automatically
 controlled. The user must explicitly use the AddToSourceControl command to add it to source control. (Exceptions are solution folders, which are controlled automatically after closing and reopening the solution.
</li><li>Controlled solutions may be opened from disk. </li><li>Controlled files can be checked out and checked in, but these actions only toggle the read-write attribute of the files. Source control status of files will be inferred from the file attributes on local disk.
</li></ol>
<p><br>
The SccProvider class derives from the IVsPersistSolutionProps interface to persist properties in the solution file. The following property names are used: SolutionIsControlled, which indicates the controlled status of the solution, and SolutionBindings, which
 shows the solution location in the source control database.<br>
<br>
The SccProvider class derives from IVsPersistSolutionProps interface to persist user options in the .suo file. The &quot;Use Scc Offline&quot; command will be visible in shortcut menus in Solution Explorer and will act like a toggle that allows projects to be taken online
 or offline. The offline status for the projects is persisted in the .suo file through the SampleSourceControlProvider options key. The status of other source control commands is not affected by the offline status of a project.<br>
<br>
The sample implements basic QueryEditQuerySave service functionality in the SccProviderService class. OnEdit will prompt the user to check out the file, edit in memory, or cancel the edit. OnSave will prompt the user to check out the file, skip the save, or
 cancel the operation. The OnSave code will trigger only if files have been edited in memory or if the user forces the file to be saved when it is checked in.<br>
<br>
SccProviderService implements the IVsTrackProjectDocumentsEvents2 interface to intercept project-change events in the integrated development environment (IDE). The following functions are implemented:<br>
OnAfterRenameFiles to rename files in source control when they are renamed in projects and OnQueryRemoveFiles to warn the user when they are deleting files under source control.<br>
<br>
</p>
<h2>Project Files</h2>
<table border="1" style="font-size:12px; border:1px solid black">
<tbody>
<tr>
<th>File Name </th>
<th>Description </th>
</tr>
<tr>
<td><strong>SccProvider</strong></td>
<td>This file contains the Package implementation. It also is responsible for handling the enabling and execution of source control commands.</td>
</tr>
<tr>
<td><strong>SccProviderService</strong></td>
<td>This file contains the source control service implementation. The class implements the the IVsSccProvider interface that enables source control provider activation and switching.</td>
</tr>
<tr>
<td><strong>SccProviderStorage</strong></td>
<td>This file contains the implementation of a pseudo-source control storage. The class creates a *.storage text file for each controlled project in the solution and stores in it the list of the controlled files. The checked in and checked out status of controlled
 files is inferred from the their attributes on disk..</td>
</tr>
<tr>
<td><strong>SccProviderOptions</strong></td>
<td>This class derives from MsVsShell.DialogPage and provides the Options page. It is responsible for handling Option page events such as activation, apply, and close. It hosts the SccProviderOptionsControl.</td>
</tr>
<tr>
<td><strong>SccProviderOptionsControl</strong></td>
<td>This class is a UserControl that will be hosted in the Options page. It has a label to demonstrate display of controls on the page.</td>
</tr>
<tr>
<td><strong>SccProviderToolWindow</strong></td>
<td>This class derives from ToolWindowPane, which provides the IVsWindowPane implementation. It is responsible for defining window frame properties such as caption and bitmap. It hosts the SccProviderToolWindowControl.</td>
</tr>
<tr>
<td><strong>SccProviderToolWindowControl</strong></td>
<td>This class is a UserControl that will be hosted in the tool window. It has a label to demonstrate display of controls in the window.</td>
</tr>
<tr>
<td><strong>DataStreamFromComStream</strong></td>
<td>This class implements a Stream object that wraps an IStream COM object. It is used to facilitate the read/write of solution user options from an IStream by using a BinaryFormatter object that can serialize data to and from Stream objects</td>
</tr>
<tr>
<td><strong>DlgQueryEditCheckedInFile</strong></td>
<td>This class is a Form that will be displayed when a checked in file is edited. The user can choose to check out the file, continue editing the file in memory, or cancel the edit</td>
</tr>
<tr>
<td><strong>DlgQuerySaveCheckedInFile</strong></td>
<td>This class is a Form that will be displayed when a checked in file is saved. The user can choose to checkout the file, discard the in-memory changes and skip saving it, save the file with a different name, or cancel the operation.</td>
</tr>
<tr>
<td><strong>CommandId</strong></td>
<td>This is a list of GUIDs specific to this sample, especially the package GUID and the commands group GUID. It also includes GUIDs of other elements used by the sample.</td>
</tr>
<tr>
<td><strong>Guids</strong></td>
<td>This is the list of command IDs that the sample defines.</td>
</tr>
<tr>
<td><strong>PkgCmd.vsct</strong></td>
<td>This file describes the menu structure and commands for this sample. It also is where the toolbar is defined.</td>
</tr>
<tr>
<td><strong>Resources (.cs/.resx/.Designer.cs)</strong></td>
<td>These files are used to support localized strings.</td>
</tr>
<tr>
<td><strong>Resources\Images_24bit.bmp</strong></td>
<td>This bitmap defines the icons that are used for tool windows.</td>
</tr>
<tr>
<td><strong>Resources\Images_32bit.bmp</strong></td>
<td>This bitmap defines the icons that are used for toolbars and menu commands.</td>
</tr>
<tr>
<td><strong>Resources\Product.ico</strong></td>
<td>This file defines the icon to be used for the product.</td>
</tr>
<tr>
<td><strong>ProvideSourceControlProvider</strong></td>
<td>This file contains the implementation of a custom registration attribute that registers a source control provider. It is used to make the source control provider visible on the Tools, Options, SourceControl, Plugins page.</td>
</tr>
<tr>
<td><strong>ProvideToolsOptionsPageVisibility</strong></td>
<td>This file contains the implementation of a custom registration attribute that defines the visibility of a tool window. It is used to make the tool window implemented by the provider visible only when the provider is active (that is, when the provider context
 UI has been asserted).</td>
</tr>
<tr>
<td><strong>ProvideSolutionProps</strong></td>
<td>This file contains the implementation of a custom registration attribute that declares the key used by the package to persist solution properties. When encountering a solution containing this key, the IDE will know which package it has to call to read that
 block of solution properties.</td>
</tr>
</tbody>
</table>
<p><span id="ctl00_ctl00_Content_TabContentPanel_Content_wikiSourceLabel"><br>
</span></p>
<h2>Unit Tests</h2>
<table border="1" style="font-size:12px; border:1px solid black">
<tbody>
<tr>
<th>Description </th>
</tr>
<tr>
<td>Verify that the package can be created and sited and that it implements IVsPackage</td>
</tr>
<tr>
<td>Verify that the source control provider service can be ceated, activated, and deactivated</td>
</tr>
<tr>
<td>Test the &quot;Scc Command&quot; command on the Tools menu by toggling it twice</td>
</tr>
<tr>
<td>Test the Activate, Deactivate, Apply, and Close events on the Options page</td>
</tr>
<tr>
<td>Test that the tool window can be displayed and that the toolbar command can be executed</td>
</tr>
<tr>
<td>Test that source control storage can be created, and read and write storage files. Test that files can be added to the storage, checked out, checked in, and renamed. Test that correct source control status is returned for files in storage</td>
</tr>
</tbody>
</table>
<p><span id="ctl00_ctl00_Content_TabContentPanel_Content_wikiSourceLabel"><br>
</span></p>
<h2>Functional Tests</h2>
<table border="1" style="font-size:12px; border:1px solid black">
<tbody>
<tr>
<th>Description </th>
</tr>
<tr>
<td>Verify sample builds in all configurations.</td>
</tr>
<tr>
<td>Verify that the sample was registered. The About box should list the product as installed.</td>
</tr>
<tr>
<td>Verify that the provider is can be selected in Tools, Options, SourceControl.</td>
</tr>
<tr>
<td>Verify that menu commands are visible when the provider is active.</td>
</tr>
<tr>
<td>Verify that the toolbar can be displayed.</td>
</tr>
<tr>
<td>Verify that toolbar buttons are enabled only when the provider is active.</td>
</tr>
<tr>
<td>Verify that the tool window is visible only when the provider is active, after it was displayed once.</td>
</tr>
<tr>
<td>Verify that the Options page is visible only when the provider is active.</td>
</tr>
<tr>
<td>Verify that a solution can be added to source control entirely by using the AddToSourceControl command on a newly created solution when the solution node is selected in Solution Explorer. Everything should be checked in.</td>
</tr>
<tr>
<td>Verify that a project can be added to source control separately from a solution by using AddToSourceControl command on a newly created solution when the project node is selected in Solution Explorer. Only project files should be checked in.</td>
</tr>
<tr>
<td>Verify that checked in files in a controlled solution can be checked out.</td>
</tr>
<tr>
<td>Verify that checked out files in a controlled solution can be checked in.</td>
</tr>
<tr>
<td>Verify that solution items are added to source control when a solution is added to source control.</td>
</tr>
<tr>
<td>Verify that adding a new project to a controlled solution prompts QueryEdit to check out the solution file and open it for editing.</td>
</tr>
<tr>
<td>Verify that adding a new project to a controlled solution does not make the project controlled.</td>
</tr>
<tr>
<td>Verify that adding a new solution item to a controlled solution makes the new file a pending addition. Pending additions display a checkout glyph in Solution Explorer, but have a different tooltip.</td>
</tr>
<tr>
<td>Verify that adding a new item to a controlled project prompts QueryEdit to check out the project file and open it for editing.</td>
</tr>
<tr>
<td>Verify that adding a new item to a controlled project makes the new file a pending addition. Pending additions display a checkout glyph in Solution Explorer, but have a different tooltip.</td>
</tr>
<tr>
<td>Verify that pending addition files can be checked in.</td>
</tr>
<tr>
<td>Verify that closing and reopening from disk a controlled solution preserves the controlled status for all of the projects controlled in that solution.</td>
</tr>
<tr>
<td>Verify that any controlled project or solution can be taken offline.</td>
</tr>
<tr>
<td>Verify that closing and reopening from disk a controlled solution in which some projects were taking offline preserves the offline status.</td>
</tr>
<tr>
<td>Verify that the user is warned when attempting to delete a controlled item from a controlled project.</td>
</tr>
<tr>
<td>Verify that renaming a controlled item in a controlled project renames the item in the store and keeps the renamed file controlled.</td>
</tr>
<tr>
<td>Verify that renaming a controlled project in a solution renames the project in the store and in the storage file, and that the project files remain controlled.</td>
</tr>
<tr>
<td>Verify source control glyphs in Solution Explorer for controlled files (checked in and checked out), pending addition files (uncontrolled files in controlled projects), and uncontrolled files.</td>
</tr>
<tr>
<td>Verify source tooltips in Solution Explorer for controlled files (checked in and checked out), pending addition files (uncontrolled files in controlled projects), and uncontrolled files.</td>
</tr>
</tbody>
</table>
<p><span id="ctl00_ctl00_Content_TabContentPanel_Content_wikiSourceLabel"><br>
</span></p>
<h2>Status</h2>
<table border="1" style="font-size:12px; border:1px solid black">
<tbody>
<tr>
<th>Function </th>
<th>Status </th>
</tr>
<tr>
<td>Demonstrates Accessibility</td>
<td>Yes</td>
</tr>
<tr>
<td>Includes Architecture Diagram</td>
<td>Yes</td>
</tr>
<tr>
<td>Demonstrates Error Handling</td>
<td>Yes</td>
</tr>
<tr>
<td>Follows SDK Coding Standards</td>
<td>No</td>
</tr>
<tr>
<td>Demonstrates Localization</td>
<td>Yes</td>
</tr>
<tr>
<td>Implements Functional Tests</td>
<td>No</td>
</tr>
<tr>
<td>Samples supported by Microsoft</td>
<td>Yes</td>
</tr>
<tr>
<td>Implements Unit Tests</td>
<td>Yes</td>
</tr>
</tbody>
</table>
<p><span id="ctl00_ctl00_Content_TabContentPanel_Content_wikiSourceLabel"><br>
</span></p>
<h2>History</h2>
<table border="1" style="font-size:12px; border:1px solid black">
<tbody>
<tr>
<th>Date </th>
<th>Activity </th>
</tr>
<tr>
<td>2005-10-01</td>
<td>Created this sample for the Visual Studio 2005 SDK</td>
</tr>
<tr>
<td>2010-03-05</td>
<td>Ported this sample to work in Visual Studio 2010</td>
</tr>
</tbody>
</table>
<p><span id="ctl00_ctl00_Content_TabContentPanel_Content_wikiSourceLabel"><br>
</span></p>
<h4>Additional Resources</h4>
<p><a class="externalLink" href="http://msdn.microsoft.com/en-us/library/bb166434%28VS.100%29.aspx">SCC Provider Integration</a></p>