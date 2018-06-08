# Relayed Messaging Bindings : WS2007Http MsgSecCertificate
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
* 2011-11-15 03:28:25
## Description

<h1>Introduction</h1>
<p><em>This sample demonstrates how to use the WS2007HttpRelayBinding binding with message security to secure end-to-end messages while still requiring clients to authenticate with the Service Bus. This allows the Service Bus to control client access to the
 service endpoint while enabling encryption/signature protection on the message path.<br>
</em></p>
<h1><em>Prerequisites</em></h1>
<div><em>&nbsp;</em>&nbsp;</div>
<div><em>If you haven't already done so, read the release notes document that explains how to sign up for a Windows Azure account and how to configure your environment.</em></div>
<h1><em>&nbsp;</em></h1>
<h1><em>Echo Service</em></h1>
<div><em>&nbsp;</em>&nbsp;</div>
<div><em>The service implements a simple contract with a single operation named Echo. The Echo service accepts a string and echoes it back.</em></div>
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>C#</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">csharp</span>
<pre class="hidden">[ServiceBehavior(Name = &quot;EchoService&quot;, Namespace = &quot;http://samples.microsoft.com/ServiceModel/Relay/&quot;)]
class EchoService : IEchoContract
{
    public string Echo(string text)
    {
        Console.WriteLine(&quot;Echoing: {0}&quot;, text);
        return text;            
    }
}
</pre>
<div class="preview">
<pre class="js">[ServiceBehavior(Name&nbsp;=&nbsp;<span class="js__string">&quot;EchoService&quot;</span>,&nbsp;Namespace&nbsp;=&nbsp;<span class="js__string">&quot;http://samples.microsoft.com/ServiceModel/Relay/&quot;</span>)]&nbsp;
class&nbsp;EchoService&nbsp;:&nbsp;IEchoContract&nbsp;
<span class="js__brace">{</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;public&nbsp;string&nbsp;Echo(string&nbsp;text)&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">{</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Console.WriteLine(<span class="js__string">&quot;Echoing:&nbsp;{0}&quot;</span>,&nbsp;text);&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__statement">return</span>&nbsp;text;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="js__brace">}</span>&nbsp;
<span class="js__brace">}</span>&nbsp;
</pre>
</div>
</div>
</div>
<div class="endscriptcode"><span style="color:black; line-height:115%">The service configuration contains one endpoint that refers to a
<strong>WS2007HttpRelayBinding </strong>configuration, which uses message security with no client credential. To secure the endpoint, the service is configured with the
<strong>certificateServiceBehavior </strong>behavior. This behavior contains the service credentials backed by the test certificate generated and installed using the setup.bat script.</span></div>
<div><em><span style="color:black; line-height:115%">
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>XML</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">xml</span>
<pre class="hidden">&lt;configuration&gt;
  &lt;system.serviceModel&gt;
    
    &lt;behaviors&gt;    
      &lt;endpointBehaviors&gt;
        &lt;behavior name=&quot;sharedSecretClientCredentials&quot;&gt;
          &lt;transportClientEndpointBehavior credentialType=&quot;SharedSecret&quot;&gt;
            &lt;clientCredentials&gt;
              &lt;sharedSecret issuerName=&quot;ISSUER_NAME&quot; issuerSecret=&quot;ISSUER_SECRET&quot; /&gt;
            &lt;/clientCredentials&gt;
          &lt;/transportClientEndpointBehavior&gt;
        &lt;/behavior&gt;
      &lt;/endpointBehaviors&gt;

      &lt;serviceBehaviors&gt;
        &lt;behavior name=&quot;certificateServiceBehavior&quot;&gt;
          &lt;serviceCredentials&gt;
            &lt;serviceCertificate findValue=&quot;localhost&quot; storeLocation=&quot;LocalMachine&quot; storeName=&quot;My&quot; x509FindType=&quot;FindBySubjectName&quot; /&gt;
          &lt;/serviceCredentials&gt;
        &lt;/behavior&gt;
      &lt;/serviceBehaviors&gt;  
    &lt;/behaviors&gt;
    
    &lt;bindings&gt;
      &lt;!-- Application Binding --&gt;
      &lt;ws2007HttpRelayBinding&gt;
        &lt;binding name=&quot;messageSecurity&quot;&gt;
          &lt;security mode=&quot;Message&quot;&gt;
            &lt;message clientCredentialType=&quot;None&quot;/&gt;
          &lt;/security&gt;
        &lt;/binding&gt;
      &lt;/ws2007HttpRelayBinding&gt;
    &lt;/bindings&gt;

    &lt;services&gt;
      &lt;!-- Application Service --&gt;
      &lt;service name=&quot;Microsoft.ServiceBus.Samples.EchoService&quot; behaviorConfiguration=&quot;certificateServiceBehavior&quot;&gt;
        &lt;endpoint name=&quot;ServiceBusEndpoint&quot;
                  contract=&quot;Microsoft.ServiceBus.Samples.IEchoContract&quot;
                  binding=&quot;ws2007HttpRelayBinding&quot;
                  bindingConfiguration=&quot;messageSecurity&quot;
                  behaviorConfiguration=&quot;sharedSecretClientCredentials&quot; /&gt;
      &lt;/service&gt;
    &lt;/services&gt;

  &lt;/system.serviceModel&gt;
&lt;/configuration&gt;
</pre>
<div class="preview">
<pre class="xml"><span class="xml__tag_start">&lt;configuration</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;<span class="xml__tag_start">&lt;system</span>.serviceModel<span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;behaviors</span><span class="xml__tag_start">&gt;&nbsp;</span>&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;endpointBehaviors</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;behavior</span>&nbsp;<span class="xml__attr_name">name</span>=<span class="xml__attr_value">&quot;sharedSecretClientCredentials&quot;</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;transportClientEndpointBehavior</span>&nbsp;<span class="xml__attr_name">credentialType</span>=<span class="xml__attr_value">&quot;SharedSecret&quot;</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;clientCredentials</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;sharedSecret</span>&nbsp;<span class="xml__attr_name">issuerName</span>=<span class="xml__attr_value">&quot;ISSUER_NAME&quot;</span>&nbsp;<span class="xml__attr_name">issuerSecret</span>=<span class="xml__attr_value">&quot;ISSUER_SECRET&quot;</span>&nbsp;<span class="xml__tag_start">/&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/clientCredentials&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/transportClientEndpointBehavior&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/behavior&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/endpointBehaviors&gt;</span>&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;serviceBehaviors</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;behavior</span>&nbsp;<span class="xml__attr_name">name</span>=<span class="xml__attr_value">&quot;certificateServiceBehavior&quot;</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;serviceCredentials</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;serviceCertificate</span>&nbsp;<span class="xml__attr_name">findValue</span>=<span class="xml__attr_value">&quot;localhost&quot;</span>&nbsp;<span class="xml__attr_name">storeLocation</span>=<span class="xml__attr_value">&quot;LocalMachine&quot;</span>&nbsp;<span class="xml__attr_name">storeName</span>=<span class="xml__attr_value">&quot;My&quot;</span>&nbsp;<span class="xml__attr_name">x509FindType</span>=<span class="xml__attr_value">&quot;FindBySubjectName&quot;</span>&nbsp;<span class="xml__tag_start">/&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/serviceCredentials&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/behavior&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/serviceBehaviors&gt;</span>&nbsp;&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/behaviors&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;bindings</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__comment">&lt;!--&nbsp;Application&nbsp;Binding&nbsp;--&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;ws2007HttpRelayBinding</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;binding</span>&nbsp;<span class="xml__attr_name">name</span>=<span class="xml__attr_value">&quot;messageSecurity&quot;</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;security</span>&nbsp;<span class="xml__attr_name">mode</span>=<span class="xml__attr_value">&quot;Message&quot;</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;message</span>&nbsp;<span class="xml__attr_name">clientCredentialType</span>=<span class="xml__attr_value">&quot;None&quot;</span><span class="xml__tag_start">/&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/security&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/binding&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/ws2007HttpRelayBinding&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/bindings&gt;</span>&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;services</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__comment">&lt;!--&nbsp;Application&nbsp;Service&nbsp;--&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;service</span>&nbsp;<span class="xml__attr_name">name</span>=<span class="xml__attr_value">&quot;Microsoft.ServiceBus.Samples.EchoService&quot;</span>&nbsp;<span class="xml__attr_name">behaviorConfiguration</span>=<span class="xml__attr_value">&quot;certificateServiceBehavior&quot;</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;endpoint</span>&nbsp;<span class="xml__attr_name">name</span>=<span class="xml__attr_value">&quot;ServiceBusEndpoint&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__attr_name">contract</span>=<span class="xml__attr_value">&quot;Microsoft.ServiceBus.Samples.IEchoContract&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__attr_name">binding</span>=<span class="xml__attr_value">&quot;ws2007HttpRelayBinding&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__attr_name">bindingConfiguration</span>=<span class="xml__attr_value">&quot;messageSecurity&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__attr_name">behaviorConfiguration</span>=<span class="xml__attr_value">&quot;sharedSecretClientCredentials&quot;</span>&nbsp;<span class="xml__tag_start">/&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/service&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/services&gt;</span>&nbsp;
&nbsp;
&nbsp;&nbsp;&lt;/system.serviceModel&gt;&nbsp;
<span class="xml__tag_end">&lt;/configuration&gt;</span>&nbsp;
</pre>
</div>
</div>
</div>
<div class="endscriptcode">&nbsp;</div>
<h1 class="endscriptcode">Echo Service Client</h1>
<div class="endscriptcode">The client is very similar to the client in the Echo sample, but differs in configuration and in how the channel factory is configured.</div>
<div class="endscriptcode"></div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>C#</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">csharp</span>
<pre class="hidden">ChannelFactory&lt;IEchoChannel&gt; channelFactory = new ChannelFactory&lt;IEchoChannel&gt;(&quot;ServiceBusEndpoint&quot;, new EndpointAddress(serviceUri, EndpointIdentity.CreateDnsIdentity(&quot;localhost&quot;)));</pre>
<div class="preview">
<pre class="js">ChannelFactory&lt;IEchoChannel&gt;&nbsp;channelFactory&nbsp;=&nbsp;<span class="js__operator">new</span>&nbsp;ChannelFactory&lt;IEchoChannel&gt;(<span class="js__string">&quot;ServiceBusEndpoint&quot;</span>,&nbsp;<span class="js__operator">new</span>&nbsp;EndpointAddress(serviceUri,&nbsp;EndpointIdentity.CreateDnsIdentity(<span class="js__string">&quot;localhost&quot;</span>)));</pre>
</div>
</div>
</div>
<div class="endscriptcode">Note that the <strong>ChannelFactory </strong>is constructed using an
<strong>EndpointAddress </strong>that has an explicit &quot;DNS&quot; <strong>EndpointIdentity</strong>. The terminology may be a bit misleading here, because the identity is not directly related to DNS but rather to the certificate subject name. The identity name (<strong>localhost
</strong>in this case) refers directly to the subject name of the certificate that is specified for the service identity in the
<strong>certificateServiceBehavior </strong>behavior on the service-side. For an actual implementation, the service identity should be backed by a production certificate issued by a trusted CA and the
<strong>EndpointIdentity </strong>must refer to its subject name.</div>
<div class="endscriptcode">The client configuration mirrors the service configuration with a few exceptions. The client endpoints are configured with the
<strong>certificateEndpointBehavior </strong>behavior, with &lt;<strong>clientCredentials</strong>&gt; settings that turn off certificate validation specifically for the test certificate that is being used here. For an actual implementation that uses a CA issued
 certificate, you should omit this override.</div>
</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;
<div class="scriptcode">
<div class="pluginEditHolder" pluginCommand="mceScriptCode">
<div class="title"><span>XML</span></div>
<div class="pluginLinkHolder"><span class="pluginEditHolderLink">Edit</span>|<span class="pluginRemoveHolderLink">Remove</span></div>
<span class="hidden">xml</span>
<pre class="hidden">&lt;configuration&gt;
  &lt;system.serviceModel&gt;
    &lt;behaviors&gt;
      &lt;endpointBehaviors&gt;
        &lt;behavior name=&quot;certificateEndpointBehavior&quot;&gt;
          &lt;clientCredentials&gt;
            &lt;serviceCertificate&gt;
              &lt;!-- The sample sets certificateValidationMode to None because it uses self-issued certificates.
                   Applications should typically set this value to ChainTrust (the default) or Custom if a customCertificateValidator is
                   specified. --&gt;
              &lt;authentication certificateValidationMode=&quot;None&quot; /&gt;
            &lt;/serviceCertificate&gt;
          &lt;/clientCredentials&gt;
          &lt;transportClientEndpointBehavior credentialType=&quot;SharedSecret&quot;&gt;
            &lt;clientCredentials&gt;
              &lt;sharedSecret issuerName=&quot;ISSUER_NAME&quot; issuerSecret=&quot;ISSUER_SECRET&quot; /&gt;
            &lt;/clientCredentials&gt;
          &lt;/transportClientEndpointBehavior&gt;
        &lt;/behavior&gt;
      &lt;/endpointBehaviors&gt;
    &lt;/behaviors&gt;
    
    &lt;bindings&gt;
      &lt;!-- Application Binding --&gt;
      &lt;ws2007HttpRelayBinding&gt;
        &lt;binding name=&quot;messageSecurity&quot;&gt;
          &lt;security mode=&quot;Message&quot;&gt;
            &lt;message clientCredentialType=&quot;None&quot;/&gt;
          &lt;/security&gt;
        &lt;/binding&gt;
      &lt;/ws2007HttpRelayBinding&gt;
    &lt;/bindings&gt;

    &lt;client&gt;
      &lt;!-- Application Endpoint --&gt;
      &lt;endpoint name=&quot;ServiceBusEndpoint&quot;
                contract=&quot;Microsoft.ServiceBus.Samples.IEchoContract&quot;
                binding=&quot;ws2007HttpRelayBinding&quot;
                bindingConfiguration=&quot;messageSecurity&quot;
                behaviorConfiguration=&quot;certificateEndpointBehavior&quot; /&gt;
    &lt;/client&gt;
  &lt;/system.serviceModel&gt;
&lt;/configuration&gt;
</pre>
<div class="preview">
<pre class="xml"><span class="xml__tag_start">&lt;configuration</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;<span class="xml__tag_start">&lt;system</span>.serviceModel<span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;behaviors</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;endpointBehaviors</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;behavior</span>&nbsp;<span class="xml__attr_name">name</span>=<span class="xml__attr_value">&quot;certificateEndpointBehavior&quot;</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;clientCredentials</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;serviceCertificate</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__comment">&lt;!--&nbsp;The&nbsp;sample&nbsp;sets&nbsp;certificateValidationMode&nbsp;to&nbsp;None&nbsp;because&nbsp;it&nbsp;uses&nbsp;self-issued&nbsp;certificates.&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Applications&nbsp;should&nbsp;typically&nbsp;set&nbsp;this&nbsp;value&nbsp;to&nbsp;ChainTrust&nbsp;(the&nbsp;default)&nbsp;or&nbsp;Custom&nbsp;if&nbsp;a&nbsp;customCertificateValidator&nbsp;is&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;specified.&nbsp;--&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;authentication</span>&nbsp;<span class="xml__attr_name">certificateValidationMode</span>=<span class="xml__attr_value">&quot;None&quot;</span>&nbsp;<span class="xml__tag_start">/&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/serviceCertificate&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/clientCredentials&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;transportClientEndpointBehavior</span>&nbsp;<span class="xml__attr_name">credentialType</span>=<span class="xml__attr_value">&quot;SharedSecret&quot;</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;clientCredentials</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;sharedSecret</span>&nbsp;<span class="xml__attr_name">issuerName</span>=<span class="xml__attr_value">&quot;ISSUER_NAME&quot;</span>&nbsp;<span class="xml__attr_name">issuerSecret</span>=<span class="xml__attr_value">&quot;ISSUER_SECRET&quot;</span>&nbsp;<span class="xml__tag_start">/&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/clientCredentials&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/transportClientEndpointBehavior&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/behavior&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/endpointBehaviors&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/behaviors&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;bindings</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__comment">&lt;!--&nbsp;Application&nbsp;Binding&nbsp;--&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;ws2007HttpRelayBinding</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;binding</span>&nbsp;<span class="xml__attr_name">name</span>=<span class="xml__attr_value">&quot;messageSecurity&quot;</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;security</span>&nbsp;<span class="xml__attr_name">mode</span>=<span class="xml__attr_value">&quot;Message&quot;</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;message</span>&nbsp;<span class="xml__attr_name">clientCredentialType</span>=<span class="xml__attr_value">&quot;None&quot;</span><span class="xml__tag_start">/&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/security&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/binding&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/ws2007HttpRelayBinding&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/bindings&gt;</span>&nbsp;
&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;client</span><span class="xml__tag_start">&gt;&nbsp;
</span>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__comment">&lt;!--&nbsp;Application&nbsp;Endpoint&nbsp;--&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_start">&lt;endpoint</span>&nbsp;<span class="xml__attr_name">name</span>=<span class="xml__attr_value">&quot;ServiceBusEndpoint&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__attr_name">contract</span>=<span class="xml__attr_value">&quot;Microsoft.ServiceBus.Samples.IEchoContract&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__attr_name">binding</span>=<span class="xml__attr_value">&quot;ws2007HttpRelayBinding&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__attr_name">bindingConfiguration</span>=<span class="xml__attr_value">&quot;messageSecurity&quot;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__attr_name">behaviorConfiguration</span>=<span class="xml__attr_value">&quot;certificateEndpointBehavior&quot;</span>&nbsp;<span class="xml__tag_start">/&gt;</span>&nbsp;
&nbsp;&nbsp;&nbsp;&nbsp;<span class="xml__tag_end">&lt;/client&gt;</span>&nbsp;
&nbsp;&nbsp;&lt;/system.serviceModel&gt;&nbsp;
<span class="xml__tag_end">&lt;/configuration&gt;</span>&nbsp;
</pre>
</div>
</div>
</div>
<div class="endscriptcode">&nbsp;</div>
</div>
<h1 class="endscriptcode"><strong>Running the Sample</strong></h1>
<div class="endscriptcode">
<p>&nbsp;</p>
<p>To run the sample, first open App.config in both Serivce and Client projects and replace the place-holders
<strong>ISSUER_NAME</strong> and <strong>ISSUER_SECRET</strong> with the issuer name and secret you want to use.&nbsp;Note that you may use the same values in both projects or alternately, you can set up multiple issuers and use different values for the Service
 and Client.</p>
<p>&nbsp;</p>
<p>To generate and install the self-issued cerificate used by the sample, run the setup.bat file included in the sample solution from a Visual Studio command line window running with Administrator privileges. After updating the configuration files, build the
 solution in Visual Studio 2010 or from the command line, then run the two resulting executables. Start the service first using an elevated command prompt, then run the client. Both programs start by prompting you to type your service namespace.</p>
<p>&nbsp;</p>
<p>When the service and the client are running, you can start typing messages into the client application. These messages are echoed by the service.</p>
<p>&nbsp;</p>
<p>After stopping the client and service you can run cleanup.bat from a Visual Studio command line window with Administrator privileges to remove the sample certificate from your computer's local store.<br>
<strong>&nbsp;</strong></p>
<h2><strong>Expected Output &ndash; Client</strong></h2>
</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">Your Service Namespace: &lt;service namespace&gt; <br>
Enter text to echo (or [Enter] to exit): Hello, World!<br>
Server echoed: Hello, World!</div>
<h2 class="endscriptcode">Expected Output &ndash; Service</h2>
<div class="endscriptcode">Service address: <a href="https://&lt;service">https://&lt;service</a> namespace&gt;.servicebus.windows.net/EchoService/<br>
Press [Enter] to exit<br>
Echoing: Hello, World!</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode">&nbsp;</div>
</span></em><em><em><span style="color:black; line-height:115%">&nbsp;</span></em></em></div>
<div class="endscriptcode">&nbsp;</div>
<div class="endscriptcode"><em><em>&nbsp;</em></em></div>
<div class="endscriptcode"><em><span style="color:black; line-height:115%">&nbsp;</span></em></div>
<div class="endscriptcode"><em><em>&nbsp;</em></em></div>
<div class="endscriptcode"><em><em>&nbsp;</em></em></div>
<div class="endscriptcode"><em>&nbsp;</em></div>