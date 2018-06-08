# Windows Azure ServiceManagement Sample
## Requires
* Visual Studio 2010
## License
* Custom
## Technologies
* Microsoft Azure
## Topics
* Hosted Service Management
## IsPublished
* False
## ModifiedDate
* 2011-04-24 11:51:57
## Description

<ol>
</ol>
<p><span style="font-family:arial,helvetica,sans-serif; font-size:x-small"><strong>Before you install and use&nbsp;Window Azure ServiceManagement Sample you must:</strong></span></p>
<ol>
<li><span style="font-family:arial,helvetica,sans-serif; font-size:x-small"><strong>Review the&nbsp;Windows Azure&nbsp;ServiceManagement Sample&nbsp;license terms by clicking&nbsp;the Custom link above.</strong></span>
</li><li><span style="font-family:arial,helvetica,sans-serif; font-size:x-small"><strong>Print and retain a copy of the license terms for your records.</strong></span>
</li></ol>
<div><span style="font-family:arial,helvetica,sans-serif; font-size:x-small"><strong>By downloading and using&nbsp;the&nbsp;Windows Azure&nbsp;ServiceManagement Sample,&nbsp;you agree to such license terms.&nbsp; If you do not accept them, do not use the software.</strong></span></div>
<div><span style="font-family:arial,helvetica,sans-serif; font-size:x-small"><strong>&nbsp;</strong></span></div>
<h1><span style="font-size:large">Introduction</span></h1>
<div><span style="font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%">The Windows Azure ServiceManagement sample is a command-line tool that uses the Service Management API to perform various service management tasks, such as retrieving
 information about a Windows Azure subscription, creating and deploying a hosted service, and updating a deployment.</span></span></div>
<div><span style="font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%">For more information about the Service Management API, see
<span style="line-height:150%"><a href="http://msdn.microsoft.com/en-us/library/ee460807.aspx">About the Service Management API</a>.</span></span></span></span></div>
<h1><span style="font-size:large">Prerequisites</span></h1>
<ul>
<li><span style="font-family:verdana,geneva; font-size:x-small"><span class="LabelEmbedded"><span style="line-height:150%"><strong>Subscription identifier and certificate thumbprint</strong>
<span style="line-height:150%">- You need the subscription identifier and the certificate thumbprint to perform operations on hosted services using the csmanage application.</span></span></span></span>
</li><li><strong><span style="font-size:x-small"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%">Windows Azure SDK
</span></span></span></span></span></span></strong><span class="LabelEmbedded" style="font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%">&ndash;
 provides tools and files that are needed to complete the development process of an application for Windows Azure.</span></span></span></span></span></span>
</li><li><span class="LabelEmbedded" style="font-size:x-small"><strong><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%">Visual
 Studio 2010 </span></span></span></span></span></span></span></strong><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%">&ndash;
 the sample provides a Visual Studio 2010 project that you can use to build the sample.</span></span></span></span></span></span></span></span></span>
</li></ul>
<div><strong><span class="LabelEmbedded" style="font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%">To
 find the subscription ID and the certificate thumbprint</span></span></span></span></span></span></span></span></span></span></span></strong></div>
<ol>
<li><span class="LabelEmbedded" style="font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%">Log
 on to the Windows Azure Management Portal.</span></span></span></span></span></span></span></span></span></span></span></span>
</li><li><span class="LabelEmbedded" style="font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Click
<span class="UI"><span style="line-height:150%"><strong>Hosted Services</strong>,
<span class="UI"><span style="line-height:150%"><strong>Storage Accounts &amp; CDN</strong><span style="line-height:150%">, and then click
<span class="UI"><span style="line-height:150%"><strong>Management Certificates</strong>.</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span>
</li><li><span class="LabelEmbedded" style="font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="UI"><span style="line-height:150%"><span class="UI"><span style="line-height:150%"><span style="line-height:150%"><span class="UI"><span style="line-height:150%"><span style="line-height:150%">In
 the Properties pane, you can find the certificate thumbprint under <span class="UI">
