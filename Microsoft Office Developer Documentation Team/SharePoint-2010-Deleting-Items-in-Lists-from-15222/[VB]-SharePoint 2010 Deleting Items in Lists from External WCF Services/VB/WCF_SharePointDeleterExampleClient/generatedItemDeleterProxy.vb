﻿'------------------------------------------------------------------------------
' <auto-generated>
'     This code was generated by a tool.
'     Runtime Version:4.0.30319.1
'
'     Changes to this file may cause incorrect behavior and will be lost if
'     the code is regenerated.
' </auto-generated>
'------------------------------------------------------------------------------

Option Strict Off
Option Explicit On



<System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0"),  _
 System.ServiceModel.ServiceContractAttribute([Namespace]:="http://WCF_SharePointCallingService", ConfigurationName:="ISharePointItemDeleter")>  _
Public Interface ISharePointItemDeleter
    
    <System.ServiceModel.OperationContractAttribute(Action:="http://WCF_SharePointCallingService/ISharePointItemDeleter/DeleteItem", ReplyAction:="http://WCF_SharePointCallingService/ISharePointItemDeleter/DeleteItemResponse")>  _
    Function DeleteItem(ByVal Title As String) As Boolean
End Interface

<System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")>  _
Public Interface ISharePointItemDeleterChannel
    Inherits ISharePointItemDeleter, System.ServiceModel.IClientChannel
End Interface

<System.Diagnostics.DebuggerStepThroughAttribute(),  _
 System.CodeDom.Compiler.GeneratedCodeAttribute("System.ServiceModel", "4.0.0.0")>  _
Partial Public Class SharePointItemDeleterClient
    Inherits System.ServiceModel.ClientBase(Of ISharePointItemDeleter)
    Implements ISharePointItemDeleter
    
    Public Sub New()
        MyBase.New
    End Sub
    
    Public Sub New(ByVal endpointConfigurationName As String)
        MyBase.New(endpointConfigurationName)
    End Sub
    
    Public Sub New(ByVal endpointConfigurationName As String, ByVal remoteAddress As String)
        MyBase.New(endpointConfigurationName, remoteAddress)
    End Sub
    
    Public Sub New(ByVal endpointConfigurationName As String, ByVal remoteAddress As System.ServiceModel.EndpointAddress)
        MyBase.New(endpointConfigurationName, remoteAddress)
    End Sub
    
    Public Sub New(ByVal binding As System.ServiceModel.Channels.Binding, ByVal remoteAddress As System.ServiceModel.EndpointAddress)
        MyBase.New(binding, remoteAddress)
    End Sub
    
    Public Function DeleteItem(ByVal Title As String) As Boolean Implements ISharePointItemDeleter.DeleteItem
        Return MyBase.Channel.DeleteItem(Title)
    End Function
End Class
