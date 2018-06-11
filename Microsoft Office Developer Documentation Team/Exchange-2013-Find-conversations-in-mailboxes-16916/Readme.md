# Exchange 2013: Find conversations in mailboxes programmatically
## Requires
* Visual Studio 2010
## License
* Apache License, Version 2.0
## Technologies
* Exchange Server 2010
* Exchange Online
* EWS Managed API
* Exchange Server 2013
## Topics
* Search
* Conversation
## IsPublished
* True
## ModifiedDate
* 2013-06-06 01:02:12
## Description

<div id="header">
<table id="bottomTable" cellpadding="0" cellspacing="0">
<tbody>
<tr id="headerTableRow1">
<td align="left"><span id="runningHeaderText"></span></td>
</tr>
<tr id="headerTableRow2">
<td align="left"><span id="nsrTitle">Exchange 2013: Find conversations in mailboxes programmatically</span>
</td>
</tr>
</tbody>
</table>
</div>
<div id="mainSection">
<div id="mainBody">
<p></p>
<div>
<p>This sample shows you how to use the Exchange Web Services (EWS) Managed API to find email conversations by using a search filter.</p>
</div>
<h1>Description of the Exchange 2013: Find conversations in mailboxes programmatically sample</h1>
<div id="sectionSection0" name="collapseableSection">
<p>This sample authenticates an email address and password entered from the console, and then searches for email conversations in the Inbox. The search is performed with a search filter that finds conversations that have Exchange in the subject and that were
 sent between January 1st, 2013, and April 22nd, 2013.</p>
</div>
<h1>Prerequisites</h1>
<div id="sectionSection1" name="collapseableSection">
<p>This sample requires the following:</p>
<ul>
<li>
<p>A target server that is running a version of Exchange starting with Exchange Server 2010 Service Pack 1 (SP1), including Exchange Online as part of Office 365.</p>
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
<p>Ex15_FindConversation_CS.sln — The Visual Studio 2010 solution file for the Ex15_FindConversation_CS project.</p>
</li><li>
<p>Ex15_FindConversation_CS.csproj — The Visual Studio 2010 project file for the <b>
FindConversation</b> function.</p>
</li><li>
<p>app.config — Contains configuration data for the Ex15_FindConversation_CS project.</p>
</li><li>
<p>Ex15_FindConversation_CS.cs — Contains the using statements, namespace, class, and functions to find email conversations in a user's Inbox folder.</p>
</li><li>
<p>Authentication.csproj — The Visual Studio 2010 project file for the dependent authentication code.</p>
</li><li>
<p>TextFileTraceListener.cs — Contains the using statements, namespace, class, and code to write the XML request and response to a text file.</p>
</li><li>
<p>Service.cs — Contains the using statements, namespace, class, and functions necessary to acquire an
<b>ExchangeService</b> object used in the Ex15_FindConversation_CS project.</p>
</li><li>
<p>CertificateCallback.cs — Contains the using statements, namespace, class, and code to acquire an X509 certificate.</p>
</li><li>
<p>UserData.cs — Contains the using statements, namespace, class, and functions necessary to acquire user information required by the service object.</p>
</li></ul>
</div>
<h1>Configure the sample</h1>
<div id="sectionSection3" name="collapseableSection">
<p>Follow these steps to configure the Exchange 2013: Find conversations in mailboxes programmatically sample.</p>
<ol>
<li>
<p>Set the startup project to Ex15_FindConversation_CS.csproj by selecting the project in the Solution Explorer and choosing &quot;Set as StartUp Project&quot; from the
<b><span class="ui">Project</span></b> menu.</p>
</li><li>
<p>Ensure that the reference path for the Microsoft.Exchange.WebServices.dll points to where the DLL is installed on your local computer.</p>
</li></ol>
<p></p>
</div>
<h1>Build the sample</h1>
<div id="sectionSection4" name="collapseableSection">
<p>Press F6 to build the sample.</p>
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
</li><li>
<p><a href="http://msdn.microsoft.com/en-us/library/ff406144(v=exchg.150).aspx" target="_blank">FindConversation operation</a>
</p>
</li></ul>
</div>
<h1>Change log</h1>
<div id="sectionSection7" name="collapseableSection">
<p>First release.</p>
</div>
</div>
</div>