<span style="line-height:150%"><strong>Thumbprint</strong><span style="line-height:150%">. The subscription identifier is under
<span class="UI"><span style="line-height:150%"><strong>Subscription ID</strong>.</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span>
</li></ol>
<div><span style="font-size:20px; font-weight:bold">Build and Run the Sample</span></div>
<div><span style="font-size:x-small; font-weight:bold"><span style="line-height:150%">To build and run the sample</span></span></div>
<ol>
<li><span style="font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%">Open Visual Studio 2010 as an administrator.</span></span></span>
</li><li><span style="font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Browse to the csmanage folder where you extracted the sample and open csmanage.sln.</span></span></span></span>
</li><li><span style="font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Open the app.config file and locate the appSetting element. Add the SubscriptionId
 and CertificateThumbprint key values, and then save the file.</span></span></span></span></span>
</li><li><span style="font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Press F6 to build the solution.</span></span></span></span></span></span>
</li><li><span style="font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Open a
 Command Prompt window as an administrator, and then enter the csmanage command with the needed options. For more information about the available options, see the following section.</span></span></span></span></span></span></span>
</li></ol>
<h1><span style="font-size:small"><strong><span style="font-family:verdana,geneva"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Csmanage
 Options</span></span></span></span></span></span></span></span></strong></span></h1>
<div><strong><span style="font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Syntax
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">csmanage /command [/resourcetype:resourcename] [optional-parameters]</pre>
<div class="preview">
<pre class="windowsshell">csmanage&nbsp;<span class="windowsshell__commandext">/command</span>&nbsp;[<span class="windowsshell__commandext">/resourcetype</span><span class="windowsshell__commandext">:resourcename</span>]&nbsp;[optional<span class="windowsshell__commandext">-parameters</span>]&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></strong></div>
<div><strong><span style="font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%">Informational
 Commands</span></span></span></span></span></span></span></span></span></span></span></span></strong></div>
<div><span style="font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%">Display
 help information for the csmanage application.
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/?</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/</span>?&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><span style="font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">List
 the properties for the specified resource (hosted service/storage account/affinity group).
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/view-properties [/resourcetype:resource]</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/view</span><span class="windowsshell__commandext">-properties</span>&nbsp;[<span class="windowsshell__commandext">/resourcetype</span><span class="windowsshell__commandext">:resource</span>]&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><span style="font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Display
 the status of the specified operation identifier. All API commands return an operation identifier in the x-ms-request-id header.
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/get-operation-status /op-id:&lt;operation-id&gt;</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/get</span><span class="windowsshell__commandext">-operation</span><span class="windowsshell__commandext">-status</span>&nbsp;<span class="windowsshell__commandext">/op</span><span class="windowsshell__commandext">-id</span><span class="windowsshell__commandext">:</span>&lt;operation<span class="windowsshell__commandext">-id</span>&gt;&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><strong><span style="font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%">Affinity
 Group Commands</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></strong></div>
<div><span style="font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="font-family:verdana,geneva">List
 all affinity groups in the subscription. Use the view-properties option to display details on any particular affinity group</span>.
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/list-affinity-groups</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/list</span><span class="windowsshell__commandext">-affinity</span><span class="windowsshell__commandext">-groups</span>&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><strong><span style="font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%">Storage
 Account Commands</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></strong></div>
<div><span style="font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%">List
 all of the storage services that are associated with the subscription.
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/list-storage-services</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/list</span><span class="windowsshell__commandext">-storage</span><span class="windowsshell__commandext">-services</span>&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><span style="font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Display
 the primary and secondary keys for the storage account. You must specify the storage account resource.
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/view-keys</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/view</span><span class="windowsshell__commandext">-keys</span>&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><span style="font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Regenerate
 storage keys by using the key-type parameter to specify the key to regenerate. You must specify the storage account resource.
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/regenerate-key /key-type:primary|secondary</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/regenerate</span><span class="windowsshell__commandext">-key</span>&nbsp;<span class="windowsshell__commandext">/key</span><span class="windowsshell__commandext">-type</span><span class="windowsshell__commandext">:primary</span>|secondary&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><strong><span style="font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%">Hosted
 Service Commands</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></strong></div>
