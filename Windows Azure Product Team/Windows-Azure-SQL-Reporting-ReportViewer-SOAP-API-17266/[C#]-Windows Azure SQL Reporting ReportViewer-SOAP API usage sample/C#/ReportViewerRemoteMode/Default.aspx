﻿<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Default.aspx.cs" Inherits="ReportViewerRemoteMode.Default" %>

<%@ Register assembly="Microsoft.ReportViewer.WebForms, Version=10.0.0.0, Culture=neutral, PublicKeyToken=b03f5f7f11d50a3a" namespace="Microsoft.Reporting.WebForms" tagprefix="rsweb" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
    <title>ReportViewer Remote Mode</title>
</head>
<body>
    <form id="form1" runat="server">
    Report Viewer running in Windows Azure against Windows Azure SQL Reporting
    <asp:ScriptManager ID="ScriptManager1" runat="server">
    </asp:ScriptManager>
&nbsp;<div>
        <rsweb:ReportViewer ID="ReportViewer1" runat="server" Font-Names="Verdana" 
            Font-Size="8pt" InteractiveDeviceInfos="(Collection)" Width = "100%" Height = "600px" 
            WaitMessageFont-Names="Verdana" WaitMessageFont-Size="14pt" 
            ProcessingMode="Remote">
        </rsweb:ReportViewer>
    </div>
    </form>
</body>
</html>
