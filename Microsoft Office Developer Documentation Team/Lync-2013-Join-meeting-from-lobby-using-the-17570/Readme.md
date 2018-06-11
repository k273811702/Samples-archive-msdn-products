# Lync 2013: Join meeting from lobby using the Automation class
## Requires
* Visual Studio 2010
## License
* Apache License, Version 2.0
## Technologies
* Microsoft Lync 2013
## Topics
* Automation
* meeting
## IsPublished
* True
## ModifiedDate
* 2012-07-15 06:38:09
## Description

<p><span style="font-size:small">This Lync SDK sample application passes a conference URI entered in a textbox in the form &quot;conf:sip:wewa@microsoft.com;gruu;opaque=app:conf:focus:id:4FNRHN16 to the
<strong>BeginStartConversation</strong> method. The <strong>BeginStartConversation</strong> method uses the conference URI to join a meeting. If the participant successfully joins the meeting, their status is set to 'in lobby'.</span></p>
<p><span style="font-size:small">This sample application also makes use of the following namespaces, classes, and events:</span></p>
<ul>
<li><span style="font-size:small"><strong>ConversationWindow </strong>class</span>
</li><li><span style="font-size:small"><strong>Participant </strong>class</span> </li><li><span style="font-size:small"><strong>ContactManager </strong>class</span> </li><li><span style="font-size:small"><strong>ParticipantProperty </strong>class</span>
</li><li><span style="font-size:small"><strong>Microsoft.Lync.Model.Extensibility </strong>
namespace</span> </li></ul>
<h1>Prerequisites</h1>
<ul>
<li><span style="font-size:small">.NET Framework 4.0 and later versions of .NET Framework 4.0.</span>
</li><li><span style="font-size:small">Microsoft Visual Studio 2010 development system and later versions of Visual Studio 2010.</span>
</li><li><span style="font-size:small">Microsoft Lync 2010 SDK and later versions of Lync SDK.</span>
</li><li><span style="font-size:small">Microsoft Lync 2010 client and later versions of the Lync client.</span>
</li></ul>
<h1>Build the sample</h1>
<ol>
<li><span style="font-size:small">Open JoinMeetingFromLobby.csproj</span> </li><li><span style="font-size:small">In Visual Studio, press F5.</span> </li></ol>
<p><span style="font-size:small">The Lync SDK includes three development models:</span></p>
<ul>
<li><span style="font-size:small">Lync Controls</span> </li><li><span style="font-size:small">Lync API</span> </li><li><span style="font-size:small">OCOM Unmanaged COM API</span> </li></ul>
<p><span style="font-size:small">You can drag and drop Microsoft Lync Controls into existing business applications to add Lync functions and user interface. Each Lync Control provides a specific feature like search, presence, instant messaging (IM) calls, and
 audio calls. The appearance of each control replicates the Lync UI for that feature. Use a single control or multiple controls. The programming style is primarily XAML text, but you can also use C# in the code-behind file to access the Lync API and .NET Framework.</span></p>
<p><span style="font-size:small">Use the Lync API to start and automate the Lync UI in your business application, or add Lync functionality to new or existing .NET Framework applications and suppress the Lync UI. Lync SDK UI Automation automates the Lync UI,
 and Lync Controls add separate pieces of Lync functionality and UI as XAML controls.</span></p>
<p><span style="font-size:small">Use the Lync 2010 API Reference to learn about the unmanaged Office Communicator Object Model API (OCOM). The OCOM API contains a subset of the types that are in the Lync API. You cannot start or carry on conversations with
 OCOM, but you can access a contact list and get contact presence. </span></p>
<p><span style="font-size:small">It is not recommended that you use this API, but if you are a C&#43;&#43; developer and you need to add contact and presence features to your application, then this API can work for you.</span></p>
<h1>Related content&nbsp;</h1>
<ul>
<li><span style="font-size:small">Lync 2010 SDK download: <a href="http://www.microsoft.com/en-us/download/details.aspx?id=18898">
http://www.microsoft.com/en-us/download/details.aspx?id=18898</a></span> </li><li><span style="font-size:small">Lync 2010 API Reference: <a href="http://gallery.technet.microsoft.com/Lync-2010-API-Reference-48d2c5c9">
http://gallery.technet.microsoft.com/Lync-2010-API-Reference-48d2c5c9</a></span> </li><li><span style="font-size:small">Office 365 Developer Hub: <a href="http://msdn.microsoft.com/en-us/office/hh506337.aspx">
http://msdn.microsoft.com/en-us/office/hh506337.aspx</a></span> </li><li><span style="font-size:small">Lync Developer Center: <a href="http://msdn.microsoft.com/en-us/lync/gg132942.aspx">
http://msdn.microsoft.com/en-us/lync/gg132942.aspx</a></span> </li><li><span style="font-size:small">Office Developer Center: <a href="http://msdn.microsoft.com/en-us/office/aa905340.aspx">
http://msdn.microsoft.com/en-us/office/aa905340.aspx</a></span> </li></ul>