<div><span style="font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%">Create
 a hosted service.
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/create-hosted-service /hosted-service:&lt;name&gt; /label:&lt;label&gt; [/description:&lt;description&gt;] [/affinity-group:&lt;affinitygroupname&gt; /location:&lt;locationconstraintname&gt;]</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/create</span><span class="windowsshell__commandext">-hosted</span><span class="windowsshell__commandext">-service</span>&nbsp;<span class="windowsshell__commandext">/hosted</span><span class="windowsshell__commandext">-service</span><span class="windowsshell__commandext">:</span>&lt;name&gt;&nbsp;<span class="windowsshell__commandext">/label</span><span class="windowsshell__commandext">:</span>&lt;<span class="windowsshell__command">label</span>&gt;&nbsp;[<span class="windowsshell__commandext">/description</span><span class="windowsshell__commandext">:</span>&lt;description&gt;]&nbsp;[<span class="windowsshell__commandext">/affinity</span><span class="windowsshell__commandext">-group</span><span class="windowsshell__commandext">:</span>&lt;affinitygroupname&gt;&nbsp;<span class="windowsshell__commandext">/location</span><span class="windowsshell__commandext">:</span>&lt;locationconstraintname&gt;]&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><span style="font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">List
 all of the hosted services that exist for the subscription. You can use the </span>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span><span style="font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%">/view-properties
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span><span style="line-height:150%; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%">informational
 command to view details about a hosted service.
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/list-hosted-services</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/list</span><span class="windowsshell__commandext">-hosted</span><span class="windowsshell__commandext">-services</span>&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Update
 a hosted service.
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/update-hosted-service /hosted-service:&lt;name&gt; [/label:&lt;label&gt;] [/description:&lt;description&gt;]</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/update</span><span class="windowsshell__commandext">-hosted</span><span class="windowsshell__commandext">-service</span>&nbsp;<span class="windowsshell__commandext">/hosted</span><span class="windowsshell__commandext">-service</span><span class="windowsshell__commandext">:</span>&lt;name&gt;&nbsp;[<span class="windowsshell__commandext">/label</span><span class="windowsshell__commandext">:</span>&lt;<span class="windowsshell__command">label</span>&gt;]&nbsp;[<span class="windowsshell__commandext">/description</span><span class="windowsshell__commandext">:</span>&lt;description&gt;]&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Delete
 a hosted service.&nbsp; You must specify the hosted service resource.
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/delete-hosted-service</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/delete</span><span class="windowsshell__commandext">-hosted</span><span class="windowsshell__commandext">-service</span>&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><strong><span style="line-height:150%; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%">Deployment
 Commands</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></strong></div>
<div><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%">View
 details about a specified deployment. You can specify the deployment either by deployment environment type or by name. You must specify the hosted service resource.
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/view-deployment /slot:staging|production</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/view</span><span class="windowsshell__commandext">-deployment</span>&nbsp;<span class="windowsshell__commandext">/slot</span><span class="windowsshell__commandext">:staging</span>|production&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
<div class="endscriptcode">&nbsp;
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/view-deployment /name:&lt;deployment-name&gt;</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/view</span><span class="windowsshell__commandext">-deployment</span>&nbsp;<span class="windowsshell__commandext">/name</span><span class="windowsshell__commandext">:</span>&lt;deployment<span class="windowsshell__commandext">-name</span>&gt;&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Create
 a new deployment. The <span class="LabelEmbedded"><span style="line-height:150%">/package
