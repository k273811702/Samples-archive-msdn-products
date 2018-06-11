# Exchange 2013: Delete folders programmatically from Exchange servers
## Requires
* Visual Studio 2010
## License
* Custom
## Technologies
* Exchange Online
* Microsoft Exchange Server 2010
* Microsoft Exchange Server 2013
* EWS Managed API
## Topics
* folders
## IsPublished
* True
## ModifiedDate
* 2013-07-22 04:42:00
## Description

<p><span style="font-size:small">This sample authenticates an email address and password entered from the console and permanently deletes a folder from the authenticated user's Inbox folder on the Exchange server. The sample retrieves the unique identifier
 of the folder to be deleted by using the folder's display name, binds to the folder by using its identifier, and deletes the folder.</span></p>
<h1>Prerequisites</h1>
<p><span style="font-size:small">This sample requires the following:</span></p>
<ul>
<li><span style="font-size:small">A target server that is running a version of Exchange starting with Exchange Server 2007 Service Pack 1 (SP1), including Exchange Online as part of Office&nbsp;365.</span>
</li><li><span style="font-size:small">The .NET Framework 4.</span> </li><li><span style="font-size:small">The EWS Managed API assembly file, Microsoft.Exchange.WebServices.dll. You can download the assembly from the
<a href="http://go.microsoft.com/fwlink/?LinkID=255472">Microsoft Download Center</a>.</span>
</li></ul>
<p><span style="font-size:small">Note: </span><span style="font-size:small">The sample assumes that the assembly is in the default download directory. You will need to verify the path before you run the solution.</span></p>
<ul>
<li><span style="font-size:small">Visual Studio 2010 with the Visual Web Developer and C# components and an open Visual Studio 2010 solution.</span><br>
<span style="font-size:small">Or</span> </li><li><span style="font-size:small">A text editor to create and edit source code files and a command prompt window to run a .NET Framework command line compiler.</span>
</li></ul>
<h1>Key components of the sample</h1>
<p><span style="font-size:small">This sample contains the following files:</span></p>
<ul>
<li><span style="font-size:small">Ex15_DeleteFolder_CS.sln &mdash; The Visual Studio 2010 solution file for the Ex15_DeleteFolder_CS project.</span>
</li><li><span style="font-size:small">Ex15_DeleteFolder_CS.csproj &mdash; The Visual Studio 2010 project file for the
<strong>DeleteFolder </strong>function.</span> </li><li><span style="font-size:small">Ex15_DeleteFolder_CS.cs &mdash; Contains the using statements, namespace, class, and functions to delete a folder.</span>
</li><li><span style="font-size:small">app.config &mdash; Contains configuration data for the Ex15_DeleteFolder_CS project.</span>
</li><li><span style="font-size:small">Ex15_FindFolderIdByDisplayName_CS.csproj &mdash; The Visual Studio 2010 project file for the
<strong>FindFolderIdByDisplayName </strong>function.</span> </li><li><span style="font-size:small">Ex15_FindFolderIdByDisplayName_CS.cs &mdash; Contains the using statements, namespace, class, and functions to find the unique identifier of a folder by using the folder's display name.</span>
</li><li><span style="font-size:small">app.config &mdash; Contains configuration data for the Ex15_FindFolderIdByDisplayName_CS project.</span>
</li><li><span style="font-size:small">Authentication.csproj &mdash; The Visual Studio 2010 project file for the dependent authentication code.</span>
</li><li><span style="font-size:small">TextFileTraceListener.cs &mdash; Contains the using statements, namespace, class, and code to write the XML request and response to a text file.</span>
</li><li><span style="font-size:small">Service.cs &mdash; Contains the using statements, namespace, class, and functions necessary to acquire an ExchangeService object used in the Ex15_DeleteFolder_CS project.</span>
</li><li><span style="font-size:small">CertificateCallback.cs &mdash; Contains the using statements, namespace, class, and code to acquire an X509 certificate.</span>
</li><li><span style="font-size:small">UserData.cs &mdash; Contains the using statements, namespace, class, and functions necessary to acquire user information required by the service object.</span>
</li></ul>
<h1>Configure the sample</h1>
<p><span style="font-size:small">Follow these steps to configure the Exchange 2013: Delete folders programmatically from Exchange servers sample.</span></p>
<ol>
<li><span style="font-size:small">Set the startup project to Ex15_DeleteFolder_CS by selecting the project in the Solution Explorer and choosing &quot;Set as StartUp Project&quot; from the Project menu.</span>
</li><li><span style="font-size:small">Ensure that the reference path for the Microsoft.Exchange.WebServices.dll points to where the DLL is installed on your local computer.</span>
</li></ol>
<h1>Build the sample</h1>
<ul>
<li><span style="font-size:small">Press F5 to build and deploy the sample.</span>
</li><li><span style="font-size:small">Run and test the sample</span> </li><li><span style="font-size:small">Press F5 to run the sample.</span> </li></ul>
<h1>Related content</h1>
<ul>
<li><span style="font-size:small"><a href="http://msdn.microsoft.com/en-us/library/jj220499(EXCHG.80).aspx">Get started with the EWS Managed API</a></span>
</li></ul>
<h1>Change log</h1>
<p><span style="font-size:small">First release.</span></p>
