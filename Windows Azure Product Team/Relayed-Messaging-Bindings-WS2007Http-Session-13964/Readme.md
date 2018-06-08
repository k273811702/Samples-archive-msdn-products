# Relayed Messaging Bindings: WS2007Http Session
## Requires
* Visual Studio 2010
## License
* Apache License, Version 2.0
## Technologies
* Microsoft Azure
* Service Bus
## Topics
* Service Bus
## IsPublished
* True
## ModifiedDate
* 2011-11-15 03:46:42
## Description

<h1>Introduction</h1>
<p>This sample demonstrates using the WS2007HttpRelayBinding binding with reliable session enabled. It also shows how to specify Service Bus credentials in configuration instead of doing so programmatically.&nbsp;&nbsp;</p>
<h1>Prerequisites</h1>
<p>If you haven't already done so, read the release notes document that explains how to sign up for a Windows Azure account and how to configure your environment.&nbsp;&nbsp;</p>
<h1>Service&nbsp;&nbsp;</h1>
<div>The service project defines a simple session contract (IPingContract):</div>
<div>&nbsp;</div>
<div>
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title">C#</div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">csharp</span>
<pre class="hidden">[ServiceContract(SessionMode = SessionMode.Required, Name = &quot;IPingContract&quot;, Namespace = &quot;http://samples.microsoft.com/ServiceModel/Relay/&quot;)]
public interface IPingContract
{
    [OperationContract(IsInitiating = true, IsTerminating = false)]
    void Open();
 
    [OperationContract(IsInitiating = false, IsOneWay = true, IsTerminating = false)]
    void Ping(int count);
 
    [OperationContract(IsInitiating = false, IsTerminating = true)]
    void Close();
}
</pre>
<div class="preview">
<pre class="js">[ServiceContract(SessionMode&nbsp;=&nbsp;SessionMode.Required,&nbsp;Name&nbsp;=&nbsp;<span class="js__string">&quot;IPingContract&quot;</span>,&nbsp;Namespace&nbsp;=&nbsp;<span class="js__string">&quot;http://samples.microsoft.com/ServiceModel/Relay/&quot;</span>)]&nbsp;
public&nbsp;interface&nbsp;IPingContract&nbsp;
<span class="js__brace">{</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;[OperationContract(IsInitiating&nbsp;=&nbsp;true,&nbsp;IsTerminating&nbsp;=&nbsp;false)]&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__operator">void</span>&nbsp;Open();&nbsp;
&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;[OperationContract(IsInitiating&nbsp;=&nbsp;false,&nbsp;IsOneWay&nbsp;=&nbsp;true,&nbsp;IsTerminating&nbsp;=&nbsp;false)]&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__operator">void</span>&nbsp;Ping(int&nbsp;count);&nbsp;
&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;[OperationContract(IsInitiating&nbsp;=&nbsp;false,&nbsp;IsTerminating&nbsp;=&nbsp;true)]&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__operator">void</span>&nbsp;Close();&nbsp;
<span class="js__brace">}</span></pre>
</div>
</div>
</div>
<div class="endscriptcode">The Open operation is used to initiate a session. <strong>
Ping </strong>is a one-way operation that can be called an arbitrary number of times. The Close operation terminates the sequence. The service implements this contract in the
<strong>PingService </strong>class.</div>
<div class="endscriptcode">The endpoints for this service are defined in the application configuration file, as follows:</div>
<div>
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title">XML</div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">xml</span>
<pre class="hidden">&lt;service name=&quot;Microsoft.ServiceBus.Samples.PingService&quot;&gt;
    &lt;endpoint name=&quot;ServiceBusEndpoint&quot;
                       contract=&quot;Microsoft.ServiceBus.Samples.IPingContract&quot;
                       bindingConfiguration=&quot;default&quot;
                       binding=&quot;ws2007HttpRelayBinding&quot;
                       behaviorConfiguration=&quot;sharedSecretClientCredentials&quot; /&gt;
&lt;/service&gt;
</pre>
<div class="preview">
<pre class="js">&lt;service&nbsp;name=<span class="js__string">&quot;Microsoft.ServiceBus.Samples.PingService&quot;</span>&gt;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&lt;endpoint&nbsp;name=<span class="js__string">&quot;ServiceBusEndpoint&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;contract=<span class="js__string">&quot;Microsoft.ServiceBus.Samples.IPingContract&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;bindingConfiguration=<span class="js__string">&quot;default&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;binding=<span class="js__string">&quot;ws2007HttpRelayBinding&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;behaviorConfiguration=<span class="js__string">&quot;sharedSecretClientCredentials&quot;</span>&nbsp;/&gt;&nbsp;
&lt;/service&gt;&nbsp;
</pre>
</div>
</div>
</div>
<div class="endscriptcode"><br>
This endpoint is configured to use a binding of type <strong>WS2007HttpRelayBinding</strong>. It references (via the
<strong>bindingConfiguration </strong>attribute) a binding configuration named default:</div>
</div>
<div>
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title">XML</div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">xml</span>
<pre class="hidden">&lt;bindings&gt;
    &lt;!-- Application Binding --&gt;
    &lt;ws2007HttpRelayBinding&gt;
        &lt;binding name=&quot;default&quot;&gt;
            &lt;reliableSession enabled=&quot;true&quot; /&gt;
            &lt;security mode=&quot;Transport&quot; relayClientAuthenticationType=&quot;RelayAccessToken&quot;/&gt;
        &lt;/binding&gt;
    &lt;/ws2007HttpRelayBinding&gt;
&lt;/bindings&gt;
</pre>
<div class="preview">
<pre class="js">&lt;bindings&gt;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&lt;!--&nbsp;Application&nbsp;Binding&nbsp;--&gt;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&lt;ws2007HttpRelayBinding&gt;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&lt;binding&nbsp;name=<span class="js__string">&quot;default&quot;</span>&gt;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&lt;reliableSession&nbsp;enabled=<span class="js__string">&quot;true&quot;</span>&nbsp;/&gt;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&lt;security&nbsp;mode=<span class="js__string">&quot;Transport&quot;</span>&nbsp;relayClientAuthenticationType=<span class="js__string">&quot;RelayAccessToken&quot;</span>/&gt;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&lt;/binding&gt;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&lt;/ws2007HttpRelayBinding&gt;&nbsp;
&lt;/bindings&gt;&nbsp;
</pre>
</div>
</div>
</div>
</div>
</div>
<div>&nbsp;The endopint also references a behavior configuration (via the <strong>
behaviorConfiguration </strong>attribute) named <strong>sharedSecretClientCredentials</strong>. This is where you can specify the issuer name and secret to be used by the service to authenticate with the Service Bus:</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div>
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title">XML</div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">xml</span>
<pre class="hidden">&lt;behaviors&gt;      
    &lt;endpointBehaviors&gt;
        &lt;behavior name=&quot;sharedSecretClientCredentials&quot;&gt;
            &lt;transportClientEndpointBehavior credentialType=&quot;SharedSecret&quot;&gt;
                &lt;clientCredentials&gt;
                    &lt;sharedSecret issuerName=&quot;ISSUER_NAME&quot; issuerSecret=&quot;ISSUER_SECRET&quot; /&gt;
                &lt;/clientCredentials&gt;
            &lt;/transportClientEndpointBehavior&gt;
        &lt;/behavior&gt;
    &lt;/endpointBehaviors&gt;
&lt;/behaviors&gt;
</pre>
<div class="preview">
<pre class="js">&lt;behaviors&gt;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&lt;endpointBehaviors&gt;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&lt;behavior&nbsp;name=<span class="js__string">&quot;sharedSecretClientCredentials&quot;</span>&gt;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&lt;transportClientEndpointBehavior&nbsp;credentialType=<span class="js__string">&quot;SharedSecret&quot;</span>&gt;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&lt;clientCredentials&gt;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&lt;sharedSecret&nbsp;issuerName=<span class="js__string">&quot;ISSUER_NAME&quot;</span>&nbsp;issuerSecret=<span class="js__string">&quot;ISSUER_SECRET&quot;</span>&nbsp;/&gt;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&lt;/clientCredentials&gt;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&lt;/transportClientEndpointBehavior&gt;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&lt;/behavior&gt;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&lt;/endpointBehaviors&gt;&nbsp;
&lt;/behaviors&gt;&nbsp;
</pre>
</div>
</div>
</div>
<h1>Client</h1>
<div><br>
The client is configured (again, via the application configuration file) with the following endpoint:</div>
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title">XML</div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">xml</span>
<pre class="hidden">&lt;client&gt;
    &lt;!-- Application Endpoint --&gt;
    &lt;endpoint name=&quot;ServiceBusEndpoint&quot;
                       binding=&quot;ws2007HttpRelayBinding&quot;
                       contract=&quot;Microsoft.ServiceBus.Samples.IPingContract&quot;
                       behaviorConfiguration=&quot;sharedSecretClientCredentials&quot;
                       bindingConfiguration=&quot;default&quot; /&gt;
&lt;/client&gt;
</pre>
<div class="preview">
<pre class="js">&lt;client&gt;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&lt;!--&nbsp;Application&nbsp;Endpoint&nbsp;--&gt;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&lt;endpoint&nbsp;name=<span class="js__string">&quot;ServiceBusEndpoint&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;binding=<span class="js__string">&quot;ws2007HttpRelayBinding&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;contract=<span class="js__string">&quot;Microsoft.ServiceBus.Samples.IPingContract&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;behaviorConfiguration=<span class="js__string">&quot;sharedSecretClientCredentials&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;bindingConfiguration=<span class="js__string">&quot;default&quot;</span>&nbsp;/&gt;&nbsp;
&lt;/client&gt;&nbsp;
</pre>
</div>
</div>
</div>
<div class="endscriptcode"><span style="color:black; line-height:115%">In the code, an endpoint is opened.</span></div>
<div class="endscriptcode"><span style="color:black; line-height:115%">&nbsp;</span></div>
<div class="endscriptcode">
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title">C#</div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">csharp</span>
<pre class="hidden">Console.Write(&quot;Your Service Namespace: &quot;);
string serviceNamespace = Console.ReadLine();

Uri serviceUri = ServiceBusEnvironment.CreateServiceUri(&quot;https&quot;, serviceNamespace, &quot;PingService&quot;);
ChannelFactory channelFactory = new ChannelFactory(&quot;ServiceBusEndpoint&quot;, new EndpointAddress(serviceUri));

IPingContract channel = channelFactory.CreateChannel();
Console.WriteLine(&quot;Opening Channel.&quot;);
channel.Open();
</pre>
<div class="preview">
<pre class="js">Console.Write(<span class="js__string">&quot;Your&nbsp;Service&nbsp;Namespace:&nbsp;&quot;</span>);&nbsp;
string&nbsp;serviceNamespace&nbsp;=&nbsp;Console.ReadLine();&nbsp;
&nbsp;
Uri&nbsp;serviceUri&nbsp;=&nbsp;ServiceBusEnvironment.CreateServiceUri(<span class="js__string">&quot;https&quot;</span>,&nbsp;serviceNamespace,&nbsp;<span class="js__string">&quot;PingService&quot;</span>);&nbsp;
ChannelFactory&nbsp;channelFactory&nbsp;=&nbsp;<span class="js__operator">new</span>&nbsp;ChannelFactory(<span class="js__string">&quot;ServiceBusEndpoint&quot;</span>,&nbsp;<span class="js__operator">new</span>&nbsp;EndpointAddress(serviceUri));&nbsp;
&nbsp;
IPingContract&nbsp;channel&nbsp;=&nbsp;channelFactory.CreateChannel();&nbsp;
Console.WriteLine(<span class="js__string">&quot;Opening&nbsp;Channel.&quot;</span>);&nbsp;
channel.Open();&nbsp;
</pre>
</div>
</div>
</div>
</div>
<div class="endscriptcode">
<div class="endscriptcode">&nbsp;</div>
</div>
<div>&nbsp;</div>
<div>After the ChannelFactory has been created, the client application creates a channel to the service and then interacts with it. Once the interaction is complete, the client closes the channel and the ChannelFactory, then exits.</div>
<div>&nbsp;</div>
<h1>Building and Running the Sample</h1>
<div></div>
<div>Follow the steps below to run the application:</div>
<div>&nbsp;</div>
<ol>
<li>
<div>Open the App.config files in both the Service and Client projects and replace the strings ISSUER_NAME and ISSUER_SECRET with the issuer name and secret you want to use. Note that you may use the same values in both projects or alternately, you can set
 up multiple issuers and use different values for the Service and Client.</div>
</li><li>
<div>Build the Service and Client projects.</div>
</li><li>
<div>From a command prompt with elevated privileges, run the service (Service\bin\Debug\Service.exe).</div>
</li><li>
<div>When prompted, provide the Service Bus namespace you want to use. At this point, the service should indicate that it is listening at the configured address.</div>
</li><li>
<div>From another command prompt, run the client (Client\bin\Debug\Client.exe).</div>
</li><li>
<div>Provide the Service Bus namespace you want to connect to.</div>
</li></ol>
<div><br>
When finished, press Enter to exit the client and the service.</div>
<div>&nbsp;</div>
<h2>Expected Output &ndash; Client</h2>
</div>
<div>&nbsp;&nbsp;</div>
<div class="endscriptcode">&nbsp;&nbsp;</div>
<div>Your Service Namespace: &lt;service namespace&gt;<br>
Opening Channel.<br>
Ping: 1<br>
Ping: 2<br>
Ping: 3<br>
Ping: 4<br>
Ping: 5<br>
Ping: 6<br>
Ping: 7<br>
Ping: 8<br>
Ping: 9<br>
Ping: 10<br>
Ping: 11<br>
Ping: 12<br>
Ping: 13<br>
Ping: 14<br>
Ping: 15<br>
Ping: 16<br>
Ping: 17<br>
Ping: 18<br>
Ping: 19<br>
Ping: 20<br>
Ping: 21<br>
Ping: 22<br>
Ping: 23<br>
Ping: 24<br>
Ping: 25<br>
Closing Channel.</div>
<div>&nbsp;&nbsp;</div>
<h2>Expected Output &ndash; Service</h2>
<div>&nbsp;</div>
<div>Your Service Namespace: &lt;service namespace&gt;<br>
Service address: <a href="https://&lt;serviceNamespace&gt;.servicebus.windows.net/PingService/">
https://&lt;serviceNamespace&gt;.servicebus.windows.net/PingService/</a></div>
<div>Press [Enter] to exit</div>
<div>Session (urn:uuid:df3910e7-28f4-4e19-a6f1-4dbcd13289e2) Opened.<br>
Session (urn:uuid:df3910e7-28f4-4e19-a6f1-4dbcd13289e2) Ping: 1<br>
Session (urn:uuid:df3910e7-28f4-4e19-a6f1-4dbcd13289e2) Ping: 2<br>
Session (urn:uuid:df3910e7-28f4-4e19-a6f1-4dbcd13289e2) Ping: 3<br>
Session (urn:uuid:df3910e7-28f4-4e19-a6f1-4dbcd13289e2) Ping: 4<br>
Session (urn:uuid:df3910e7-28f4-4e19-a6f1-4dbcd13289e2) Ping: 5<br>
Session (urn:uuid:df3910e7-28f4-4e19-a6f1-4dbcd13289e2) Ping: 6<br>
Session (urn:uuid:df3910e7-28f4-4e19-a6f1-4dbcd13289e2) Ping: 7<br>
Session (urn:uuid:df3910e7-28f4-4e19-a6f1-4dbcd13289e2) Ping: 8<br>
Session (urn:uuid:df3910e7-28f4-4e19-a6f1-4dbcd13289e2) Ping: 9<br>
Session (urn:uuid:df3910e7-28f4-4e19-a6f1-4dbcd13289e2) Ping: 10<br>
Session (urn:uuid:df3910e7-28f4-4e19-a6f1-4dbcd13289e2) Ping: 11<br>
Session (urn:uuid:df3910e7-28f4-4e19-a6f1-4dbcd13289e2) Ping: 12<br>
Session (urn:uuid:df3910e7-28f4-4e19-a6f1-4dbcd13289e2) Ping: 13<br>
Session (urn:uuid:df3910e7-28f4-4e19-a6f1-4dbcd13289e2) Ping: 14<br>
Session (urn:uuid:df3910e7-28f4-4e19-a6f1-4dbcd13289e2) Ping: 15<br>
Session (urn:uuid:df3910e7-28f4-4e19-a6f1-4dbcd13289e2) Ping: 16<br>
Session (urn:uuid:df3910e7-28f4-4e19-a6f1-4dbcd13289e2) Ping: 17<br>
Session (urn:uuid:df3910e7-28f4-4e19-a6f1-4dbcd13289e2) Ping: 18<br>
Session (urn:uuid:df3910e7-28f4-4e19-a6f1-4dbcd13289e2) Ping: 19<br>
Session (urn:uuid:df3910e7-28f4-4e19-a6f1-4dbcd13289e2) Ping: 20<br>
Session (urn:uuid:df3910e7-28f4-4e19-a6f1-4dbcd13289e2) Ping: 21<br>
Session (urn:uuid:df3910e7-28f4-4e19-a6f1-4dbcd13289e2) Ping: 22<br>
Session (urn:uuid:df3910e7-28f4-4e19-a6f1-4dbcd13289e2) Ping: 23<br>
Session (urn:uuid:df3910e7-28f4-4e19-a6f1-4dbcd13289e2) Ping: 24<br>
Session (urn:uuid:df3910e7-28f4-4e19-a6f1-4dbcd13289e2) Ping: 25<br>
Session (urn:uuid:df3910e7-28f4-4e19-a6f1-4dbcd13289e2) Closed.</div>
<p>&nbsp;</p>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