<span style="line-height:150%">parameter must contain the URI to a .cspkg file in blob storage that is associated with the subscription. The
<span class="LabelEmbedded"><span style="line-height:150%">/config <span style="line-height:150%">
parameter must specify a .cscfg file on a local drive. You must specify the hosted service resource. If
<span class="LabelEmbedded"><span style="line-height:150%">/warnings-as-error <span style="line-height:150%">
is specified, warnings are returned in ErrorDetails and the operation is terminated.
<span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">The
 deployment name must be unique.</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span>
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/create-deployment  /name:&lt;name-of-deployment&gt; /label:&lt;label&gt; /package:&lt;blob-uri&gt; /config:&lt;filename&gt; /slot:staging|production [/warnings-as-error]</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/create</span><span class="windowsshell__commandext">-deployment</span>&nbsp;&nbsp;<span class="windowsshell__commandext">/name</span><span class="windowsshell__commandext">:</span>&lt;name<span class="windowsshell__commandext">-of</span><span class="windowsshell__commandext">-deployment</span>&gt;&nbsp;<span class="windowsshell__commandext">/label</span><span class="windowsshell__commandext">:</span>&lt;<span class="windowsshell__command">label</span>&gt;&nbsp;<span class="windowsshell__commandext">/package</span><span class="windowsshell__commandext">:</span>&lt;blob<span class="windowsshell__commandext">-uri</span>&gt;&nbsp;<span class="windowsshell__commandext">/config</span><span class="windowsshell__commandext">:</span>&lt;filename&gt;&nbsp;<span class="windowsshell__commandext">/slot</span><span class="windowsshell__commandext">:staging</span>|production&nbsp;[<span class="windowsshell__commandext">/warnings</span><span class="windowsshell__commandext">-as</span><span class="windowsshell__commandext">-error</span>]&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Swap
 the deployments in between the production environment and the staging environment. If the deployment exists in both the production and staging environments, you must specify the names of both deployments. If a deployment does not exist in the production environment,
 the /production-slot parameter is not required. You must specify the hosted service resource.
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/swap-deployment /production-slot:&lt;deployment-name-in-production&gt; /source-deployment:&lt;deployment-name-in-staging&gt;</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/swap</span><span class="windowsshell__commandext">-deployment</span>&nbsp;<span class="windowsshell__commandext">/production</span><span class="windowsshell__commandext">-slot</span><span class="windowsshell__commandext">:</span>&lt;deployment<span class="windowsshell__commandext">-name</span><span class="windowsshell__commandext">-in</span><span class="windowsshell__commandext">-production</span>&gt;&nbsp;<span class="windowsshell__commandext">/source</span><span class="windowsshell__commandext">-deployment</span><span class="windowsshell__commandext">:</span>&lt;deployment<span class="windowsshell__commandext">-name</span><span class="windowsshell__commandext">-in</span><span class="windowsshell__commandext">-staging</span>&gt;&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Delete
 the specified deployment. You must specify the hosted service resource. <span style="line-height:150%; font-family:verdana,geneva; font-size:x-small">
