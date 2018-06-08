# Relayed Messaging Bindings: Net Event
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
* 2011-11-15 12:15:53
## Description

<h1>Introduction</h1>
<div>&nbsp;</div>
<div>This sample demonstrates using the <strong>NetEventRelayBinding</strong> binding on the Windows Azure Service Bus. This binding allows multiple applications to listen to events sent to an endpoint; events sent to that endpoint are received by all applications.</div>
<div>The application accepts one of three mutually exclusive, optional command line parameters that select the connectivity mode for the Service Bus environment.</div>
<ul>
<li><strong>-auto</strong> selects the AutoDetect mode. In this mode, the Service Bus client automatically switches between TCP and HTTP connectivity.
</li><li><strong>-tcp</strong> selects the Tcp mode, in which all communication to the Service Bus is performed using outbound TCP connections.
</li><li><strong>-http</strong> tells the application to use the Http mode, in which all communication to Service Bus is performed using outbound HTTP connections.
</li></ul>
<h1>Prerequisites</h1>
<div>If you haven't already done so, read the release notes document that explains how to sign up for a Windows Azure account and how to configure your environment. It also contains important information about the default security settings for your environment
 that you need to be aware of.</div>
<div>&nbsp;</div>
<h1>Service Contract &amp; Implementation</h1>
<div>This sample implements a chatroom via the project's<code> IMulticastContract</code> and
<code>MulticastService</code> implementations. <code>Hello</code> and <code>Bye</code> are used within the chatroom application to notify participants when a user joins and leaves the chat.
<code>Chat</code> is called by the application when a user provides a string to contribute to the conversation.</div>
<div>Note that the methods must be marked as <code>IsOneWay=True</code>.</div>
<div><br>
<br>
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>C#</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">csharp</span>
<pre class="hidden">[ServiceContract(Name = &quot;IMulticastContract&quot;, Namespace = &quot;http://samples.microsoft.com/ServiceModel/Relay/&quot;)]
public interface IMulticastContract
{
     [OperationContract(IsOneWay=true)]
     void Hello(string nickName);
 
     [OperationContract(IsOneWay = true)]
     void Chat(string nickName, string text);
 
     [OperationContract(IsOneWay = true)]
     void Bye(string nickName);
}
</pre>
<div class="preview">
<pre class="csharp">[ServiceContract(Name&nbsp;=&nbsp;<span class="cs__string">&quot;IMulticastContract&quot;</span>,&nbsp;Namespace&nbsp;=&nbsp;<span class="cs__string">&quot;http://samples.microsoft.com/ServiceModel/Relay/&quot;</span>)]&nbsp;
<span class="cs__keyword">public</span><span class="cs__keyword">interface</span>&nbsp;IMulticastContract&nbsp;
{&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[OperationContract(IsOneWay=<span class="cs__keyword">true</span>)]&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="cs__keyword">void</span>&nbsp;Hello(<span class="cs__keyword">string</span>&nbsp;nickName);&nbsp;
&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[OperationContract(IsOneWay&nbsp;=&nbsp;<span class="cs__keyword">true</span>)]&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="cs__keyword">void</span>&nbsp;Chat(<span class="cs__keyword">string</span>&nbsp;nickName,&nbsp;<span class="cs__keyword">string</span>&nbsp;text);&nbsp;
&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[OperationContract(IsOneWay&nbsp;=&nbsp;<span class="cs__keyword">true</span>)]&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="cs__keyword">void</span>&nbsp;Bye(<span class="cs__keyword">string</span>&nbsp;nickName);&nbsp;
}&nbsp;
</pre>
</div>
</div>
</div>
</div>
<div><span style="color:black; font-family:">The service implementation is shown below.</span></div>
<div>
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>C#</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">csharp</span>
<pre class="hidden">ServiceBehavior(Name = &quot;MulticastService&quot;, Namespace = &quot;http://samples.microsoft.com/ServiceModel/Relay/&quot;)]
class MulticastService : IMulticastContract
{
    void IMulticastContract.Hello(string nickName)
    {
        Console.WriteLine(&quot;[&quot; &#43; nickName &#43; &quot;] joins&quot;);
    }
 
    void IMulticastContract.Chat(string nickName, string text)
    {
        Console.WriteLine(&quot;[&quot; &#43; nickName &#43; &quot;] says: &quot; &#43; text);
    }
 
    void IMulticastContract.Bye(string nickName)
    {
        Console.WriteLine(&quot;[&quot; &#43; nickName &#43; &quot;] leaves&quot;);
    }   
}
</pre>
<div class="preview">
<pre class="csharp">ServiceBehavior(Name&nbsp;=&nbsp;<span class="cs__string">&quot;MulticastService&quot;</span>,&nbsp;Namespace&nbsp;=&nbsp;<span class="cs__string">&quot;http://samples.microsoft.com/ServiceModel/Relay/&quot;</span>)]&nbsp;
<span class="cs__keyword">class</span>&nbsp;MulticastService&nbsp;:&nbsp;IMulticastContract&nbsp;
{&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="cs__keyword">void</span>&nbsp;IMulticastContract.Hello(<span class="cs__keyword">string</span>&nbsp;nickName)&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Console.WriteLine(<span class="cs__string">&quot;[&quot;</span>&nbsp;&#43;&nbsp;nickName&nbsp;&#43;&nbsp;<span class="cs__string">&quot;]&nbsp;joins&quot;</span>);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;
&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="cs__keyword">void</span>&nbsp;IMulticastContract.Chat(<span class="cs__keyword">string</span>&nbsp;nickName,&nbsp;<span class="cs__keyword">string</span>&nbsp;text)&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Console.WriteLine(<span class="cs__string">&quot;[&quot;</span>&nbsp;&#43;&nbsp;nickName&nbsp;&#43;&nbsp;<span class="cs__string">&quot;]&nbsp;says:&nbsp;&quot;</span>&nbsp;&#43;&nbsp;text);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;
&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="cs__keyword">void</span>&nbsp;IMulticastContract.Bye(<span class="cs__keyword">string</span>&nbsp;nickName)&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Console.WriteLine(<span class="cs__string">&quot;[&quot;</span>&nbsp;&#43;&nbsp;nickName&nbsp;&#43;&nbsp;<span class="cs__string">&quot;]&nbsp;leaves&quot;</span>);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;&nbsp;&nbsp;&nbsp;
}&nbsp;
</pre>
</div>
</div>
</div>
</div>
<h1>Configuration</h1>
<div><span style="color:black; font-family:">The service and client endpoints use the
<strong>NetEventRelayBinding</strong> binding. </span></div>
<div>
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>XML</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">xml</span>
<pre class="hidden">&lt;netEventRelayBinding&gt;
     &lt;binding name=&quot;default&quot; /&gt;
&lt;/netEventRelayBinding&gt; 
</pre>
<div class="preview">
<pre class="js">&lt;netEventRelayBinding&gt;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&lt;binding&nbsp;name=<span class="js__string">&quot;default&quot;</span>&nbsp;/&gt;&nbsp;
&lt;/netEventRelayBinding&gt;&nbsp;&nbsp;
</pre>
</div>
</div>
</div>
</div>
<div><span style="color:black; font-family:">The endpoints for the service and client are defined in the application configuration file. The client address is a placeholder that is replaced in the application. The following endpoints are defined:</span></div>
<div>&nbsp;</div>
<div>
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>XML</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">xml</span>
<pre class="hidden">&lt;service name=&quot;Microsoft.ServiceBus.Samples.MulticastService&quot;&gt;
    &lt;endpoint name=&quot;RelayEndpoint&quot;
              contract=&quot;Microsoft.ServiceBus.Samples.IMulticastContract&quot;
              binding=&quot;netEventRelayBinding&quot;
              bindingConfiguration=&quot;default&quot;
              address=&quot;&quot; /&gt;
&lt;/service&gt;
 
&lt;client&gt;
    &lt;endpoint name=&quot;RelayEndpoint&quot;
              contract=&quot;Microsoft.ServiceBus.Samples.IMulticastContract&quot;
              binding=&quot;netTcpRelayBinding&quot;
              bindingConfiguration=&quot;default&quot;
              address=&quot;http://AddressToBeReplacedInCode/&quot; /&gt;
&lt;/client&gt;
</pre>
<div class="preview">
<pre class="js">&lt;service&nbsp;name=<span class="js__string">&quot;Microsoft.ServiceBus.Samples.MulticastService&quot;</span>&gt;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&lt;endpoint&nbsp;name=<span class="js__string">&quot;RelayEndpoint&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;contract=<span class="js__string">&quot;Microsoft.ServiceBus.Samples.IMulticastContract&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;binding=<span class="js__string">&quot;netEventRelayBinding&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;bindingConfiguration=<span class="js__string">&quot;default&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;address=<span class="js__string">&quot;&quot;</span>&nbsp;/&gt;&nbsp;
&lt;/service&gt;&nbsp;
&nbsp;&nbsp;
&lt;client&gt;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&lt;endpoint&nbsp;name=<span class="js__string">&quot;RelayEndpoint&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;contract=<span class="js__string">&quot;Microsoft.ServiceBus.Samples.IMulticastContract&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;binding=<span class="js__string">&quot;netTcpRelayBinding&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;bindingConfiguration=<span class="js__string">&quot;default&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;address=<span class="js__string">&quot;http://AddressToBeReplacedInCode/&quot;</span>&nbsp;/&gt;&nbsp;
&lt;/client&gt;&nbsp;
</pre>
</div>
</div>
</div>
</div>
<h1>Application</h1>
<div><span style="color:black; font-family:">The application begins by obtaining the chat session name, the service namespace, the issuer credentials and a chat nickname (a string used to identify the chatter). The sample constructs the service URI using this
 information, then opens the service and the client channel to the Service Bus rendezvous endpoint for the chat session. The
</span><code><span style="font-size:9pt">Hello</span></code><span style="color:black; font-family:"> method notifies all participating applications of the arrival of a new user. The
</span><code><span style="font-size:9pt">Chat</span></code><span style="color:black; font-family:"> method sends all strings as messages to all participating applications until an empty string is provided as input. At that point the client leaves the chatroom
 and the </span><code><span style="font-size:9pt">Bye</span></code><span style="color:black; font-family:"> method notifies all participants of the client's departure.</span></div>
<div><br>
<br>
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>C#</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">csharp</span>
<pre class="hidden">Console.Write(&quot;What do you want to call your chat session? &quot;);
string session = Console.ReadLine();
Console.Write(&quot;Your Service Namespace: &quot;);
string serviceNamespace = Console.ReadLine();
Console.Write(&quot;Your Issuer Name: &quot;);
string issuerName = Console.ReadLine();
Console.Write(&quot;Your Issuer Secret: &quot;);
string issuerSecret = Console.ReadLine();
Console.Write(&quot;Your Chat Nickname: &quot;);
string chatNickname = Console.ReadLine();
TransportClientEndpointBehavior relayCredentials = new TransportClientEndpointBehavior();
relayCredentials.TokenProvider = TokenProvider.CreateSharedSecretTokenProvider(issuerName, issuerSecret);    

Uri serviceAddress = ServiceBusEnvironment.CreateServiceUri(&quot;sb&quot;, &quot;ChatRooms&quot;,
String.Format(CultureInfo.InvariantCulture, &quot;{0}/MulticastService/&quot;, session));
ServiceHost host = new ServiceHost(typeof(MulticastService), serviceAddress);
host.Description.Endpoints[0].Behaviors.Add(relayCredentials);
host.Open();

ChannelFactory&lt;IMulticastChannel&gt; channelFactory = new ChannelFactory&lt;IMulticastChannel&gt;(&quot;RelayEndpoint&quot;, new EndpointAddress(serviceAddress));
channelFactory.Endpoint.Behaviors.Add(relayCredentials);
IMulticastChannel channel = channelFactory.CreateChannel();
channel.Open();

Console.WriteLine(&quot;\nPress [Enter] to exit\n&quot;);

channel.Hello(chatNickname);

string input = Console.ReadLine();
while (input != String.Empty)
{
   channel.Chat(chatNickname, input);
   input = Console.ReadLine();
}

channel.Bye(chatNickname);

channel.Close();
channelFactory.Close();
host.Close();
</pre>
<div class="preview">
<pre class="js">Console.Write(<span class="js__string">&quot;What&nbsp;do&nbsp;you&nbsp;want&nbsp;to&nbsp;call&nbsp;your&nbsp;chat&nbsp;session?&nbsp;&quot;</span>);&nbsp;
string&nbsp;session&nbsp;=&nbsp;Console.ReadLine();&nbsp;
Console.Write(<span class="js__string">&quot;Your&nbsp;Service&nbsp;Namespace:&nbsp;&quot;</span>);&nbsp;
string&nbsp;serviceNamespace&nbsp;=&nbsp;Console.ReadLine();&nbsp;
Console.Write(<span class="js__string">&quot;Your&nbsp;Issuer&nbsp;Name:&nbsp;&quot;</span>);&nbsp;
string&nbsp;issuerName&nbsp;=&nbsp;Console.ReadLine();&nbsp;
Console.Write(<span class="js__string">&quot;Your&nbsp;Issuer&nbsp;Secret:&nbsp;&quot;</span>);&nbsp;
string&nbsp;issuerSecret&nbsp;=&nbsp;Console.ReadLine();&nbsp;
Console.Write(<span class="js__string">&quot;Your&nbsp;Chat&nbsp;Nickname:&nbsp;&quot;</span>);&nbsp;
string&nbsp;chatNickname&nbsp;=&nbsp;Console.ReadLine();&nbsp;
TransportClientEndpointBehavior&nbsp;relayCredentials&nbsp;=&nbsp;<span class="js__operator">new</span>&nbsp;TransportClientEndpointBehavior();&nbsp;
relayCredentials.TokenProvider&nbsp;=&nbsp;TokenProvider.CreateSharedSecretTokenProvider(issuerName,&nbsp;issuerSecret);&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;
Uri&nbsp;serviceAddress&nbsp;=&nbsp;ServiceBusEnvironment.CreateServiceUri(<span class="js__string">&quot;sb&quot;</span>,&nbsp;<span class="js__string">&quot;ChatRooms&quot;</span>,&nbsp;
<span class="js__object">String</span>.Format(CultureInfo.InvariantCulture,&nbsp;<span class="js__string">&quot;{0}/MulticastService/&quot;</span>,&nbsp;session));&nbsp;
ServiceHost&nbsp;host&nbsp;=&nbsp;<span class="js__operator">new</span>&nbsp;ServiceHost(<span class="js__operator">typeof</span>(MulticastService),&nbsp;serviceAddress);&nbsp;
host.Description.Endpoints[<span class="js__num">0</span>].Behaviors.Add(relayCredentials);&nbsp;
host.Open();&nbsp;
&nbsp;
ChannelFactory&lt;IMulticastChannel&gt;&nbsp;channelFactory&nbsp;=&nbsp;<span class="js__operator">new</span>&nbsp;ChannelFactory&lt;IMulticastChannel&gt;(<span class="js__string">&quot;RelayEndpoint&quot;</span>,&nbsp;<span class="js__operator">new</span>&nbsp;EndpointAddress(serviceAddress));&nbsp;
channelFactory.Endpoint.Behaviors.Add(relayCredentials);&nbsp;
IMulticastChannel&nbsp;channel&nbsp;=&nbsp;channelFactory.CreateChannel();&nbsp;
channel.Open();&nbsp;
&nbsp;
Console.WriteLine(<span class="js__string">&quot;\nPress&nbsp;[Enter]&nbsp;to&nbsp;exit\n&quot;</span>);&nbsp;
&nbsp;
channel.Hello(chatNickname);&nbsp;
&nbsp;
string&nbsp;input&nbsp;=&nbsp;Console.ReadLine();&nbsp;
<span class="js__statement">while</span>&nbsp;(input&nbsp;!=&nbsp;<span class="js__object">String</span>.Empty)&nbsp;
<span class="js__brace">{</span>&nbsp;
&nbsp;&nbsp;&nbsp;channel.Chat(chatNickname,&nbsp;input);&nbsp;
&nbsp;&nbsp;&nbsp;input&nbsp;=&nbsp;Console.ReadLine();&nbsp;
<span class="js__brace">}</span>&nbsp;
&nbsp;
channel.Bye(chatNickname);&nbsp;
&nbsp;
channel.Close();&nbsp;
channelFactory.Close();&nbsp;
host.Close();&nbsp;
</pre>
</div>
</div>
</div>
<div class="endscriptcode">&nbsp;</div>
</div>
<h1>Building and Running the Sample</h1>
<div>
<p>After building the solution, perform the following steps to run the application:</p>
<ol>
<li>From a command prompt, run the application bin\Debug\MulticastSample.exe. </li><li>From another command prompt, run another instance of the application bin\Debug\MulticastSample.exe.
</li></ol>
<p>When finished, press ENTER to exit the application.</p>
<p>&nbsp;</p>
<h2><strong>Expected Output &ndash; Application 1</strong></h2>
<p>What do you want to call your chat session? &lt;chat-session&gt;<br>
Your Service Namespace: &lt;service-namespace&gt;<br>
Your Issuer Name: owner<br>
Your Issuer Secret: &lt;issuer-secret&gt;<br>
Your Chat Nickname: &lt;chat-nickname&gt;</p>
<p>Press [Enter] to exit</p>
<p>[jill] joins<br>
hello<br>
[jill] says: hello<br>
[jack] says: hi, how are you?<br>
[jack] says: who do you think will win the superbowl this year?</p>
</div>
<div>&nbsp;</div>
<h2>Expected Output &ndash; Application 2</h2>
<p>What do you want to call your chat session? &lt;chat-session&gt;<br>
Your Service Namespace: &lt;service-namespace&gt;<br>
Your Issuer Name: owner<br>
Your Issuer Secret: &lt;issuer-secret&gt;<br>
Your Chat Nickname: &lt;chat-nickname&gt;</p>
<p>Press [Enter] to exit</p>
<p>[jack] joins<br>
[jill] joins<br>
[jill] says: hello<br>
hi, how are you?<br>
[jack] says: hi, how are you?<br>
who do you think will win the superbowl this year?<br>
[jack] says: who do you think will win the superbowl this year?</p>
<div><br>
<br>
</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div><br>
<br>
&nbsp;</div>
<div></div>
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
<div></div>
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
<div><br>
<br>
&nbsp;</div>
