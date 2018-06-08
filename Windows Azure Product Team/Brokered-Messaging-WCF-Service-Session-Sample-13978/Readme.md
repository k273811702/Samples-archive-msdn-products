# Brokered Messaging: WCF Service Session Sample
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
* 2014-08-14 01:00:45
## Description

<h1>Introduction</h1>
<div>This sample demonstrates how to use the Windows Azure Service Bus using the WCF service model.</div>
<div><br>
The sample shows the use of the WCF service model to accomplish session-based communication via a Service Bus queue. The sample demonstrates this using an order service scenario. In the scenario, different customers send orders to the order service. All the
 order items are grouped together in a single session using a customer Id. The service creates a new instance for each session to process all related messages. The service prints out the total items ordered by the customer. Once the service has processed all
 the messages it closes the instance.</div>
<div>&nbsp;</div>
<div>The sample prompts for service namespace credentials for the purpose of creating and deleting the queues. Authentication is done via a token that is signed with a Shared Access Signature (SAS) key. The&nbsp;client and service use the credentials defined
 in the config file.</div>
<div>&nbsp;</div>
<h1>Prerequisites</h1>
<div><br>
If you haven't already done so, please read the release notes document that explains how to sign up for a Windows Azure account and how to configure your environment.</div>
<div>&nbsp;</div>
<h1>Configuring the Sample</h1>
<div><br>
When the solution is opened in Visual Studio, update &lt;behaviors&gt; and &lt;client&gt; sections in the App.config file of the Client project. Also, update the &lt;behaviors&gt; and &lt;services&gt; sections in the App.config file of the OrderService project.</div>
<div><br>
The value for 'keyName' and &lsquo;key&rsquo; should be available upon signup for a Windows Azure account and upon configuring your environment. Please read the release notes for details.</div>
<div><br>
The vaule for &lsquo;address&rsquo; in the &lt;client&gt; and &lt;services&gt; section is a Service Bus Uri that points to the queue entity. The Uri should be of type sb://&lt;ServiceBus Namespace&gt;.servicebus.windows.net/OrderQueue where the &lsquo;OrderQueue&rsquo;
 is the entity name. Note that the Uri scheme &lsquo;sb&rsquo; is mandatory for all runtime operations such as send/receive.</div>
<div>&nbsp;</div>
<div><strong>Client App.Config </strong></div>
<div><span style="font-family:Consolas; font-size:x-small"><span style="font-family:Consolas; font-size:x-small">&nbsp;</span></span></div>
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>XML</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">xml</span>
<pre class="hidden">&lt;behaviors&gt;
  &lt;endpointBehaviors&gt;
    &lt;behavior name=&quot;securityBehavior&quot;&gt;
      &lt;transportClientEndpointBehavior&gt;
        &lt;tokenProvider&gt;
          &lt;sharedAccessSignature keyName=&quot;RootManageSharedAccessKey&quot; key=&quot;XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX=&quot; /&gt;
        &lt;/tokenProvider&gt;
      &lt;/transportClientEndpointBehavior&gt;
    &lt;/behavior&gt;
  &lt;/endpointBehaviors&gt;
&lt;/behaviors&gt;

&lt;client&gt;
  &lt;endpoint name=&quot;orderSendClient&quot;
            address=&quot;sb://[ServiceBus Namespace].servicebus.windows.net/OrderQueue&quot;
            contract=&quot;Microsoft.Samples.SessionMessages.IOrderServiceContract&quot;
            binding=&quot;netMessagingBinding&quot; bindingConfiguration=&quot;messagingBinding&quot;
            behaviorConfiguration=&quot;securityBehavior&quot;/&gt;
&lt;/client&gt;
</pre>
<div class="preview">
<pre class="xml"><span class="xml__tag_start">&lt;behaviors</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;<span class="xml__tag_start">&lt;endpointBehaviors</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;behavior</span>&nbsp;<span class="xml__attr_name">name</span>=<span class="xml__attr_value">&quot;securityBehavior&quot;</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;transportClientEndpointBehavior</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;tokenProvider</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;sharedAccessSignature</span>&nbsp;<span class="xml__attr_name">keyName</span>=<span class="xml__attr_value">&quot;RootManageSharedAccessKey&quot;</span>&nbsp;<span class="xml__attr_name">key</span>=<span class="xml__attr_value">&quot;XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX=&quot;</span>&nbsp;<span class="xml__tag_start">/&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/tokenProvider&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/transportClientEndpointBehavior&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/behavior&gt;</span>&nbsp;
&nbsp;&nbsp;<span class="xml__tag_end">&lt;/endpointBehaviors&gt;</span>&nbsp;
<span class="xml__tag_end">&lt;/behaviors&gt;</span>&nbsp;
&nbsp;
<span class="xml__tag_start">&lt;client</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;<span class="xml__tag_start">&lt;endpoint</span>&nbsp;<span class="xml__attr_name">name</span>=<span class="xml__attr_value">&quot;orderSendClient&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__attr_name">address</span>=<span class="xml__attr_value">&quot;sb://[ServiceBus&nbsp;Namespace].servicebus.windows.net/OrderQueue&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__attr_name">contract</span>=<span class="xml__attr_value">&quot;Microsoft.Samples.SessionMessages.IOrderServiceContract&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__attr_name">binding</span>=<span class="xml__attr_value">&quot;netMessagingBinding&quot;</span>&nbsp;<span class="xml__attr_name">bindingConfiguration</span>=<span class="xml__attr_value">&quot;messagingBinding&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__attr_name">behaviorConfiguration</span>=<span class="xml__attr_value">&quot;securityBehavior&quot;</span><span class="xml__tag_start">/&gt;</span>&nbsp;
<span class="xml__tag_end">&lt;/client&gt;</span>&nbsp;
</pre>
</div>
</div>
</div>
<div><strong>OrderService App.Config&nbsp;</strong>&nbsp;</div>
<div>&nbsp;</div>
<div>
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>XML</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">xml</span>
<pre class="hidden">&lt;behaviors&gt;
  &lt;endpointBehaviors&gt;
    &lt;behavior name=&quot;securityBehavior&quot;&gt;
      &lt;transportClientEndpointBehavior&gt;
        &lt;tokenProvider&gt;
          &lt;sharedAccessSignature keyName=&quot;RootManageSharedAccessKey&quot; key=&quot;XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX=&quot; /&gt;        &lt;/tokenProvider&gt;
      &lt;/transportClientEndpointBehavior&gt;
    &lt;/behavior&gt;
  &lt;/endpointBehaviors&gt;
&lt;/behaviors&gt;

&lt;services&gt;
  &lt;service name=&quot;Microsoft.Samples.SessionMessages.OrderService&quot;&gt;
    &lt;endpoint name=&quot;SessionServiceEndPoint&quot;
                address=&quot;sb://[ServiceBus Namespace].servicebus.windows.net/OrderQueue&quot;
                binding=&quot;netMessagingBinding&quot; bindingConfiguration=&quot;messagingBinding&quot;
                contract=&quot;Microsoft.Samples.SessionMessages.IOrderServiceContractSessionful&quot;
                behaviorConfiguration=&quot;securityBehavior&quot; /&gt;
  &lt;/service&gt;