The deployment must be in suspended state to be deleted.
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/delete-deployment /name:&lt;deployment-name&gt;</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/delete</span><span class="windowsshell__commandext">-deployment</span>&nbsp;<span class="windowsshell__commandext">/name</span><span class="windowsshell__commandext">:</span>&lt;deployment<span class="windowsshell__commandext">-name</span>&gt;&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
<div class="endscriptcode">&nbsp;
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/delete-deployment /slot:production|staging</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/delete</span><span class="windowsshell__commandext">-deployment</span>&nbsp;<span class="windowsshell__commandext">/slot</span><span class="windowsshell__commandext">:production</span>|staging&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Change
 the deployment status to ready or stopped. You must specify the hosted service resource.
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/update-deployment /status:running|suspended /name:&lt;deployment-name&gt;</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/update</span><span class="windowsshell__commandext">-deployment</span>&nbsp;<span class="windowsshell__commandext">/status</span><span class="windowsshell__commandext">:running</span>|suspended&nbsp;<span class="windowsshell__commandext">/name</span><span class="windowsshell__commandext">:</span>&lt;deployment<span class="windowsshell__commandext">-name</span>&gt;&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
<div class="endscriptcode">&nbsp;
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/update-deployment /status:running|suspended /slot:production|staging</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/update</span><span class="windowsshell__commandext">-deployment</span>&nbsp;<span class="windowsshell__commandext">/status</span><span class="windowsshell__commandext">:running</span>|suspended&nbsp;<span class="windowsshell__commandext">/slot</span><span class="windowsshell__commandext">:production</span>|staging&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Change
 the configuration of the deployment. You must specify the hosted service resource.</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/change-deployment-config /config:&lt;filename&gt; /slot:production|staging [/warnings-as-error]</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/change</span><span class="windowsshell__commandext">-deployment</span><span class="windowsshell__commandext">-config</span>&nbsp;<span class="windowsshell__commandext">/config</span><span class="windowsshell__commandext">:</span>&lt;filename&gt;&nbsp;<span class="windowsshell__commandext">/slot</span><span class="windowsshell__commandext">:production</span>|staging&nbsp;[<span class="windowsshell__commandext">/warnings</span><span class="windowsshell__commandext">-as</span><span class="windowsshell__commandext">-error</span>]&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/change-deployment-config /config:&lt;filename&gt; /name:&lt;deployment-name&gt; [/warnings-as-error]</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/change</span><span class="windowsshell__commandext">-deployment</span><span class="windowsshell__commandext">-config</span>&nbsp;<span class="windowsshell__commandext">/config</span><span class="windowsshell__commandext">:</span>&lt;filename&gt;&nbsp;<span class="windowsshell__commandext">/name</span><span class="windowsshell__commandext">:</span>&lt;deployment<span class="windowsshell__commandext">-name</span>&gt;&nbsp;[<span class="windowsshell__commandext">/warnings</span><span class="windowsshell__commandext">-as</span><span class="windowsshell__commandext">-error</span>]&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Initiates
 an in-place upgrade of the specified deployment. You must specify the hosted service resource.
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/upgrade-deployment /mode:auto|manual /label:&lt;label&gt; /config:&lt;config-filename&gt; /name:&lt;deployment-name&gt; [/warnings-as-error]</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/upgrade</span><span class="windowsshell__commandext">-deployment</span>&nbsp;<span class="windowsshell__commandext">/mode</span><span class="windowsshell__commandext">:auto</span>|manual&nbsp;<span class="windowsshell__commandext">/label</span><span class="windowsshell__commandext">:</span>&lt;<span class="windowsshell__command">label</span>&gt;&nbsp;<span class="windowsshell__commandext">/config</span><span class="windowsshell__commandext">:</span>&lt;config<span class="windowsshell__commandext">-filename</span>&gt;&nbsp;<span class="windowsshell__commandext">/name</span><span class="windowsshell__commandext">:</span>&lt;deployment<span class="windowsshell__commandext">-name</span>&gt;&nbsp;[<span class="windowsshell__commandext">/warnings</span><span class="windowsshell__commandext">-as</span><span class="windowsshell__commandext">-error</span>]&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
<div class="endscriptcode">&nbsp;
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/upgrade-deployment /mode:auto|manual /label:&lt;label&gt; /config:&lt;config-filename&gt; /slot:staging|production [/warnings-as-error]</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/upgrade</span><span class="windowsshell__commandext">-deployment</span>&nbsp;<span class="windowsshell__commandext">/mode</span><span class="windowsshell__commandext">:auto</span>|manual&nbsp;<span class="windowsshell__commandext">/label</span><span class="windowsshell__commandext">:</span>&lt;<span class="windowsshell__command">label</span>&gt;&nbsp;<span class="windowsshell__commandext">/config</span><span class="windowsshell__commandext">:</span>&lt;config<span class="windowsshell__commandext">-filename</span>&gt;&nbsp;<span class="windowsshell__commandext">/slot</span><span class="windowsshell__commandext">:staging</span>|production&nbsp;[<span class="windowsshell__commandext">/warnings</span><span class="windowsshell__commandext">-as</span><span class="windowsshell__commandext">-error</span>]&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Walk
 the specified upgrade domain. You must specify the hosted service resource.
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/walk-upgrade-domain /domain:&lt;update-domain-number&gt; /slot:production|staging</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/walk</span><span class="windowsshell__commandext">-upgrade</span><span class="windowsshell__commandext">-domain</span>&nbsp;<span class="windowsshell__commandext">/domain</span><span class="windowsshell__commandext">:</span>&lt;update<span class="windowsshell__commandext">-domain</span><span class="windowsshell__commandext">-number</span>&gt;&nbsp;<span class="windowsshell__commandext">/slot</span><span class="windowsshell__commandext">:production</span>|staging&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
<div class="endscriptcode">&nbsp;
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/walk-upgrade-domain /domain:&lt;update-domain-number&gt; /name:&lt;deployment-name&gt;</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/walk</span><span class="windowsshell__commandext">-upgrade</span><span class="windowsshell__commandext">-domain</span>&nbsp;<span class="windowsshell__commandext">/domain</span><span class="windowsshell__commandext">:</span>&lt;update<span class="windowsshell__commandext">-domain</span><span class="windowsshell__commandext">-number</span>&gt;&nbsp;<span class="windowsshell__commandext">/name</span><span class="windowsshell__commandext">:</span>&lt;deployment<span class="windowsshell__commandext">-name</span>&gt;&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Request
 the reboot of a single role instance in the deployment. You must specify the hosted service resource.
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/reboot-deploymentroleinstance /slot:&lt;staging|production&gt; /role-instance-name:&lt;roleinstancename&gt;</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/reboot</span><span class="windowsshell__commandext">-deploymentroleinstance</span>&nbsp;<span class="windowsshell__commandext">/slot</span><span class="windowsshell__commandext">:</span>&lt;staging|production&gt;&nbsp;<span class="windowsshell__commandext">/role</span><span class="windowsshell__commandext">-instance</span><span class="windowsshell__commandext">-name</span><span class="windowsshell__commandext">:</span>&lt;roleinstancename&gt;&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
<div class="endscriptcode">&nbsp;
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/reboot-deploymentroleinstance /name:&lt;deploymentname&gt; /role-instance-name:&lt;roleinstancename&gt;</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/reboot</span><span class="windowsshell__commandext">-deploymentroleinstance</span>&nbsp;<span class="windowsshell__commandext">/name</span><span class="windowsshell__commandext">:</span>&lt;deploymentname&gt;&nbsp;<span class="windowsshell__commandext">/role</span><span class="windowsshell__commandext">-instance</span><span class="windowsshell__commandext">-name</span><span class="windowsshell__commandext">:</span>&lt;roleinstancename&gt;&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Request
 the reimaging of a single role instance in the deployment. You must specify the hosted service resource.
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/reimage-deploymentroleinstance /slot:&lt;staging|production&gt; /role-instance-name:&lt;roleinstancename&gt;</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/reimage</span><span class="windowsshell__commandext">-deploymentroleinstance</span>&nbsp;<span class="windowsshell__commandext">/slot</span><span class="windowsshell__commandext">:</span>&lt;staging|production&gt;&nbsp;<span class="windowsshell__commandext">/role</span><span class="windowsshell__commandext">-instance</span><span class="windowsshell__commandext">-name</span><span class="windowsshell__commandext">:</span>&lt;roleinstancename&gt;&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
<div class="endscriptcode">&nbsp;
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/reimage-deploymentroleinstance /name:&lt;deploymentname&gt; /role-instance-name:&lt;roleinstancename&gt;</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/reimage</span><span class="windowsshell__commandext">-deploymentroleinstance</span>&nbsp;<span class="windowsshell__commandext">/name</span><span class="windowsshell__commandext">:</span>&lt;deploymentname&gt;&nbsp;<span class="windowsshell__commandext">/role</span><span class="windowsshell__commandext">-instance</span><span class="windowsshell__commandext">-name</span><span class="windowsshell__commandext">:</span>&lt;roleinstancename&gt;&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><strong><span style="line-height:150%; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%">Certificate
 Commands</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></strong></div>
