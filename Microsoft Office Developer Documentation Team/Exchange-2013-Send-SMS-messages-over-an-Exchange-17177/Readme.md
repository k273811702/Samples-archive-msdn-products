# Exchange 2013: Send SMS messages over an Exchange server and an SMS gateway
## Requires
* Visual Studio 2010
## License
* Apache License, Version 2.0
## Technologies
* Exchange Server 2007
* Exchange Server 2010
* Exchange Online
* EWS Managed API
* Exchange Server 2013
## Topics
* SMS
## IsPublished
* True
## ModifiedDate
* 2013-06-06 02:16:16
## Description

<div id="header">
<table id="bottomTable" cellpadding="0" cellspacing="0">
<tbody>
<tr id="headerTableRow1">
<td align="left"><span id="runningHeaderText"></span></td>
</tr>
<tr id="headerTableRow2">
<td align="left"><span id="nsrTitle">Exchange 2013: Send SMS messages by using an Exchange server and an SMS gateway</span>
</td>
</tr>
</tbody>
</table>
</div>
<div id="mainSection">
<div id="mainBody">
<p></p>
<div>
<p>This sample shows you how to use the Exchange Web Services (EWS) Managed API to send an SMS message by using an Exchange server and an SMS gateway.</p>
</div>
<h1>Description of the Exchange 2013: Send SMS messages by using an Exchange server and an SMS gateway sample</h1>
<div id="sectionSection0" name="collapseableSection">
<p>This sample authenticates an email address and password entered from the console, and then creates and sends an SMS message.</p>
</div>
<h1>Prerequisites</h1>
<div id="sectionSection1" name="collapseableSection">
<p>This sample requires the following:</p>
<ul>
<li>
<p>A target server that is running a version of Exchange starting with Exchange Server 2007 Service Pack 1 (SP1), including Exchange Online as part of Office 365..</p>
</li><li>
<p>The .NET Framework 4.</p>
</li><li>
<p>The EWS Managed API assembly file, Microsoft.Exchange.WebServices.dll. You can download the assembly from the
<a href="http://go.microsoft.com/fwlink/?LinkID=255472" target="_blank">Microsoft Download Center</a>.</p>
<div>
<table width="100%" cellspacing="0" cellpadding="0">
<tbody>
<tr>
<th align="left"><b>Note</b> </th>
</tr>
<tr>
<td>
<p>The sample assumes that the assembly is in the default download directory. You will need to verify the path before you run the solution.</p>
</td>
</tr>
</tbody>
</table>
</div>
</li><li>
<p>Visual Studio 2010 with the Visual Web Developer and C# components and an open Visual Studio 2010 solution.</p>
<p>Or</p>
</li><li>
<p>A text editor to create and edit source code files and a command prompt window to run a .NET Framework command line compiler.</p>
</li></ul>
</div>
<h1>Key components of the sample</h1>
<div id="sectionSection2" name="collapseableSection">
<p>This sample contains the following files:</p>
<ul>
<li>
<p>Ex15_SendSMS_CS.sln — The Visual Studio 2010 solution file for the Ex15_SendSMS_CS project.</p>
</li><li>
<p>Ex15_SendSMS_CS.csproj — The Visual Studio 2010 project file for the <b>SendSMS</b> function.</p>
</li><li>
<p>app.config — Contains configuration data for the Ex15_SendSMS_CS project.</p>
</li><li>
<p>Ex15_SendSMS_CS.cs — Contains the using statements, namespace, class, and functions to send an SMS message from Exchange.</p>
</li><li>
<p>Authentication.csproj — The Visual Studio 2010 project file for the dependent authentication code.</p>
</li><li>
<p>TextFileTraceListener.cs — Contains the using statements, namespace, class, and code to write the XML request and response to a text file.</p>
</li><li>
<p>Service.cs — Contains the using statements, namespace, class, and functions necessary to acquire an
<b>ExchangeService</b> object used in the Ex15_SendSMS_CS project.</p>
</li><li>
<p>CertificateCallback.cs — Contains the using statements, namespace, class, and code to acquire an X509 certificate.</p>
</li><li>
<p>UserData.cs — Contains the using statements, namespace, class, and functions necessary to acquire user information required by the service object.</p>
</li></ul>
</div>
<h1>Configure the sample</h1>
<div id="sectionSection3" name="collapseableSection">
<p>Follow these steps to configure the Exchange 2013: Send SMS messages bv using an Exchange server and an SMS gateway sample.</p>
<ol>
<li>
<p>Set the startup project to Ex15_SendSMS_CS.csproj by selecting the project in the Solution Explorer and choosing &quot;Set as StartUp Project&quot; from the
<b><span class="ui">Project</span></b> menu.</p>
</li><li>
<p>On line 27 in Ex15_SendSMS_CS.cs, update the SMS gateway format to match the SMS gateway format of your mobile carrier. For a partial list of international mobile carrier SMS gateway formats, see
<a href="http://en.wikipedia.org/wiki/List_of_SMS_gateways" target="_blank">List of SMS gateways</a>.</p>
</li><li>
<p>On line 28 in Ex15_SendSMS_CS.cs, update the phone number to match your target phone number that uses the SMS gateway from line 27. Note that different carriers have different phone number format requirements.</p>
</li><li>
<p>Ensure that the reference path for the Microsoft.Exchange.WebServices.dll points to where the DLL is installed on your local computer.</p>
</li></ol>
<p></p>
</div>
<h1>Build the sample</h1>
<div id="sectionSection4" name="collapseableSection">
<p>Press F6 to build and deploy the sample.</p>
</div>
<h1>Run and test the sample</h1>
<div id="sectionSection5" name="collapseableSection">
<p>Press F5 to run the sample.</p>
</div>
<h1>Related content</h1>
<div id="sectionSection6" name="collapseableSection">
<ul>
<li>
<p><a href="http://go.microsoft.com/fwlink/?LinkId=301827" target="_blank">Get started with the EWS Managed API</a>
</p>
</li></ul>
</div>
<h1>Change log</h1>
<div id="sectionSection7" name="collapseableSection">
<p>First release.</p>
</div>
</div>
</div>