&lt;/services&gt;</pre>
<div class="preview">
<pre class="xml"><span class="xml__tag_start">&lt;behaviors</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;<span class="xml__tag_start">&lt;endpointBehaviors</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;behavior</span>&nbsp;<span class="xml__attr_name">name</span>=<span class="xml__attr_value">&quot;securityBehavior&quot;</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;transportClientEndpointBehavior</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;tokenProvider</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;sharedAccessSignature</span>&nbsp;<span class="xml__attr_name">keyName</span>=<span class="xml__attr_value">&quot;RootManageSharedAccessKey&quot;</span>&nbsp;<span class="xml__attr_name">key</span>=<span class="xml__attr_value">&quot;XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX=&quot;</span>&nbsp;<span class="xml__tag_start">/&gt;</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/tokenProvider&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/transportClientEndpointBehavior&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/behavior&gt;</span>&nbsp;
&nbsp;&nbsp;<span class="xml__tag_end">&lt;/endpointBehaviors&gt;</span>&nbsp;
<span class="xml__tag_end">&lt;/behaviors&gt;</span>&nbsp;
&nbsp;
<span class="xml__tag_start">&lt;services</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;<span class="xml__tag_start">&lt;service</span>&nbsp;<span class="xml__attr_name">name</span>=<span class="xml__attr_value">&quot;Microsoft.Samples.SessionMessages.OrderService&quot;</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;endpoint</span>&nbsp;<span class="xml__attr_name">name</span>=<span class="xml__attr_value">&quot;SessionServiceEndPoint&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__attr_name">address</span>=<span class="xml__attr_value">&quot;sb://[ServiceBus&nbsp;Namespace].servicebus.windows.net/OrderQueue&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__attr_name">binding</span>=<span class="xml__attr_value">&quot;netMessagingBinding&quot;</span>&nbsp;<span class="xml__attr_name">bindingConfiguration</span>=<span class="xml__attr_value">&quot;messagingBinding&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__attr_name">contract</span>=<span class="xml__attr_value">&quot;Microsoft.Samples.SessionMessages.IOrderServiceContractSessionful&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__attr_name">behaviorConfiguration</span>=<span class="xml__attr_value">&quot;securityBehavior&quot;</span>&nbsp;<span class="xml__tag_start">/&gt;</span>&nbsp;
&nbsp;&nbsp;<span class="xml__tag_end">&lt;/service&gt;</span>&nbsp;
<span class="xml__tag_end">&lt;/services&gt;</span></pre>
</div>
</div>
</div>
<h1 class="endscriptcode">Configuration File</h1>
<div><br>
The sender and receiver use NetMessagingBinding which is defined in their respective App.config files. NetMessagingBinding uses BinaryMessageEncoding as its encoder and NetMessagingTransportBindingElement as its transport. The TransportSettings property, which
 is a part of the transport element, represents the runtime factory used by the Service Bus. An extension section is required be added to the configuration file in order to use Service Bus components with WCF.</div>
<div>&nbsp;</div>
<div>In addition to the binding, both the configuration files have a &lt;behaviors&gt; section which defines TransportClientEndpointBehavior. Service Bus credentials are passed to the client and service via this endpoint behavior.</div>
<div>&nbsp;</div>
<div><strong>App.Config - Config Extensions and Binding</strong></div>
<div>
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>XML</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">xml</span>
<pre class="hidden">&lt;extensions&gt;
  &lt;bindingElementExtensions&gt;
    &lt;add name=&quot;netMessagingTransport&quot; type=&quot;Microsoft.ServiceBus.Messaging.Configuration.NetMessagingTransportExtensionElement, Microsoft.ServiceBus, Version=2.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35&quot; /&gt;
  &lt;/bindingElementExtensions&gt;
  &lt;bindingExtensions&gt;
    &lt;add name=&quot;netMessagingBinding&quot; type=&quot;Microsoft.ServiceBus.Messaging.Configuration.NetMessagingBindingCollectionElement, Microsoft.ServiceBus, Version=2.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35&quot; /&gt;
  &lt;/bindingExtensions&gt;
&lt;/extensions&gt;

&lt;bindings&gt;
  &lt;netMessagingBinding&gt;
    &lt;binding name=&quot;messagingBinding&quot; sendTimeout=&quot;00:03:00&quot; receiveTimeout=&quot;00:03:00&quot; openTimeout=&quot;00:03:00&quot; closeTimeout=&quot;00:03:00&quot;&gt;
    &lt;/binding&gt;
  &lt;/netMessagingBinding&gt;
&lt;/bindings&gt;</pre>
<div class="preview">
<pre class="xml"><span class="xml__tag_start">&lt;extensions</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;<span class="xml__tag_start">&lt;bindingElementExtensions</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;add</span>&nbsp;<span class="xml__attr_name">name</span>=<span class="xml__attr_value">&quot;netMessagingTransport&quot;</span>&nbsp;<span class="xml__attr_name">type</span>=<span class="xml__attr_value">&quot;Microsoft.ServiceBus.Messaging.Configuration.NetMessagingTransportExtensionElement,&nbsp;Microsoft.ServiceBus,&nbsp;Version=2.0.0.0,&nbsp;Culture=neutral,&nbsp;PublicKeyToken=31bf3856ad364e35&quot;</span>&nbsp;<span class="xml__tag_start">/&gt;</span>&nbsp;
&nbsp;&nbsp;<span class="xml__tag_end">&lt;/bindingElementExtensions&gt;</span>&nbsp;
&nbsp;&nbsp;<span class="xml__tag_start">&lt;bindingExtensions</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;add</span>&nbsp;<span class="xml__attr_name">name</span>=<span class="xml__attr_value">&quot;netMessagingBinding&quot;</span>&nbsp;<span class="xml__attr_name">type</span>=<span class="xml__attr_value">&quot;Microsoft.ServiceBus.Messaging.Configuration.NetMessagingBindingCollectionElement,&nbsp;Microsoft.ServiceBus,&nbsp;Version=2.0.0.0,&nbsp;Culture=neutral,&nbsp;PublicKeyToken=31bf3856ad364e35&quot;</span>&nbsp;<span class="xml__tag_start">/&gt;</span>&nbsp;
&nbsp;&nbsp;<span class="xml__tag_end">&lt;/bindingExtensions&gt;</span>&nbsp;
<span class="xml__tag_end">&lt;/extensions&gt;</span>&nbsp;
&nbsp;
<span class="xml__tag_start">&lt;bindings</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;<span class="xml__tag_start">&lt;netMessagingBinding</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;binding</span>&nbsp;<span class="xml__attr_name">name</span>=<span class="xml__attr_value">&quot;messagingBinding&quot;</span>&nbsp;<span class="xml__attr_name">sendTimeout</span>=<span class="xml__attr_value">&quot;00:03:00&quot;</span>&nbsp;<span class="xml__attr_name">receiveTimeout</span>=<span class="xml__attr_value">&quot;00:03:00&quot;</span>&nbsp;<span class="xml__attr_name">openTimeout</span>=<span class="xml__attr_value">&quot;00:03:00&quot;</span>&nbsp;<span class="xml__attr_name">closeTimeout</span>=<span class="xml__attr_value">&quot;00:03:00&quot;</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/binding&gt;</span>&nbsp;
&nbsp;&nbsp;<span class="xml__tag_end">&lt;/netMessagingBinding&gt;</span>&nbsp;
<span class="xml__tag_end">&lt;/bindings&gt;</span></pre>
</div>
</div>
</div>
<div class="endscriptcode">&nbsp;</div>
In the config files, NetMessagingBinding exposes SessionIdleTimeOut, PrefetchCount, and BatchFlushInterval. The SessionIdleTimeOut property allows the Service Bus dispatcher to close an instance of the service if it is idle for more than the specified time
 interval. The default value for SessionIdleTimeout is 1 minute. BatchFlushInterval is responsible for implicitly batching the send operation or the complete operation. The Service Bus implicitly batches the send operation from sender or complete operation
 from receiver for the specified time to avoid multiple round-trips. The default value of BatchFlushInterval is 20 milliseconds.</div>