<div><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%">List
 the certificate thumbprints for a hosted service. You must specify the hosted service resource.
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/list-certificates</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/list</span><span class="windowsshell__commandext">-certificates</span>&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Add
 a certificate to the specified hosted service. You must specify the hosted service resource.
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/add-certificate /cert-file:&lt;path-to-cert-file&gt; /cert-format:[pfx] /cert-password:&lt;password&gt;</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/add</span><span class="windowsshell__commandext">-certificate</span>&nbsp;<span class="windowsshell__commandext">/cert</span><span class="windowsshell__commandext">-file</span><span class="windowsshell__commandext">:</span>&lt;<span class="windowsshell__command">path</span><span class="windowsshell__commandext">-to</span><span class="windowsshell__commandext">-cert</span><span class="windowsshell__commandext">-file</span>&gt;&nbsp;<span class="windowsshell__commandext">/cert</span><span class="windowsshell__commandext">-format</span><span class="windowsshell__commandext">:</span>[pfx]&nbsp;<span class="windowsshell__commandext">/cert</span><span class="windowsshell__commandext">-password</span><span class="windowsshell__commandext">:</span>&lt;password&gt;&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Deletes
 certificate with specified thumbprint and algorithm. Should have hosted service resource specified.
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/delete-certificate /cert-thumbprint:&lt;thumbprint&gt; /algorithm:&lt;algorithm&gt;</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/delete</span><span class="windowsshell__commandext">-certificate</span>&nbsp;<span class="windowsshell__commandext">/cert</span><span class="windowsshell__commandext">-thumbprint</span><span class="windowsshell__commandext">:</span>&lt;thumbprint&gt;&nbsp;<span class="windowsshell__commandext">/algorithm</span><span class="windowsshell__commandext">:</span>&lt;algorithm&gt;&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><strong><span style="line-height:150%; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%">Operating
 System Commands</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></strong></div>
<div><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%">List
 all of the operating systems that you can use to create a deployment in Windows Azure.
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/list-operating-systems</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/list</span><span class="windowsshell__commandext">-operating</span><span class="windowsshell__commandext">-systems</span>&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">List
 all of the operating system families and the operating systems that belong to them.
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/list-operating-system-families</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/list</span><span class="windowsshell__commandext">-operating</span><span class="windowsshell__commandext">-system</span><span class="windowsshell__commandext">-families</span>&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><strong><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%; font-size:10pt">Location
 Commands</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></strong></div>
<div><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%">List
 all of the locations that are accessible from a subscription.
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/list-locations</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/list</span><span class="windowsshell__commandext">-locations</span>&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><strong><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Resources</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></strong></div>
<div><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Specify
 the storage account name.
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/storage-service:&lt;storage-account-name&gt;</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/storage</span><span class="windowsshell__commandext">-service</span><span class="windowsshell__commandext">:</span>&lt;storage<span class="windowsshell__commandext">-account</span><span class="windowsshell__commandext">-name</span>&gt;&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Specify
 the hosted service name.
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/hosted-service:&lt;hosted-service-name&gt;</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/hosted</span><span class="windowsshell__commandext">-service</span><span class="windowsshell__commandext">:</span>&lt;hosted<span class="windowsshell__commandext">-service</span><span class="windowsshell__commandext">-name</span>&gt;&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%; font-size:11pt">Specify
 the affinity group.
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">/affinity-group:&lt;affinity-group-name&gt;</pre>
<div class="preview">
<pre class="windowsshell"><span class="windowsshell__commandext">/affinity</span><span class="windowsshell__commandext">-group</span><span class="windowsshell__commandext">:</span>&lt;affinity<span class="windowsshell__commandext">-group</span><span class="windowsshell__commandext">-name</span>&gt;&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><strong><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Examples</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></strong></div>
<div><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Create
 a new deployment in staging.
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">csmanage.exe /create-deployment /slot:staging /hosted-service:MyHostedService /name:MyDeployment /label:MyLabel /config:./ServiceConfiguration.cscfg /package:http://myaccount.blob.core.windows.net/packages/MyApplication.cspkg</pre>
<div class="preview">
<pre class="js">csmanage.exe&nbsp;/create-deployment&nbsp;/slot:staging&nbsp;/hosted-service:MyHostedService&nbsp;/name:MyDeployment&nbsp;/label:MyLabel&nbsp;/config:.<span class="js__reg_exp">/ServiceConfiguration.cscfg&nbsp;/</span>package:http:<span class="js__sl_comment">//myaccount.blob.core.windows.net/packages/MyApplication.cspkg</span>&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Update
 the deployment status to running.
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">csmanage.exe /update-deployment /slot:staging /hosted-service:MyHostedService /status:running</pre>
<div class="preview">
<pre class="windowsshell">csmanage.exe&nbsp;<span class="windowsshell__commandext">/update</span><span class="windowsshell__commandext">-deployment</span>&nbsp;<span class="windowsshell__commandext">/slot</span><span class="windowsshell__commandext">:staging</span>&nbsp;<span class="windowsshell__commandext">/hosted</span><span class="windowsshell__commandext">-service</span><span class="windowsshell__commandext">:MyHostedService</span>&nbsp;<span class="windowsshell__commandext">/status</span><span class="windowsshell__commandext">:running</span>&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Swap
 the deployments in the staging and production environments.
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">csmanage.exe /swap-deployment /hosted-service:MyHostedService /source-deployment:MyStagingDeployment /production-slot:MyProductionDeployment</pre>
<div class="preview">
<pre class="js">csmanage.exe&nbsp;/swap-deployment&nbsp;/hosted-service:MyHostedService&nbsp;/source-deployment:MyStagingDeployment&nbsp;/production-slot:MyProductionDeployment&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>
</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div><span style="line-height:150%; font-family:verdana,geneva; font-size:x-small"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span class="LabelEmbedded"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%"><span style="line-height:150%">Change
 the configuration or number of instances. <span style="line-height:150%; font-family:verdana,geneva; font-size:x-small">
The number of role instances is defined in the ServiceConfiguration.cscfg file.</span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></span></div>
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>Windows Shell Script</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">windowsshell</span>
<pre class="hidden">csmanage.exe /change-deployment-config /hosted-service:MyHostedService /slot:production /config:./ServiceConfiguration.cscfg</pre>
<div class="preview">
<pre class="csharp">csmanage.exe&nbsp;/change-deployment-config&nbsp;/hosted-service:MyHostedService&nbsp;/slot:production&nbsp;/config:./ServiceConfiguration.cscfg&nbsp;
&nbsp;
</pre>
</div>
</div>
</div>