<div>The client configuration file defines the client object and the service configuration file defines the service object.</div>
<div>&nbsp;</div>
<div><strong>App.Config - Client and Service Definition</strong></div>
<div>
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>XML</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">xml</span>
<pre class="hidden">&lt;client&gt;
  &lt;endpoint name=&quot;orderSendClient&quot;
            address=&quot;[Enter Endpoint address]&quot;
            contract=&quot;Microsoft.Samples.SessionMessages.IOrderServiceContract&quot;
            binding=&quot;netMessagingBinding&quot; bindingConfiguration=&quot;messagingBinding&quot;
            behaviorConfiguration=&quot;securityBehavior&quot;/&gt;
&lt;/client&gt;

&lt;services&gt;
  &lt;service name=&quot;Microsoft.Samples.SessionMessages.OrderService&quot;&gt;
    &lt;endpoint name=&quot;SessionServiceEndPoint&quot;
                address=&quot;[Enter Endpoint address]&quot;
                binding=&quot;netMessagingBinding&quot; bindingConfiguration=&quot;messagingBinding&quot;
                contract=&quot;Microsoft.Samples.SessionMessages.IOrderServiceContractSessionful&quot;
                behaviorConfiguration=&quot;securityBehavior&quot; /&gt;
  &lt;/service&gt;
&lt;/services&gt;</pre>
<div class="preview">
<pre class="js">&lt;client&gt;&nbsp;
&nbsp;&nbsp;&lt;endpoint&nbsp;name=<span class="js__string">&quot;orderSendClient&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;address=<span class="js__string">&quot;[Enter&nbsp;Endpoint&nbsp;address]&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;contract=<span class="js__string">&quot;Microsoft.Samples.SessionMessages.IOrderServiceContract&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;binding=<span class="js__string">&quot;netMessagingBinding&quot;</span>&nbsp;bindingConfiguration=<span class="js__string">&quot;messagingBinding&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;behaviorConfiguration=<span class="js__string">&quot;securityBehavior&quot;</span>/&gt;&nbsp;
&lt;/client&gt;&nbsp;
&nbsp;
&lt;services&gt;&nbsp;
&nbsp;&nbsp;&lt;service&nbsp;name=<span class="js__string">&quot;Microsoft.Samples.SessionMessages.OrderService&quot;</span>&gt;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&lt;endpoint&nbsp;name=<span class="js__string">&quot;SessionServiceEndPoint&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;address=<span class="js__string">&quot;[Enter&nbsp;Endpoint&nbsp;address]&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;binding=<span class="js__string">&quot;netMessagingBinding&quot;</span>&nbsp;bindingConfiguration=<span class="js__string">&quot;messagingBinding&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;contract=<span class="js__string">&quot;Microsoft.Samples.SessionMessages.IOrderServiceContractSessionful&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;behaviorConfiguration=<span class="js__string">&quot;securityBehavior&quot;</span>&nbsp;/&gt;&nbsp;
&nbsp;&nbsp;&lt;/service&gt;&nbsp;
&lt;/services&gt;</pre>
</div>
</div>
</div>
</div>
<div><br>
The client configuration file defines the client object and the service configuration file defines the service object.</div>
<div>&nbsp;</div>
<h1>Credentials</h1>
<div><br>
The sample obtains user credentials and creates a NamespaceManager object. This entity holds the credentials and is used for all messaging management operations - in this case, to create and delete queues.</div>
</div>
<div>&nbsp;</div>
<div>&nbsp;
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>C#</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">csharp</span>
<pre class="hidden"> public static void GetUserCredentials()
    {
        // User namespace
        Console.Write(&quot;Please provide the namespace: &quot;);
        serviceBusNamespace = Console.ReadLine();

        // Issuer name
        Console.Write(&quot;Please provide the key name (e.g., \&quot;RootManageSharedAccessKey\&quot;): &quot;);
        serviceBusKeyName = Console.ReadLine();

        // Issuer key
        Console.Write(&quot;Please provide the key: &quot;);
        serviceBusKey = Console.ReadLine();
    }

    // Create the NamespaceManager for management operations (queue)
    static void CreateNamespaceManager()
    {
        // Create SAS token provider.
        TokenProvider credentials = TokenProvider.CreateSharedAccessSignatureTokenProvider(serviceBusKeyName, serviceBusKey);
        // Create the management Uri
        Uri managementUri = ServiceBusEnvironment.CreateServiceUri(&quot;sb&quot;, serviceBusNamespace, string.Empty);
        namespaceManager = new NamespaceManager(managementUri, credentials);
    }

    // Create the entity (queue)
    static QueueDescription CreateQueue(bool session)
    {
        QueueDescription queueDescription = new QueueDescription(orderQueueName) { RequiresSession = session };

        // Try deleting the queue before creation. Ignore exception if queue does not exist.
        try
        {
            namespaceManager.DeleteQueue(orderQueueName);
        }
        catch (MessagingEntityNotFoundException)
        {
        }

        return namespaceManager.CreateQueue(queueDescription);
    }</pre>
<div class="preview">
<pre class="csharp">&nbsp;<span class="cs__keyword">public</span>&nbsp;<span class="cs__keyword">static</span>&nbsp;<span class="cs__keyword">void</span>&nbsp;GetUserCredentials()&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="cs__com">//&nbsp;User&nbsp;namespace</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Console.Write(<span class="cs__string">&quot;Please&nbsp;provide&nbsp;the&nbsp;namespace:&nbsp;&quot;</span>);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;serviceBusNamespace&nbsp;=&nbsp;Console.ReadLine();&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="cs__com">//&nbsp;Issuer&nbsp;name</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Console.Write(<span class="cs__string">&quot;Please&nbsp;provide&nbsp;the&nbsp;key&nbsp;name&nbsp;(e.g.,&nbsp;\&quot;RootManageSharedAccessKey\&quot;):&nbsp;&quot;</span>);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;serviceBusKeyName&nbsp;=&nbsp;Console.ReadLine();&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="cs__com">//&nbsp;Issuer&nbsp;key</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Console.Write(<span class="cs__string">&quot;Please&nbsp;provide&nbsp;the&nbsp;key:&nbsp;&quot;</span>);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;serviceBusKey&nbsp;=&nbsp;Console.ReadLine();&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="cs__com">//&nbsp;Create&nbsp;the&nbsp;NamespaceManager&nbsp;for&nbsp;management&nbsp;operations&nbsp;(queue)</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="cs__keyword">static</span>&nbsp;<span class="cs__keyword">void</span>&nbsp;CreateNamespaceManager()&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="cs__com">//&nbsp;Create&nbsp;SAS&nbsp;token&nbsp;provider.</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;TokenProvider&nbsp;credentials&nbsp;=&nbsp;TokenProvider.CreateSharedAccessSignatureTokenProvider(serviceBusKeyName,&nbsp;serviceBusKey);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="cs__com">//&nbsp;Create&nbsp;the&nbsp;management&nbsp;Uri</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Uri&nbsp;managementUri&nbsp;=&nbsp;ServiceBusEnvironment.CreateServiceUri(<span class="cs__string">&quot;sb&quot;</span>,&nbsp;serviceBusNamespace,&nbsp;<span class="cs__keyword">string</span>.Empty);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;namespaceManager&nbsp;=&nbsp;<span class="cs__keyword">new</span>&nbsp;NamespaceManager(managementUri,&nbsp;credentials);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="cs__com">//&nbsp;Create&nbsp;the&nbsp;entity&nbsp;(queue)</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="cs__keyword">static</span>&nbsp;QueueDescription&nbsp;CreateQueue(<span class="cs__keyword">bool</span>&nbsp;session)&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;QueueDescription&nbsp;queueDescription&nbsp;=&nbsp;<span class="cs__keyword">new</span>&nbsp;QueueDescription(orderQueueName)&nbsp;{&nbsp;RequiresSession&nbsp;=&nbsp;session&nbsp;};&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="cs__com">//&nbsp;Try&nbsp;deleting&nbsp;the&nbsp;queue&nbsp;before&nbsp;creation.&nbsp;Ignore&nbsp;exception&nbsp;if&nbsp;queue&nbsp;does&nbsp;not&nbsp;exist.</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="cs__keyword">try</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;namespaceManager.DeleteQueue(orderQueueName);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="cs__keyword">catch</span>&nbsp;(MessagingEntityNotFoundException)&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;{&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;}&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="cs__keyword">return</span>&nbsp;namespaceManager.CreateQueue(queueDescription);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;}</pre>
</div>
</div>
</div>
<div class="endscriptcode">&nbsp;</div>
<div><br>
The preceding code prompts for the issuer credential and then constructs the listening URI using that information. The static ServiceBusEnvironment.CreateServiceUri function is provided to help construct the URI with the correct format and domain name. It is
 strongly recommended that you use this function instead of building the URI from scratch because the URI construction logic and format might change in future releases. At present, the resulting URI is scheme://&lt;service-namespace&gt;.servicebus.windows.net/.</div>
<div>&nbsp;</div>
<div>The CreateNamespaceManager() function creates the object to perform management operations, in this case creating and deleting queues. Both &lsquo;https&rsquo; and &lsquo;sb&rsquo; Uri schemes are allowed as a part of service Uri.</div>
<div>The CreateQueue(bool session) function creates a queue with the RequireSession property set as per the argument passed.</div>
<div>&nbsp;</div>
<h1>Data Contract</h1>
<div><br>
The sample uses an OrderItem data contract to communicate between client and service. This data contract has two data members: ProductId and Quantity.</div>
<div>&nbsp;</div>
<div>
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>C#</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">csharp</span>
<pre class="hidden">    [DataContract(Name = &quot;OrderDataContract&quot;, Namespace = &quot;Microsoft.Samples.SessionMessages&quot;)]
    public class OrderItem
    {
        [DataMember]
        public string ProductId;

        [DataMember]
        public int Quantity;

        public OrderItem(string productId)
            : this(productId, 1)
        {
        }

        public OrderItem(string productId, int quantity)
        {
            this.ProductId = productId;
            this.Quantity = quantity;
        }
    }
</pre>
<div class="preview">
<pre class="js">&nbsp;&nbsp;&nbsp;&nbsp;[DataContract(Name&nbsp;=&nbsp;<span class="js__string">&quot;OrderDataContract&quot;</span>,&nbsp;Namespace&nbsp;=&nbsp;<span class="js__string">&quot;Microsoft.Samples.SessionMessages&quot;</span>)]&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;public&nbsp;class&nbsp;OrderItem&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">{</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[DataMember]&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;public&nbsp;string&nbsp;ProductId;&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[DataMember]&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;public&nbsp;int&nbsp;Quantity;&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;public&nbsp;OrderItem(string&nbsp;productId)&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;:&nbsp;<span class="js__operator">this</span>(productId,&nbsp;<span class="js__num">1</span>)&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">{</span><span class="js__brace">}</span>&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;public&nbsp;OrderItem(string&nbsp;productId,&nbsp;int&nbsp;quantity)&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">{</span><span class="js__operator">this</span>.ProductId&nbsp;=&nbsp;productId;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__operator">this</span>.Quantity&nbsp;=&nbsp;quantity;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">}</span><span class="js__brace">}</span></pre>
</div>
</div>
</div>
</div>
<h1>Client</h1>
<div><br>
The Service Bus only supports IOutputChannel for sending messages using NetMessagingBinding. To accomplish sessionful communication over NetMessagingBinding the BrokeredMessageProperty.SessionId must be set to the the desired session value. All the messages
 with the same SessionId are grouped together in a single session. This property is required to be set for session-based communication and is optional for non-session communication. The lifetime of a session is based on the SessionIdleTimeout property as discussed
 above.</div>
<div>&nbsp;</div>
<div>In this sample the clients or customers create orders and send it to the order service. The order message that is sent has the SessionId property set to the customer Id. The client is defined in its App.config file.</div>
<div>&nbsp;</div>
<div>
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>C#</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">csharp</span>
<pre class="hidden">    static void Main(string[] args)
    {
        ParseArgs(args);

        // Send messages to queue which does not require session
        Console.Title = &quot;Order Client&quot;;

        // Create sender to Order Service
        ChannelFactory&lt;IOrderServiceContract&gt; sendChannelFactory = new ChannelFactory&lt;IOrderServiceContract&gt;(SampleManager.OrderSendClientConfigName);
        IOrderServiceContract clientChannel = sendChannelFactory.CreateChannel();
        ((IChannel)clientChannel).Open();

        // Send messages
        orderQuantity = new Random().Next(10, 30);
        Console.WriteLine(&quot;Sending {0} messages to {1}...&quot;, orderQuantity, SampleManager.OrderQueueName);
        PlaceOrder(clientChannel);

        // Close sender
        ((IChannel)clientChannel).Close();
        sendChannelFactory.Close();

        Console.WriteLine(&quot;\nSender complete.&quot;);
        Console.WriteLine(&quot;\nPress [Enter] to exit.&quot;);
        Console.ReadLine();
    }

    static void PlaceOrder(IOrderServiceContract clientChannel)
    {
        // Send messages to queue which requires session:
        for (int i = 0; i &lt; orderQuantity; i&#43;&#43;)
        {
            using (OperationContextScope scope = new OperationContextScope((IContextChannel)clientChannel))
            {
                OrderItem orderItem = RandomizeOrder();

                // Assign the session name
                BrokeredMessageProperty property = new BrokeredMessageProperty();

                // Correlating ServiceBus SessionId to CustomerId 
                property.SessionId = customerId;

                // Add BrokeredMessageProperty to the OutgoingMessageProperties bag to pass on the session information 
                OperationContext.Current.OutgoingMessageProperties.Add(BrokeredMessageProperty.Name, property);
                clientChannel.Order(orderItem);
                SampleManager.OutputMessageInfo(&quot;Order&quot;, string.Format(&quot;{0} [{1}]&quot;, orderItem.ProductId, orderItem.Quantity), customerId);
                Thread.Sleep(200);
            }
        }
    }

    private static OrderItem RandomizeOrder()
    {
        // Generating a random order
        string productId = SampleManager.Products[new Random().Next(0, 6)];
        int quantity = new Random().Next(1, 100);
        return new OrderItem(productId, quantity);
    }

    static void ParseArgs(string[] args)
    {
        if (args.Length != 1)
        {
            // Customer Id is needed to identify the sender
            customerId = new Random().Next(1, 7).ToString();
        }
        else
        {
            customerId = args[0];
        }
    } 
</pre>
<div class="preview">
<pre class="js">&nbsp;&nbsp;&nbsp;&nbsp;static&nbsp;<span class="js__operator">void</span>&nbsp;Main(string[]&nbsp;args)&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">{</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ParseArgs(args);&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__sl_comment">//&nbsp;Send&nbsp;messages&nbsp;to&nbsp;queue&nbsp;which&nbsp;does&nbsp;not&nbsp;require&nbsp;session</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Console.Title&nbsp;=&nbsp;<span class="js__string">&quot;Order&nbsp;Client&quot;</span>;&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__sl_comment">//&nbsp;Create&nbsp;sender&nbsp;to&nbsp;Order&nbsp;Service</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ChannelFactory&lt;IOrderServiceContract&gt;&nbsp;sendChannelFactory&nbsp;=&nbsp;<span class="js__operator">new</span>&nbsp;ChannelFactory&lt;IOrderServiceContract&gt;(SampleManager.OrderSendClientConfigName);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;IOrderServiceContract&nbsp;clientChannel&nbsp;=&nbsp;sendChannelFactory.CreateChannel();&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;((IChannel)clientChannel).Open();&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__sl_comment">//&nbsp;Send&nbsp;messages</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;orderQuantity&nbsp;=&nbsp;<span class="js__operator">new</span>&nbsp;Random().Next(<span class="js__num">10</span>,&nbsp;<span class="js__num">30</span>);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Console.WriteLine(<span class="js__string">&quot;Sending&nbsp;{0}&nbsp;messages&nbsp;to&nbsp;{1}...&quot;</span>,&nbsp;orderQuantity,&nbsp;SampleManager.OrderQueueName);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;PlaceOrder(clientChannel);&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__sl_comment">//&nbsp;Close&nbsp;sender</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;((IChannel)clientChannel).Close();&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;sendChannelFactory.Close();&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Console.WriteLine(<span class="js__string">&quot;\nSender&nbsp;complete.&quot;</span>);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Console.WriteLine(<span class="js__string">&quot;\nPress&nbsp;[Enter]&nbsp;to&nbsp;exit.&quot;</span>);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Console.ReadLine();&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">}</span>&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;static&nbsp;<span class="js__operator">void</span>&nbsp;PlaceOrder(IOrderServiceContract&nbsp;clientChannel)&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">{</span><span class="js__sl_comment">//&nbsp;Send&nbsp;messages&nbsp;to&nbsp;queue&nbsp;which&nbsp;requires&nbsp;session:</span><span class="js__statement">for</span>&nbsp;(int&nbsp;i&nbsp;=&nbsp;<span class="js__num">0</span>;&nbsp;i&nbsp;&lt;&nbsp;orderQuantity;&nbsp;i&#43;&#43;)&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">{</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;using&nbsp;(OperationContextScope&nbsp;scope&nbsp;=&nbsp;<span class="js__operator">new</span>&nbsp;OperationContextScope((IContextChannel)clientChannel))&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">{</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;OrderItem&nbsp;orderItem&nbsp;=&nbsp;RandomizeOrder();&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__sl_comment">//&nbsp;Assign&nbsp;the&nbsp;session&nbsp;name</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;BrokeredMessageProperty&nbsp;property&nbsp;=&nbsp;<span class="js__operator">new</span>&nbsp;BrokeredMessageProperty();&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__sl_comment">//&nbsp;Correlating&nbsp;ServiceBus&nbsp;SessionId&nbsp;to&nbsp;CustomerId&nbsp;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;property.SessionId&nbsp;=&nbsp;customerId;&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__sl_comment">//&nbsp;Add&nbsp;BrokeredMessageProperty&nbsp;to&nbsp;the&nbsp;OutgoingMessageProperties&nbsp;bag&nbsp;to&nbsp;pass&nbsp;on&nbsp;the&nbsp;session&nbsp;information&nbsp;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;OperationContext.Current.OutgoingMessageProperties.Add(BrokeredMessageProperty.Name,&nbsp;property);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;clientChannel.Order(orderItem);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SampleManager.OutputMessageInfo(<span class="js__string">&quot;Order&quot;</span>,&nbsp;string.Format(<span class="js__string">&quot;{0}&nbsp;[{1}]&quot;</span>,&nbsp;orderItem.ProductId,&nbsp;orderItem.Quantity),&nbsp;customerId);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Thread.Sleep(<span class="js__num">200</span>);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">}</span><span class="js__brace">}</span><span class="js__brace">}</span>&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;private&nbsp;static&nbsp;OrderItem&nbsp;RandomizeOrder()&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">{</span><span class="js__sl_comment">//&nbsp;Generating&nbsp;a&nbsp;random&nbsp;order</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;string&nbsp;productId&nbsp;=&nbsp;SampleManager.Products[<span class="js__operator">new</span>&nbsp;Random().Next(<span class="js__num">0</span>,&nbsp;<span class="js__num">6</span>)];&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;int&nbsp;quantity&nbsp;=&nbsp;<span class="js__operator">new</span>&nbsp;Random().Next(<span class="js__num">1</span>,&nbsp;<span class="js__num">100</span>);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__statement">return</span><span class="js__operator">new</span>&nbsp;OrderItem(productId,&nbsp;quantity);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">}</span>&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;static&nbsp;<span class="js__operator">void</span>&nbsp;ParseArgs(string[]&nbsp;args)&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">{</span><span class="js__statement">if</span>&nbsp;(args.Length&nbsp;!=&nbsp;<span class="js__num">1</span>)&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">{</span><span class="js__sl_comment">//&nbsp;Customer&nbsp;Id&nbsp;is&nbsp;needed&nbsp;to&nbsp;identify&nbsp;the&nbsp;sender</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;customerId&nbsp;=&nbsp;<span class="js__operator">new</span>&nbsp;Random().Next(<span class="js__num">1</span>,&nbsp;<span class="js__num">7</span>).ToString();&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">}</span><span class="js__statement">else</span><span class="js__brace">{</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;customerId&nbsp;=&nbsp;args[<span class="js__num">0</span>];&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">}</span><span class="js__brace">}</span></pre>
</div>
</div>
</div>
</div>
<h1>Service</h1>
<div><br>
The sample illustrates an order service as described above. The OrderService implements IOrderServiceContractSessionful operation contract which implements IOrderServiceContract. Because the Service Bus does not support IOutputSessionChannel, all senders sending
 messages to session-based queues must use a contract which does not enforce SessionMode.Required. However, Service Bus supports IInputSessionChannel and so the service implements the sessionful contract. The operation attribute ReceiveContextEnabled is set
 with manual control set to true. This requires an explicit ReceiveContext.Complete operation to be performed for every message received. The service has ServiceBehavior.InstanceContextMode set to per-session. The ServiceHost will create a new instance every
 time a new session is available in the queue. The life-time of the instance is controlled by setting the SessionIdleTimeout property of the binding.</div>
<div>&nbsp;</div>
<div>Note that NetMessagingBinding only supports one-way communication. Therefore, OperationContract must explicitly set the attribute IsOneWay to true.</div>
<div>In the sample, the service collects all the items in a single session and then displays the total at the end. The service is defined in its App.config file.</div>
<div>
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>C#</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">csharp</span>
<pre class="hidden">    // ServiceBus does not support IOutputSessionChannel.
    // All senders sending messages to sessionful queue must use a contract which does not enforce SessionMode.Required.
    // Sessionful messages are sent by setting the SessionId property of the BrokeredMessageProperty object.
    [ServiceContract]
    public interface IOrderServiceContract
    {
        [OperationContract(IsOneWay = true)]
        [ReceiveContextEnabled(ManualControl = true)]
        void Order(OrderItem orderItem);
    }

    // ServiceBus supports both IInputChannel and IInputSessionChannel. 
    // A sessionful service listening to a sessionful queue must have SessionMode.Required in its contract.
    [ServiceContract(SessionMode = SessionMode.Required)]
    public interface IOrderServiceContractSessionful : IOrderServiceContract
    {
    }

    [ServiceBehavior(InstanceContextMode = InstanceContextMode.PerSession, ConcurrencyMode = ConcurrencyMode.Single)]
    public class OrderService : IOrderServiceContractSessionful, IDisposable
    {
        #region Service variables
        List&lt;OrderItem&gt; orderItems;
        int messageCounter;
        string sessionId;
        #endregion

        public OrderService()
        {
            this.messageCounter = 0;
            this.orderItems = new List&lt;OrderItem&gt;();
            this.sessionId = string.Empty;
        }

        public void Dispose()
        {
            SampleManager.OutputMessageInfo(&quot;Process Order&quot;, string.Format(&quot;Finished processing order. Total {0} items&quot;, orderItems.Count), this.sessionId);
        }

        public void Order(OrderItem orderItem)
        {
            // Get the BrokeredMessageProperty from OperationContext
            var incomingProperties = OperationContext.Current.IncomingMessageProperties;
            BrokeredMessageProperty property = (BrokeredMessageProperty)incomingProperties[BrokeredMessageProperty.Name];

            // Get the current ServiceBus SessionId
            if (this.sessionId == string.Empty)
            {
                this.sessionId = property.SessionId;
            }

            // Print message
            if (this.messageCounter == 0)
            {
                SampleManager.OutputMessageInfo(&quot;Process Order&quot;, &quot;Started processing order.&quot;, this.sessionId);
            }

            //Complete the Message
            ReceiveContext receiveContext;
            if (ReceiveContext.TryGet(incomingProperties, out receiveContext))
            {
                receiveContext.Complete(TimeSpan.FromSeconds(10.0d));
                this.orderItems.Add(orderItem);
                this.messageCounter&#43;&#43;;
            }
            else
            {
                throw new InvalidOperationException(&quot;Receiver is in peek lock mode but receive context is not available!&quot;);
            }
        }
    }</pre>
<div class="preview">
<pre class="js">&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__sl_comment">//&nbsp;ServiceBus&nbsp;does&nbsp;not&nbsp;support&nbsp;IOutputSessionChannel.</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__sl_comment">//&nbsp;All&nbsp;senders&nbsp;sending&nbsp;messages&nbsp;to&nbsp;sessionful&nbsp;queue&nbsp;must&nbsp;use&nbsp;a&nbsp;contract&nbsp;which&nbsp;does&nbsp;not&nbsp;enforce&nbsp;SessionMode.Required.</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__sl_comment">//&nbsp;Sessionful&nbsp;messages&nbsp;are&nbsp;sent&nbsp;by&nbsp;setting&nbsp;the&nbsp;SessionId&nbsp;property&nbsp;of&nbsp;the&nbsp;BrokeredMessageProperty&nbsp;object.</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;[ServiceContract]&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;public&nbsp;interface&nbsp;IOrderServiceContract&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">{</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[OperationContract(IsOneWay&nbsp;=&nbsp;true)]&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;[ReceiveContextEnabled(ManualControl&nbsp;=&nbsp;true)]&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__operator">void</span>&nbsp;Order(OrderItem&nbsp;orderItem);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">}</span>&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__sl_comment">//&nbsp;ServiceBus&nbsp;supports&nbsp;both&nbsp;IInputChannel&nbsp;and&nbsp;IInputSessionChannel.&nbsp;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__sl_comment">//&nbsp;A&nbsp;sessionful&nbsp;service&nbsp;listening&nbsp;to&nbsp;a&nbsp;sessionful&nbsp;queue&nbsp;must&nbsp;have&nbsp;SessionMode.Required&nbsp;in&nbsp;its&nbsp;contract.</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;[ServiceContract(SessionMode&nbsp;=&nbsp;SessionMode.Required)]&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;public&nbsp;interface&nbsp;IOrderServiceContractSessionful&nbsp;:&nbsp;IOrderServiceContract&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">{</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">}</span>&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;[ServiceBehavior(InstanceContextMode&nbsp;=&nbsp;InstanceContextMode.PerSession,&nbsp;ConcurrencyMode&nbsp;=&nbsp;ConcurrencyMode.Single)]&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;public&nbsp;class&nbsp;OrderService&nbsp;:&nbsp;IOrderServiceContractSessionful,&nbsp;IDisposable&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">{</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;#region&nbsp;Service&nbsp;variables&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;List&lt;OrderItem&gt;&nbsp;orderItems;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;int&nbsp;messageCounter;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;string&nbsp;sessionId;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;#endregion&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;public&nbsp;OrderService()&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">{</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__operator">this</span>.messageCounter&nbsp;=&nbsp;<span class="js__num">0</span>;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__operator">this</span>.orderItems&nbsp;=&nbsp;<span class="js__operator">new</span>&nbsp;List&lt;OrderItem&gt;();&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__operator">this</span>.sessionId&nbsp;=&nbsp;string.Empty;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">}</span>&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;public&nbsp;<span class="js__operator">void</span>&nbsp;Dispose()&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">{</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SampleManager.OutputMessageInfo(<span class="js__string">&quot;Process&nbsp;Order&quot;</span>,&nbsp;string.Format(<span class="js__string">&quot;Finished&nbsp;processing&nbsp;order.&nbsp;Total&nbsp;{0}&nbsp;items&quot;</span>,&nbsp;orderItems.Count),&nbsp;<span class="js__operator">this</span>.sessionId);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">}</span>&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;public&nbsp;<span class="js__operator">void</span>&nbsp;Order(OrderItem&nbsp;orderItem)&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">{</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__sl_comment">//&nbsp;Get&nbsp;the&nbsp;BrokeredMessageProperty&nbsp;from&nbsp;OperationContext</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__statement">var</span>&nbsp;incomingProperties&nbsp;=&nbsp;OperationContext.Current.IncomingMessageProperties;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;BrokeredMessageProperty&nbsp;property&nbsp;=&nbsp;(BrokeredMessageProperty)incomingProperties[BrokeredMessageProperty.Name];&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__sl_comment">//&nbsp;Get&nbsp;the&nbsp;current&nbsp;ServiceBus&nbsp;SessionId</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__statement">if</span>&nbsp;(<span class="js__operator">this</span>.sessionId&nbsp;==&nbsp;string.Empty)&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">{</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__operator">this</span>.sessionId&nbsp;=&nbsp;property.SessionId;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">}</span>&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__sl_comment">//&nbsp;Print&nbsp;message</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__statement">if</span>&nbsp;(<span class="js__operator">this</span>.messageCounter&nbsp;==&nbsp;<span class="js__num">0</span>)&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">{</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;SampleManager.OutputMessageInfo(<span class="js__string">&quot;Process&nbsp;Order&quot;</span>,&nbsp;<span class="js__string">&quot;Started&nbsp;processing&nbsp;order.&quot;</span>,&nbsp;<span class="js__operator">this</span>.sessionId);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">}</span>&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__sl_comment">//Complete&nbsp;the&nbsp;Message</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ReceiveContext&nbsp;receiveContext;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__statement">if</span>&nbsp;(ReceiveContext.TryGet(incomingProperties,&nbsp;out&nbsp;receiveContext))&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">{</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;receiveContext.Complete(TimeSpan.FromSeconds(<span class="js__num">10</span>.0d));&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__operator">this</span>.orderItems.Add(orderItem);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__operator">this</span>.messageCounter&#43;&#43;;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">}</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__statement">else</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">{</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__statement">throw</span>&nbsp;<span class="js__operator">new</span>&nbsp;InvalidOperationException(<span class="js__string">&quot;Receiver&nbsp;is&nbsp;in&nbsp;peek&nbsp;lock&nbsp;mode&nbsp;but&nbsp;receive&nbsp;context&nbsp;is&nbsp;not&nbsp;available!&quot;</span>);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">}</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">}</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">}</span></pre>
</div>
</div>
</div>
<div class="endscriptcode">&nbsp;</div>
The service subscribes to the faulted event. This will notify the service if any fault occurred during execution and can be handled properly. In the sample, the service is aborted on fault. The service also implements a ErrorServiceBehavior for handling exceptions
 during execution.</div>
<div>&nbsp;</div>
<div>
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>C#</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">csharp</span>
<pre class="hidden">    static void Main(string[] args)
    {
        // Create MessageReceiver for queue which requires session
        Console.Title = &quot;Order Service&quot;;
        Console.WriteLine(&quot;Ready to receive messages from {0}...&quot;, SampleManager.OrderQueueName);

        // Creating the service host object as defined in config
        ServiceHost serviceHost = new ServiceHost(typeof(OrderService));

        // Add ErrorServiceBehavior for handling errors encounter by servicehost during execution.
        serviceHost.Description.Behaviors.Add(new ErrorServiceBehavior());

        // Subscribe to the faulted event.
        serviceHost.Faulted &#43;= new EventHandler(serviceHost_Faulted);

        // Start service
        serviceHost.Open();

        Console.WriteLine(&quot;\nPress [Enter] to exit.&quot;);
        Console.ReadLine();

        // Close the service
        serviceHost.Close();
    }

    static void serviceHost_Faulted(object sender, EventArgs e)
    {
        Console.WriteLine(&quot;Fault occured. Aborting the service host object ...&quot;);
        ((ServiceHost)sender).Abort();
    }</pre>
<div class="preview">
<pre class="js">&nbsp;&nbsp;&nbsp;&nbsp;static&nbsp;<span class="js__operator">void</span>&nbsp;Main(string[]&nbsp;args)&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">{</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__sl_comment">//&nbsp;Create&nbsp;MessageReceiver&nbsp;for&nbsp;queue&nbsp;which&nbsp;requires&nbsp;session</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Console.Title&nbsp;=&nbsp;<span class="js__string">&quot;Order&nbsp;Service&quot;</span>;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Console.WriteLine(<span class="js__string">&quot;Ready&nbsp;to&nbsp;receive&nbsp;messages&nbsp;from&nbsp;{0}...&quot;</span>,&nbsp;SampleManager.OrderQueueName);&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__sl_comment">//&nbsp;Creating&nbsp;the&nbsp;service&nbsp;host&nbsp;object&nbsp;as&nbsp;defined&nbsp;in&nbsp;config</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;ServiceHost&nbsp;serviceHost&nbsp;=&nbsp;<span class="js__operator">new</span>&nbsp;ServiceHost(<span class="js__operator">typeof</span>(OrderService));&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__sl_comment">//&nbsp;Add&nbsp;ErrorServiceBehavior&nbsp;for&nbsp;handling&nbsp;errors&nbsp;encounter&nbsp;by&nbsp;servicehost&nbsp;during&nbsp;execution.</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;serviceHost.Description.Behaviors.Add(<span class="js__operator">new</span>&nbsp;ErrorServiceBehavior());&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__sl_comment">//&nbsp;Subscribe&nbsp;to&nbsp;the&nbsp;faulted&nbsp;event.</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;serviceHost.Faulted&nbsp;&#43;=&nbsp;<span class="js__operator">new</span>&nbsp;EventHandler(serviceHost_Faulted);&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__sl_comment">//&nbsp;Start&nbsp;service</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;serviceHost.Open();&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Console.WriteLine(<span class="js__string">&quot;\nPress&nbsp;[Enter]&nbsp;to&nbsp;exit.&quot;</span>);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Console.ReadLine();&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__sl_comment">//&nbsp;Close&nbsp;the&nbsp;service</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;serviceHost.Close();&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">}</span>&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;static&nbsp;<span class="js__operator">void</span>&nbsp;serviceHost_Faulted(object&nbsp;sender,&nbsp;EventArgs&nbsp;e)&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">{</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Console.WriteLine(<span class="js__string">&quot;Fault&nbsp;occured.&nbsp;Aborting&nbsp;the&nbsp;service&nbsp;host&nbsp;object&nbsp;...&quot;</span>);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;((ServiceHost)sender).Abort();&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">}</span></pre>
</div>
</div>
</div>
<div class="endscriptcode">&nbsp;</div>
The service also implements an ErrorServiceBehavior for unhandled exceptions during service execution. ErrorServiceBehavior is a service behavior which adds an IErrorHandler object to the dispatcher. This object simply prints out all the exceptions except CommunicationException.</div>
<div>&nbsp;</div>
<div>
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>C#</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">csharp</span>
<pre class="hidden">public class ErrorHandler : IErrorHandler
{
    public bool HandleError(Exception error)
    {
        if (!error.GetType().Equals(typeof(CommunicationException)))
        {
            // Handle the exception as required by the application
            Console.WriteLine(&quot;Service encountered an exception.&quot;);
            Console.WriteLine(error.ToString());
        }

        return true;
    }

    public void ProvideFault(Exception error, MessageVersion version, ref Message fault)
    {
    }
}

public class ErrorServiceBehavior : IServiceBehavior
{
    public void AddBindingParameters(ServiceDescription serviceDescription, ServiceHostBase serviceHostBase,
        Collection&lt;ServiceEndpoint&gt; endpoints, BindingParameterCollection bindingParameters)
    {
    }

    public void ApplyDispatchBehavior(ServiceDescription serviceDescription, ServiceHostBase serviceHostBase)
    {
        foreach (ChannelDispatcher dispatcher in serviceHostBase.ChannelDispatchers)
        {
            dispatcher.ErrorHandlers.Add(new ErrorHandler());
        }
    }

    public void Validate(ServiceDescription serviceDescription, ServiceHostBase serviceHostBase)
    {
    }
}
</pre>
<div class="preview">
<pre class="js">public&nbsp;class&nbsp;ErrorHandler&nbsp;:&nbsp;IErrorHandler&nbsp;
<span class="js__brace">{</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;public&nbsp;bool&nbsp;HandleError(Exception&nbsp;error)&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">{</span><span class="js__statement">if</span>&nbsp;(!error.GetType().Equals(<span class="js__operator">typeof</span>(CommunicationException)))&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">{</span><span class="js__sl_comment">//&nbsp;Handle&nbsp;the&nbsp;exception&nbsp;as&nbsp;required&nbsp;by&nbsp;the&nbsp;application</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Console.WriteLine(<span class="js__string">&quot;Service&nbsp;encountered&nbsp;an&nbsp;exception.&quot;</span>);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Console.WriteLine(error.ToString());&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">}</span><span class="js__statement">return</span>&nbsp;true;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">}</span>&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;public&nbsp;<span class="js__operator">void</span>&nbsp;ProvideFault(Exception&nbsp;error,&nbsp;MessageVersion&nbsp;version,&nbsp;ref&nbsp;Message&nbsp;fault)&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">{</span><span class="js__brace">}</span><span class="js__brace">}</span>&nbsp;
&nbsp;
public&nbsp;class&nbsp;ErrorServiceBehavior&nbsp;:&nbsp;IServiceBehavior&nbsp;
<span class="js__brace">{</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;public&nbsp;<span class="js__operator">void</span>&nbsp;AddBindingParameters(ServiceDescription&nbsp;serviceDescription,&nbsp;ServiceHostBase&nbsp;serviceHostBase,&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Collection&lt;ServiceEndpoint&gt;&nbsp;endpoints,&nbsp;BindingParameterCollection&nbsp;bindingParameters)&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">{</span><span class="js__brace">}</span>&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;public&nbsp;<span class="js__operator">void</span>&nbsp;ApplyDispatchBehavior(ServiceDescription&nbsp;serviceDescription,&nbsp;ServiceHostBase&nbsp;serviceHostBase)&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">{</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;foreach&nbsp;(ChannelDispatcher&nbsp;dispatcher&nbsp;<span class="js__operator">in</span>&nbsp;serviceHostBase.ChannelDispatchers)&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">{</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;dispatcher.ErrorHandlers.Add(<span class="js__operator">new</span>&nbsp;ErrorHandler());&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">}</span><span class="js__brace">}</span>&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;public&nbsp;<span class="js__operator">void</span>&nbsp;Validate(ServiceDescription&nbsp;serviceDescription,&nbsp;ServiceHostBase&nbsp;serviceHostBase)&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">{</span><span class="js__brace">}</span><span class="js__brace">}</span></pre>
</div>
</div>
</div>
</div>
<h1>Running the Sample</h1>
<ul>
<li>Open&nbsp;the solution in Visual Studio. </li><li>Add the namespace and key information in theApp.Config files for the&nbsp;OrderClient and OrderService.
</li><li>Run&nbsp;the executable &lsquo;SampleManager.exe&rsquo;. The program prompts for your Service Bus namespace and credentials.
</li></ul>
<div>&nbsp;</div>
<h2>Expected Output - Sample Manager</h2>
<div>&nbsp;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Please provide the namespace: &lt;Service Namespace&gt;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Please provide the key name: &lt;SAS Key&nbsp;Name&gt;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Please provide the key: &lt;SAS Key&gt;<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Creating Queues...<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Created OrderQueue, Queue.RequiresSession = True&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div>
<div>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Launching senders and receivers...&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div>
<div>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Press [Enter] to exit</div>
<div>&nbsp;</div>
<h2>Expected Output &ndash; Order Client [CustomerId 0]</h2>
<div>&nbsp;</div>
<div><br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Sending 7 messages to OrderQueue...<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Order: Product5 [81] - CustomerId 0.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Order: Product6 [84] - CustomerId 0.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Order: Product1 [9] - CustomerId 0.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Order: Product3 [34] - CustomerId 0.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Order: Product4 [58] - CustomerId 0.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Order: Product5 [83] - CustomerId 0.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Order: Product1 [8] - CustomerId 0.&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div>
<div>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Sender complete.&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div>
<div>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Press [Enter] to exit.</div>
<div>&nbsp;</div>
<h2>Expected Output &ndash; Order Client [CustomerId 1]</h2>
<div>&nbsp;</div>
<div><br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Sending 8 messages to OrderQueue...<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Order: Product5 [67] - CustomerId 1.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Order: Product6 [92] - CustomerId 1.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Order: Product2 [17] - CustomerId 1.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Order: Product5 [80] - CustomerId 1.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Order: Product1 [6] - CustomerId 1.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Order: Product2 [30] - CustomerId 1.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Order: Product4 [55] - CustomerId 1.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Order: Product5 [79] - CustomerId 1.&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div>
<div>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Sender complete.&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div>
<div>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Press [Enter] to exit.</div>
<div>&nbsp;</div>
<h2>Expected Output - Order Service</h2>
<div>&nbsp;</div>
<div><br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Ready to receive messages from OrderQueue...&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</div>
<div>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Press [Enter] to exit.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Process Order: Started processing order. - CustomerId 1.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Process Order: Started processing order. - CustomerId 0.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Process Order: Finished processing order. Total 8 items - CustomerId 1.<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
 Process Order: Finished processing order. Total 7 items - CustomerId 0.</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
<div>&nbsp;</div>
</div>
<div>&nbsp;</div>
<div><span style="font-family:Consolas; font-size:x-small"><span style="font-family:Consolas; font-size:x-small">&nbsp;</span></span>&nbsp;</div>
