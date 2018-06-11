////////////////////////////////////////////////////////////////////////////////////////////////////
//
//   Copyright (c) 2012 Microsoft Corporation.  All Rights Reserved.
//
//   Module Name:
//      ClassifyFunctions_FastPacketInjectionCallouts.cpp
//
//   Abstract:
//      This module contains WFP Classify functions that inject packets back into the data path 
//         using the clone / block / inject method.  This method is inline only, no modification,
//         and uses as little validation and error checking as possible.  Certain scenarios will 
//         definitely fail injection, such as injection to loopback, or IPsec encrypted packets.   
//         These functions are meant for test performance purposes only.
//
//   Naming Convention:
//
//      <Module><Scenario>
//  
//      i.e.
//       ClassifyFastPacketInjection
//
//       <Module>
//          Classify             - Function is an FWPS_CALLOUT_CLASSIFY_FN
//       <Scenario>
//          FastPacketInjection  - Function demonstrates the clone / block / inject model in the 
//                                    fastest form available (inline, no validation, etc.).
//
//
//   Private Functions:
//
//   Public Functions:
//      ClassifyFastPacketInjection(),
//
//   Author:
//      Dusty Harper      (DHarper)
//
//   Revision History:
//
//      [ Month ][Day] [Year] - [Revision]-[ Comments ]
//      May       01,   2010  -     1.0   -  Creation
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Framework_WFPSamplerCalloutDriver.h"               /// .
#include "ClassifyFunctions_FastPacketInjectionCallouts.tmh" /// $(OBJ_PATH)\$(O)\

#if(NTDDI_VERSION >= NTDDI_WIN7)

/**
 @classify_function="ClassifyFastPacketInjection"
 
   Purpose:  Blocks the current NET_BUFFER_LIST and injects a clone back to the stack without 
             modification.                                                                      <br>
                                                                                                <br>
   Notes:    Applies to the following layers:                                                   <br>
                FWPS_LAYER_INBOUND_IPPACKET_V{4/6}                                              <br>
                FWPS_LAYER_OUTBOUND_IPPACKET_V{4/6}                                             <br>
                FWPS_LAYER_IPFORWARD_V{4/6}                                                     <br>
                FWPS_LAYER_INBOUND_TRANSPORT_V{4/6}                                             <br>
                FWPS_LAYER_OUTBOUND_TRANSPORT_V{4/6}                                            <br>
                FWPS_LAYER_DATAGRAM_DATA_V{4/6}                                                 <br>
                FWPS_LAYER_INBOUND_ICMP_ERROR_V{4/6}                                            <br>
                FWPS_LAYER_OUTBOUND_ICMP_ERROR_V{4/6}                                           <br>
                FWPS_LAYER_ALE_AUTH_CONNECT_V{4/6}                                              <br>
                FWPS_LAYER_ALE_FLOW_ESTABLISHED_V{4/6}                                          <br>
                FWPS_LAYER_STREAM_PACKET_V{4/6}                                                 <br>
                FWPS_LAYER_INBOUND_MAC_FRAME_ETHERNET                                           <br>
                FWPS_LAYER_OUTBOUND_MAC_FRAME_ETHERNET                                          <br>
                FWPS_LAYER_INBOUND_MAC_FRAME_NATIVE                                             <br>
                FWPS_LAYER_OUTBOUND_MAC_FRAME_NATIVE                                            <br>
                FWPS_LAYER_INGRESS_VSWITCH_ETHERNET                                             <br>
                FWPS_LAYER_EGRESS_VSWITCH_ETHERNET                                              <br>
                                                                                                <br>
             Intended for test performance purposes only.                                       <br>
                                                                                                <br>
   MSDN_Ref: HTTP://MSDN.Microsoft.com/En-US/Library/Windows/Hardware/FF544893.aspx             <br>
             HTTP://MSDN.Microsoft.com/En-US/Library/Windows/Hardware/FF551202.aspx             <br>
             HTTP://MSDN.Microsoft.com/En-US/Library/Windows/Hardware/FF551134.aspx             <br>
             HTTP://MSDN.Microsoft.com/En-US/Library/Windows/Hardware/FF551183.aspx             <br>
             HTTP://MSDN.Microsoft.com/En-US/Library/Windows/Hardware/FF551185.aspx             <br>
             HTTP://MSDN.Microsoft.com/En-US/Library/Windows/Hardware/FF551177.aspx             <br>
             HTTP://MSDN.Microsoft.com/En-US/Library/Windows/Hardware/FF551186.aspx             <br>
             HTTP://MSDN.Microsoft.com/En-US/Library/Windows/Hardware/FF551188.aspx             <br>
             HTTP://MSDN.Microsoft.com/En-US/Library/Windows/Hardware/HH439588.aspx             <br>
             HTTP://MSDN.Microsoft.com/En-US/Library/Windows/Hardware/HH439593.aspx             <br>
             HTTP://MSDN.Microsoft.com/En-US/Library/Windows/Hardware/HH439669.aspx             <br>
             HTTP://MSDN.Microsoft.com/En-US/Library/Windows/Hardware/FF551170.aspx             <br>
*/
_IRQL_requires_min_(PASSIVE_LEVEL)
_IRQL_requires_max_(DISPATCH_LEVEL)
_IRQL_requires_same_
VOID ClassifyFastPacketInjection(_In_ const FWPS_INCOMING_VALUES* pClassifyValues,
                                 _In_ const FWPS_INCOMING_METADATA_VALUES* pMetadata,
                                 _Inout_opt_ VOID* pNetBufferList,
                                 _In_opt_ const VOID* pClassifyContext,
                                 _In_ const FWPS_FILTER* pFilter,
                                 _In_ UINT64 flowContext,
                                 _Inout_ FWPS_CLASSIFY_OUT* pClassifyOut)
{
   UNREFERENCED_PARAMETER(pFilter);
   UNREFERENCED_PARAMETER(pClassifyContext);
   UNREFERENCED_PARAMETER(flowContext);

   if(pClassifyOut->rights & FWPS_RIGHT_ACTION_WRITE)
   {
      NTSTATUS                    status                = STATUS_SUCCESS;
      UINT32                      ipHeaderSize          = 0;
      UINT32                      transportHeaderSize   = 0;
      COMPARTMENT_ID              compartmentID         = UNSPECIFIED_COMPARTMENT_ID;
      UINT64                      endpointHandle        = 0;
      ADDRESS_FAMILY              addressFamily         = AF_UNSPEC;
      FWP_DIRECTION               direction             = FWP_DIRECTION_MAX;
      UINT32                      flags                 = 0;
      BOOLEAN                     isALEClassifyRequired = FALSE;
      VOID*                       pRemoteAddress        = 0;
      IF_INDEX                    interfaceIndex        = 0;
      IF_INDEX                    subInterfaceIndex     = 0;
      HANDLE                      injectionHandle       = 0;
      FWPS_PACKET_INJECTION_STATE injectionState        = FWPS_PACKET_INJECTION_STATE_MAX;
      HANDLE                      injectionContext      = 0;
      UINT32                      bytesRetreated        = 0;
      NET_BUFFER_LIST*            pClonedNetBufferList = 0;

#if(NTDDI_VERSION >= NTDDI_WIN8)

      UINT32                      ethernetHeaderSize   = 0;
      NDIS_PORT_NUMBER            ndisPort             = 0;
      NDIS_SWITCH_PORT_ID         sourcePortID         = 0;
      NDIS_SWITCH_NIC_INDEX       sourceNICIndex       = 0;
      FWP_BYTE_BLOB*              pVSwitchID           = 0;

      if(FWPS_IS_L2_METADATA_FIELD_PRESENT(pMetadata,
                                           FWPS_L2_METADATA_FIELD_ETHERNET_MAC_HEADER_SIZE))
         ethernetHeaderSize = pMetadata->ethernetMacHeaderSize;

      if(FWPS_IS_L2_METADATA_FIELD_PRESENT(pMetadata,
                                           FWPS_L2_METADATA_FIELD_VSWITCH_SOURCE_PORT_ID))
         sourcePortID = pMetadata->vSwitchSourcePortId;

      if(FWPS_IS_L2_METADATA_FIELD_PRESENT(pMetadata,
                                           FWPS_L2_METADATA_FIELD_VSWITCH_SOURCE_NIC_INDEX))
         sourceNICIndex = (NDIS_SWITCH_NIC_INDEX)pMetadata->vSwitchSourceNicIndex;

#endif /// (NTDDI_VERSION >= NTDDI_WIN8)

      if(FWPS_IS_METADATA_FIELD_PRESENT(pMetadata,
                                        FWPS_METADATA_FIELD_IP_HEADER_SIZE))
         ipHeaderSize = pMetadata->ipHeaderSize;

      if(FWPS_IS_METADATA_FIELD_PRESENT(pMetadata,
                                        FWPS_METADATA_FIELD_TRANSPORT_HEADER_SIZE))
         transportHeaderSize = pMetadata->transportHeaderSize;

      if(FWPS_IS_METADATA_FIELD_PRESENT(pMetadata,
                                        FWPS_METADATA_FIELD_COMPARTMENT_ID))
         compartmentID = (COMPARTMENT_ID)pMetadata->compartmentId;

      if(FWPS_IS_METADATA_FIELD_PRESENT(pMetadata,
                                        FWPS_METADATA_FIELD_TRANSPORT_ENDPOINT_HANDLE))
         endpointHandle = pMetadata->transportEndpointHandle;

      if(FWPS_IS_METADATA_FIELD_PRESENT(pMetadata,
                                        FWPS_METADATA_FIELD_PACKET_DIRECTION))
         direction = pMetadata->packetDirection;

      if(FWPS_IS_METADATA_FIELD_PRESENT(pMetadata,
                                        FWPS_METADATA_FIELD_ALE_CLASSIFY_REQUIRED))
         isALEClassifyRequired = TRUE;

      switch(pClassifyValues->layerId)
      {
         case FWPS_LAYER_INBOUND_IPPACKET_V4:
         {
            addressFamily = AF_INET;

            interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_IPPACKET_V4_INTERFACE_INDEX].value.uint32;

            subInterfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_IPPACKET_V4_SUB_INTERFACE_INDEX].value.uint32;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_IPPACKET_V4_FLAGS].value.uint32;

            injectionHandle = g_IPv4InboundNetworkInjectionHandle;

            bytesRetreated = ipHeaderSize;

            break;
         }
         case FWPS_LAYER_INBOUND_IPPACKET_V6:
         {
            addressFamily = AF_INET6;

            interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_IPPACKET_V6_INTERFACE_INDEX].value.uint32;

            subInterfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_IPPACKET_V6_SUB_INTERFACE_INDEX].value.uint32;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_IPPACKET_V6_FLAGS].value.uint32;

            injectionHandle = g_IPv6InboundNetworkInjectionHandle;

            bytesRetreated = ipHeaderSize;

            break;
         }
         case FWPS_LAYER_OUTBOUND_IPPACKET_V4:
         {
            addressFamily = AF_INET;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_OUTBOUND_IPPACKET_V4_FLAGS].value.uint32;

            injectionHandle = g_IPv4OutboundNetworkInjectionHandle;
      
            break;
         }
         case FWPS_LAYER_OUTBOUND_IPPACKET_V6:
         {
            addressFamily = AF_INET6;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_OUTBOUND_IPPACKET_V6_FLAGS].value.uint32;

            injectionHandle = g_IPv6OutboundNetworkInjectionHandle;
      
            break;
         }
         case FWPS_LAYER_IPFORWARD_V4:
         {
            addressFamily = AF_INET;

            interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_IPFORWARD_V4_DESTINATION_INTERFACE_INDEX].value.uint32;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_IPFORWARD_V4_FLAGS].value.uint32;

            if(direction == FWP_DIRECTION_OUTBOUND)
               injectionHandle = g_IPv4OutboundForwardInjectionHandle;
            else
               injectionHandle = g_IPv4InboundForwardInjectionHandle;
      
            break;
         }
         case FWPS_LAYER_IPFORWARD_V6:
         {
            addressFamily = AF_INET6;

            interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_IPFORWARD_V6_DESTINATION_INTERFACE_INDEX].value.uint32;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_IPFORWARD_V6_FLAGS].value.uint32;

            if(direction == FWP_DIRECTION_OUTBOUND)
               injectionHandle = g_IPv6OutboundForwardInjectionHandle;
            else
               injectionHandle = g_IPv6InboundForwardInjectionHandle;
      
            break;
         }
         case FWPS_LAYER_INBOUND_TRANSPORT_V4:
         {
            addressFamily = AF_INET;

            interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_TRANSPORT_V4_INTERFACE_INDEX].value.uint32;

            subInterfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_TRANSPORT_V4_SUB_INTERFACE_INDEX].value.uint32;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_TRANSPORT_V4_FLAGS].value.uint32;

            injectionHandle = g_IPv4InboundTransportInjectionHandle;

            if(pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_TRANSPORT_V4_IP_PROTOCOL].value.uint8 == ICMPV4)
               bytesRetreated = ipHeaderSize;
            else
               bytesRetreated = ipHeaderSize + transportHeaderSize;

            break;
         }
         case FWPS_LAYER_INBOUND_TRANSPORT_V6:
         {
            addressFamily = AF_INET6;

            interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_TRANSPORT_V6_INTERFACE_INDEX].value.uint32;

            subInterfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_TRANSPORT_V6_SUB_INTERFACE_INDEX].value.uint32;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_TRANSPORT_V6_FLAGS].value.uint32;

            injectionHandle = g_IPv6InboundTransportInjectionHandle;

            if(pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_TRANSPORT_V6_IP_PROTOCOL].value.uint8 == ICMPV6)
               bytesRetreated = ipHeaderSize;
            else
               bytesRetreated = ipHeaderSize + transportHeaderSize;

            break;
         }
         case FWPS_LAYER_OUTBOUND_TRANSPORT_V4:
         {
            addressFamily = AF_INET;

            pRemoteAddress = &(pClassifyValues->incomingValue[FWPS_FIELD_OUTBOUND_TRANSPORT_V4_IP_REMOTE_ADDRESS].value.uint32);

            flags = pClassifyValues->incomingValue[FWPS_FIELD_OUTBOUND_TRANSPORT_V4_FLAGS].value.uint32;

            injectionHandle = g_IPv4OutboundTransportInjectionHandle;
      
            break;
         }
         case FWPS_LAYER_OUTBOUND_TRANSPORT_V6:
         {
            addressFamily = AF_INET6;

            pRemoteAddress = pClassifyValues->incomingValue[FWPS_FIELD_OUTBOUND_TRANSPORT_V6_IP_REMOTE_ADDRESS].value.byteArray16->byteArray16;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_OUTBOUND_TRANSPORT_V6_FLAGS].value.uint32;

            injectionHandle = g_IPv6OutboundTransportInjectionHandle;
      
            break;
         }
         case FWPS_LAYER_DATAGRAM_DATA_V4:
         {
            addressFamily = AF_INET;

            direction = (FWP_DIRECTION)pClassifyValues->incomingValue[FWPS_FIELD_DATAGRAM_DATA_V4_DIRECTION].value.uint32;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_DATAGRAM_DATA_V4_FLAGS].value.uint32;

            if(direction == FWP_DIRECTION_INBOUND)
            {
               interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_DATAGRAM_DATA_V4_INTERFACE_INDEX].value.uint32;

               subInterfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_DATAGRAM_DATA_V4_SUB_INTERFACE_INDEX].value.uint32;

               injectionHandle = g_IPv4InboundTransportInjectionHandle;

               if(pClassifyValues->incomingValue[FWPS_FIELD_DATAGRAM_DATA_V4_IP_PROTOCOL].value.uint8 == ICMPV4)
                  bytesRetreated = ipHeaderSize;
               else
                  bytesRetreated = ipHeaderSize + transportHeaderSize;
            }
            else
            {
               pRemoteAddress = &(pClassifyValues->incomingValue[FWPS_FIELD_DATAGRAM_DATA_V4_IP_REMOTE_ADDRESS].value.uint32);

               injectionHandle = g_IPv4OutboundTransportInjectionHandle;
            }
      
            break;
         }
         case FWPS_LAYER_DATAGRAM_DATA_V6:
         {
            addressFamily = AF_INET6;

            direction = (FWP_DIRECTION)pClassifyValues->incomingValue[FWPS_FIELD_DATAGRAM_DATA_V6_DIRECTION].value.uint32;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_DATAGRAM_DATA_V6_FLAGS].value.uint32;

            if(direction == FWP_DIRECTION_INBOUND)
            {
               interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_DATAGRAM_DATA_V6_INTERFACE_INDEX].value.uint32;

               subInterfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_DATAGRAM_DATA_V6_SUB_INTERFACE_INDEX].value.uint32;

               injectionHandle = g_IPv6InboundTransportInjectionHandle;

               if(pClassifyValues->incomingValue[FWPS_FIELD_DATAGRAM_DATA_V6_IP_PROTOCOL].value.uint8 == ICMPV6)
                  bytesRetreated = ipHeaderSize;
               else
                  bytesRetreated = ipHeaderSize + transportHeaderSize;
            }
            else
            {
               pRemoteAddress = pClassifyValues->incomingValue[FWPS_FIELD_DATAGRAM_DATA_V6_IP_REMOTE_ADDRESS].value.byteArray16->byteArray16;

               injectionHandle = g_IPv6OutboundTransportInjectionHandle;
            }

            break;
         }
         case FWPS_LAYER_INBOUND_ICMP_ERROR_V4:
         {
            addressFamily = AF_INET;

            interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_ICMP_ERROR_V4_INTERFACE_INDEX].value.uint32;

            subInterfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_ICMP_ERROR_V4_SUB_INTERFACE_INDEX].value.uint32;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_ICMP_ERROR_V4_FLAGS].value.uint32;

            injectionHandle = g_IPv4InboundTransportInjectionHandle;

            bytesRetreated = ipHeaderSize + transportHeaderSize;

            break;
         }
         case FWPS_LAYER_INBOUND_ICMP_ERROR_V6:
         {
            addressFamily = AF_INET6;

            interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_ICMP_ERROR_V6_INTERFACE_INDEX].value.uint32;

            subInterfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_ICMP_ERROR_V6_SUB_INTERFACE_INDEX].value.uint32;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_ICMP_ERROR_V6_FLAGS].value.uint32;

            injectionHandle = g_IPv6InboundTransportInjectionHandle;

            bytesRetreated = ipHeaderSize + transportHeaderSize;

            break;
         }
         case FWPS_LAYER_OUTBOUND_ICMP_ERROR_V4:
         {
            addressFamily = AF_INET;

            pRemoteAddress = &(pClassifyValues->incomingValue[FWPS_FIELD_OUTBOUND_ICMP_ERROR_V4_IP_REMOTE_ADDRESS].value.uint32);

            flags = pClassifyValues->incomingValue[FWPS_FIELD_OUTBOUND_ICMP_ERROR_V4_FLAGS].value.uint32;

            injectionHandle = g_IPv4OutboundTransportInjectionHandle;

            bytesRetreated = ipHeaderSize;

            break;
         }
         case FWPS_LAYER_OUTBOUND_ICMP_ERROR_V6:
         {
            addressFamily = AF_INET6;

            pRemoteAddress = pClassifyValues->incomingValue[FWPS_FIELD_OUTBOUND_ICMP_ERROR_V6_IP_REMOTE_ADDRESS].value.byteArray16->byteArray16;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_OUTBOUND_ICMP_ERROR_V6_FLAGS].value.uint32;

            injectionHandle = g_IPv6OutboundTransportInjectionHandle;

            bytesRetreated = ipHeaderSize;

            break;
         }
         case FWPS_LAYER_ALE_AUTH_RECV_ACCEPT_V4:
         {
            addressFamily = AF_INET;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_FLAGS].value.uint32;

            if(direction == FWP_DIRECTION_OUTBOUND)
            {
               pRemoteAddress = &(pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_IP_REMOTE_ADDRESS].value.uint32);

               injectionHandle = g_IPv4OutboundTransportInjectionHandle;
            }
            else
            {
               interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_INTERFACE_INDEX].value.uint32;
               
               subInterfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_SUB_INTERFACE_INDEX].value.uint32;

               injectionHandle = g_IPv4InboundTransportInjectionHandle;

               if(pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_IP_PROTOCOL].value.uint8 == ICMPV4)
                  bytesRetreated = ipHeaderSize;
               else
                  bytesRetreated = ipHeaderSize + transportHeaderSize;
            }

            break;
         }
         case FWPS_LAYER_ALE_AUTH_RECV_ACCEPT_V6:
         {
            addressFamily = AF_INET6;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V6_FLAGS].value.uint32;

            if(direction == FWP_DIRECTION_OUTBOUND)
            {
               pRemoteAddress = pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V6_IP_REMOTE_ADDRESS].value.byteArray16->byteArray16;

               injectionHandle = g_IPv6OutboundTransportInjectionHandle;
            }
            else
            {
               interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V6_INTERFACE_INDEX].value.uint32;
               
               subInterfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V6_SUB_INTERFACE_INDEX].value.uint32;

               injectionHandle = g_IPv6InboundTransportInjectionHandle;

               if(pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V6_IP_PROTOCOL].value.uint8 == ICMPV6)
                  bytesRetreated = ipHeaderSize;
               else
                  bytesRetreated = ipHeaderSize + transportHeaderSize;
            }
      
            break;
         }
         case FWPS_LAYER_ALE_AUTH_CONNECT_V4:
         {
            addressFamily = AF_INET;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_CONNECT_V4_FLAGS].value.uint32;

            bytesRetreated = ipHeaderSize + transportHeaderSize;

            if(direction == FWP_DIRECTION_INBOUND)
            {
               interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_CONNECT_V4_INTERFACE_INDEX].value.uint32;

               subInterfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_CONNECT_V4_SUB_INTERFACE_INDEX].value.uint32;

               injectionHandle = g_IPv4InboundTransportInjectionHandle;
            }
            else
            {
               pRemoteAddress = &(pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_CONNECT_V4_IP_REMOTE_ADDRESS].value.uint32);

               injectionHandle = g_IPv4OutboundTransportInjectionHandle;
            }

            break;
         }
         case FWPS_LAYER_ALE_AUTH_CONNECT_V6:
         {
            addressFamily = AF_INET6;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_CONNECT_V6_FLAGS].value.uint32;

            bytesRetreated = ipHeaderSize + transportHeaderSize;

            if(direction == FWP_DIRECTION_INBOUND)
            {
               interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_CONNECT_V6_INTERFACE_INDEX].value.uint32;

               subInterfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_CONNECT_V6_SUB_INTERFACE_INDEX].value.uint32;

               injectionHandle = g_IPv6InboundTransportInjectionHandle;
            }
            else
            {
               pRemoteAddress = pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_CONNECT_V6_IP_REMOTE_ADDRESS].value.byteArray16->byteArray16;

               injectionHandle = g_IPv6OutboundTransportInjectionHandle;
            }

            break;
         }
         case FWPS_LAYER_ALE_FLOW_ESTABLISHED_V4:
         {
            addressFamily = AF_INET;

            direction = (FWP_DIRECTION)pClassifyValues->incomingValue[FWPS_FIELD_ALE_FLOW_ESTABLISHED_V4_DIRECTION].value.uint8;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_ALE_FLOW_ESTABLISHED_V4_FLAGS].value.uint32;

            if(direction == FWP_DIRECTION_INBOUND)
            {
               injectionHandle = g_IPv4InboundTransportInjectionHandle;

               if(pClassifyValues->incomingValue[FWPS_FIELD_ALE_FLOW_ESTABLISHED_V4_IP_PROTOCOL].value.uint8 == ICMPV4)
                  bytesRetreated = ipHeaderSize;
               else
                  bytesRetreated = ipHeaderSize + transportHeaderSize;
            }
            else
            {
               pRemoteAddress = &(pClassifyValues->incomingValue[FWPS_FIELD_ALE_FLOW_ESTABLISHED_V6_IP_REMOTE_ADDRESS].value.uint32);

               injectionHandle = g_IPv4OutboundTransportInjectionHandle;

               bytesRetreated = ipHeaderSize;
            }
      
            break;
         }
         case FWPS_LAYER_ALE_FLOW_ESTABLISHED_V6:
         {
            addressFamily = AF_INET6;

            direction = (FWP_DIRECTION)pClassifyValues->incomingValue[FWPS_FIELD_ALE_FLOW_ESTABLISHED_V6_DIRECTION].value.uint8;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_ALE_FLOW_ESTABLISHED_V6_FLAGS].value.uint32;

            if(direction == FWP_DIRECTION_INBOUND)
            {
               injectionHandle = g_IPv6InboundTransportInjectionHandle;

               if(pClassifyValues->incomingValue[FWPS_FIELD_ALE_FLOW_ESTABLISHED_V6_IP_PROTOCOL].value.uint8 == ICMPV6)
                  bytesRetreated = ipHeaderSize;
               else
                  bytesRetreated = ipHeaderSize + transportHeaderSize;
            }
            else
            {
               pRemoteAddress = pClassifyValues->incomingValue[FWPS_FIELD_ALE_FLOW_ESTABLISHED_V6_IP_REMOTE_ADDRESS].value.byteArray16->byteArray16;

               injectionHandle = g_IPv6OutboundTransportInjectionHandle;

               bytesRetreated = ipHeaderSize;
            }

            break;
         }
         case FWPS_LAYER_STREAM_PACKET_V4:
         {
            addressFamily = AF_INET;

            direction = (FWP_DIRECTION)pClassifyValues->incomingValue[FWPS_FIELD_STREAM_PACKET_V4_DIRECTION].value.uint8;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_STREAM_PACKET_V4_FLAGS].value.uint32;
   
            if(direction == FWP_DIRECTION_INBOUND)
            {
               interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_STREAM_PACKET_V4_INTERFACE_INDEX].value.uint32;

               subInterfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_STREAM_PACKET_V4_SUB_INTERFACE_INDEX].value.uint32;

               injectionHandle = g_IPv4InboundTransportInjectionHandle;

               bytesRetreated = ipHeaderSize + transportHeaderSize;
            }
            else
            {
               pRemoteAddress = &(pClassifyValues->incomingValue[FWPS_FIELD_STREAM_PACKET_V4_IP_REMOTE_ADDRESS].value.uint32);
            
               injectionHandle = g_IPv4OutboundTransportInjectionHandle;

               bytesRetreated = ipHeaderSize;
            }

            break;
         }
         case FWPS_LAYER_STREAM_PACKET_V6:
         {
            addressFamily = AF_INET6;

            direction = (FWP_DIRECTION)pClassifyValues->incomingValue[FWPS_FIELD_STREAM_PACKET_V6_DIRECTION].value.uint8;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_STREAM_PACKET_V6_FLAGS].value.uint32;

            if(direction == FWP_DIRECTION_INBOUND)
            {
               interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_STREAM_PACKET_V6_INTERFACE_INDEX].value.uint32;

               subInterfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_STREAM_PACKET_V6_SUB_INTERFACE_INDEX].value.uint32;

               injectionHandle = g_IPv6InboundTransportInjectionHandle;

               bytesRetreated = ipHeaderSize + transportHeaderSize;
            }
            else
            {
               pRemoteAddress = pClassifyValues->incomingValue[FWPS_FIELD_STREAM_PACKET_V6_IP_REMOTE_ADDRESS].value.byteArray16->byteArray16;
            
               injectionHandle = g_IPv6OutboundTransportInjectionHandle;

               bytesRetreated = ipHeaderSize;
            }

            break;
         }
      
#if(NTDDI_VERSION >= NTDDI_WIN8)
      
         case FWPS_LAYER_INBOUND_MAC_FRAME_ETHERNET:
         {
            UINT16 etherType = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_MAC_FRAME_ETHERNET_ETHER_TYPE].value.uint16;

            interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_MAC_FRAME_ETHERNET_INTERFACE_INDEX].value.uint32;

            ndisPort = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_MAC_FRAME_ETHERNET_NDIS_PORT].value.uint32;

            if(etherType == 0x86DD)
            {
               addressFamily = AF_INET6;

               injectionHandle = g_IPv6InboundMACInjectionHandle;
            }
            else if(etherType == 0x800)
            {
               addressFamily = AF_INET;

               injectionHandle = g_IPv4InboundMACInjectionHandle;
            }
            else
               injectionHandle = g_InboundMACInjectionHandle;
 
            bytesRetreated = ethernetHeaderSize;

            break;
         }
         case FWPS_LAYER_OUTBOUND_MAC_FRAME_ETHERNET:
         {
            UINT16 etherType = pClassifyValues->incomingValue[FWPS_FIELD_OUTBOUND_MAC_FRAME_ETHERNET_ETHER_TYPE].value.uint16;

            interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_OUTBOUND_MAC_FRAME_ETHERNET_INTERFACE_INDEX].value.uint32;

            ndisPort = pClassifyValues->incomingValue[FWPS_FIELD_OUTBOUND_MAC_FRAME_ETHERNET_NDIS_PORT].value.uint32;

            if(etherType == 0x86DD)
            {
               addressFamily = AF_INET6;

               injectionHandle = g_IPv6OutboundMACInjectionHandle;
            }
            else if(etherType == 0x800)
            {
               addressFamily = AF_INET;

               injectionHandle = g_IPv4OutboundMACInjectionHandle;
            }
            else
               injectionHandle = g_OutboundMACInjectionHandle;

            break;
         }
         case FWPS_LAYER_INBOUND_MAC_FRAME_NATIVE:
         {
            interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_MAC_FRAME_NATIVE_INTERFACE_INDEX].value.uint32;

            ndisPort = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_MAC_FRAME_NATIVE_NDIS_PORT].value.uint32;

            injectionHandle = g_InboundMACInjectionHandle;

            break;
         }
         case FWPS_LAYER_OUTBOUND_MAC_FRAME_NATIVE:
         {
            interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_OUTBOUND_MAC_FRAME_NATIVE_INTERFACE_INDEX].value.uint32;

            ndisPort = pClassifyValues->incomingValue[FWPS_FIELD_OUTBOUND_MAC_FRAME_NATIVE_NDIS_PORT].value.uint32;

            injectionHandle = g_OutboundMACInjectionHandle;
   
            break;
         }
         case FWPS_LAYER_INGRESS_VSWITCH_ETHERNET:
         {
            UINT16 etherType = pClassifyValues->incomingValue[FWPS_FIELD_INGRESS_VSWITCH_ETHERNET_ETHER_TYPE].value.uint16;

            pVSwitchID = pClassifyValues->incomingValue[FWPS_FIELD_INGRESS_VSWITCH_ETHERNET_VSWITCH_ID].value.byteBlob;

            if(etherType == 0x86DD)
            {
               addressFamily   = AF_INET6;

               injectionHandle = g_IPv6IngressVSwitchEthernetInjectionHandle;
            }
            else if(etherType == 0x800)
            {
               addressFamily   = AF_INET;

               injectionHandle = g_IPv4IngressVSwitchEthernetInjectionHandle;
            }
            else
               injectionHandle = g_IngressVSwitchEthernetInjectionHandle;
   
            break;
         }
         case FWPS_LAYER_EGRESS_VSWITCH_ETHERNET:
         {
            UINT16 etherType = pClassifyValues->incomingValue[FWPS_FIELD_EGRESS_VSWITCH_ETHERNET_ETHER_TYPE].value.uint16;

            pVSwitchID = pClassifyValues->incomingValue[FWPS_FIELD_EGRESS_VSWITCH_ETHERNET_VSWITCH_ID].value.byteBlob;

            if(etherType == 0x86DD)
            {
               addressFamily   = AF_INET6;

               injectionHandle = g_IPv6EgressVSwitchEthernetInjectionHandle;
            }
            else if(etherType == 0x800)
            {
               addressFamily   = AF_INET;

               injectionHandle = g_IPv4EgressVSwitchEthernetInjectionHandle;
            }
            else
               injectionHandle = g_EgressVSwitchEthernetInjectionHandle;
   
            break;
         }
         
#endif // (NTDDI_VERSION >= NTDDI_WIN8)

      }

      pClassifyOut->actionType = FWP_ACTION_PERMIT;

      if(!((flags & FWP_CONDITION_FLAG_IS_LOOPBACK ||
         (flags & FWP_CONDITION_FLAG_IS_IPSEC_SECURED &&
         (flags & FWP_CONDITION_FLAG_REQUIRES_ALE_CLASSIFY ||
         isALEClassifyRequired)))))
      {
         injectionState = FwpsQueryPacketInjectionState(injectionHandle,
                                                        (NET_BUFFER_LIST*)pNetBufferList,
                                                        &injectionContext);
         if(injectionState != FWPS_PACKET_INJECTED_BY_SELF &&
            injectionState != FWPS_PACKET_PREVIOUSLY_INJECTED_BY_SELF)
         {
            pClassifyOut->actionType  = FWP_ACTION_BLOCK;
            pClassifyOut->flags      |= FWPS_CLASSIFY_OUT_FLAG_ABSORB;
            pClassifyOut->rights     ^= FWPS_RIGHT_ACTION_WRITE;

            if(bytesRetreated)
            {
               status = NdisRetreatNetBufferDataStart(NET_BUFFER_LIST_FIRST_NB((NET_BUFFER_LIST*)pNetBufferList),
                                                      bytesRetreated,
                                                      0,
                                                      0);
               HLPR_BAIL_ON_FAILURE(status);
            }

            status = FwpsAllocateCloneNetBufferList((NET_BUFFER_LIST*)pNetBufferList,
                                                    g_pNDISPoolData->nblPoolHandle,
                                                    g_pNDISPoolData->nbPoolHandle,
                                                    0,
                                                    &pClonedNetBufferList);

            if(bytesRetreated)
               NdisAdvanceNetBufferDataStart(NET_BUFFER_LIST_FIRST_NB((NET_BUFFER_LIST*)pNetBufferList),
                                             bytesRetreated,
                                             FALSE,
                                             0);

            HLPR_BAIL_ON_FAILURE(status);

            if(injectionHandle == g_IPv4InboundNetworkInjectionHandle ||
               injectionHandle == g_IPv6InboundNetworkInjectionHandle)
               status = FwpsInjectNetworkReceiveAsync(injectionHandle,
                                                      injectionContext,
                                                      0,
                                                      compartmentID,
                                                      interfaceIndex,
                                                      subInterfaceIndex,
                                                      pClonedNetBufferList,
                                                      CompleteFastPacketInjection,
                                                      0);
            else if(injectionHandle == g_IPv4OutboundNetworkInjectionHandle ||
                    injectionHandle == g_IPv6OutboundNetworkInjectionHandle)
               status = FwpsInjectNetworkSendAsync(injectionHandle,
                                                   injectionContext,
                                                   0,
                                                   compartmentID,
                                                   pClonedNetBufferList,
                                                   CompleteFastPacketInjection,
                                                   0);
            else if(injectionHandle == g_IPv4InboundForwardInjectionHandle ||
                    injectionHandle == g_IPv6InboundForwardInjectionHandle ||
                    injectionHandle == g_IPv4OutboundForwardInjectionHandle ||
                    injectionHandle == g_IPv6OutboundForwardInjectionHandle)
               status = FwpsInjectForwardAsync(injectionHandle,
                                               injectionContext,
                                               0,
                                               addressFamily,
                                               compartmentID,
                                               interfaceIndex,
                                               pClonedNetBufferList,
                                               CompleteFastPacketInjection,
                                               0);
            else if(injectionHandle == g_IPv4InboundTransportInjectionHandle ||
                    injectionHandle == g_IPv6InboundTransportInjectionHandle)
               status = FwpsInjectTransportReceiveAsync(injectionHandle,
                                                        injectionContext,
                                                        0,
                                                        0,
                                                        addressFamily,
                                                        compartmentID,
                                                        interfaceIndex,
                                                        subInterfaceIndex,
                                                        pClonedNetBufferList,
                                                        CompleteFastPacketInjection,
                                                        0);
            else if(injectionHandle == g_IPv4OutboundTransportInjectionHandle ||
                    injectionHandle == g_IPv6OutboundTransportInjectionHandle)
            {
               FWPS_TRANSPORT_SEND_PARAMS* pSendParams = 0;
               UINT32                      addressSize = addressFamily == AF_INET ? IPV4_ADDRESS_SIZE : IPV6_ADDRESS_SIZE;

#pragma warning(push)
#pragma warning(disable: 6014) /// pSendParams will be freed in completionFn using FastPacketInjectionCompletionDataDestroy

               HLPR_NEW(pSendParams,
                        FWPS_TRANSPORT_SEND_PARAMS,
                        WFPSAMPLER_CALLOUT_DRIVER_TAG);
               HLPR_BAIL_ON_ALLOC_FAILURE_2(pSendParams,
                                            status);

               HLPR_NEW_ARRAY(pSendParams->remoteAddress,
                              BYTE,
                              addressSize,
                              WFPSAMPLER_CALLOUT_DRIVER_TAG);
               HLPR_BAIL_ON_ALLOC_FAILURE_2(pSendParams->remoteAddress,
                                            status);

#pragma warning(pop)

               if(addressFamily == AF_INET)
               {
                  UINT32 remoteAddress = *((UINT32*)pRemoteAddress);

                  remoteAddress = ntohl(remoteAddress);

                  RtlCopyMemory(pSendParams->remoteAddress,
                                &remoteAddress,
                                addressSize);
               }
               else
               {
                  RtlCopyMemory(pSendParams->remoteAddress,
                                pRemoteAddress,
                                addressSize);

                  if(FWPS_IS_METADATA_FIELD_PRESENT(pMetadata,
                                                    FWPS_METADATA_FIELD_REMOTE_SCOPE_ID))
                     pSendParams->remoteScopeId = pMetadata->remoteScopeId;
               }

               status = FwpsInjectTransportSendAsync(injectionHandle,
                                                     injectionContext,
                                                     endpointHandle,
                                                     0,
                                                     pSendParams,
                                                     addressFamily,
                                                     compartmentID,
                                                     pClonedNetBufferList,
                                                     CompleteFastPacketInjection,
                                                     pSendParams);

               HLPR_BAIL_LABEL_2:

               if(status != STATUS_SUCCESS)
               {
#pragma warning(push)
#pragma warning(disable: 28924) /// pSendParams could be NULL if the ALLOC fails

                  if(pSendParams)
                  {
                     HLPR_DELETE_ARRAY(pSendParams->remoteAddress,
                                       WFPSAMPLER_CALLOUT_DRIVER_TAG);
                  }

                  HLPR_DELETE(pSendParams,
                              WFPSAMPLER_CALLOUT_DRIVER_TAG);

#pragma warning(pop)
               }
            }

#if(NTDDI_VERSION >= NTDDI_WIN8)

            else if(injectionHandle == g_IPv4InboundMACInjectionHandle ||
                    injectionHandle == g_IPv6InboundMACInjectionHandle ||
                    injectionHandle == g_InboundMACInjectionHandle)
               status = FwpsInjectMacReceiveAsync(injectionHandle,
                                                  injectionContext,
                                                  0,
                                                  pClassifyValues->layerId,
                                                  interfaceIndex,
                                                  ndisPort,
                                                  pClonedNetBufferList,
                                                  CompleteFastPacketInjection,
                                                  0);
            else if(injectionHandle == g_IPv4OutboundMACInjectionHandle ||
                    injectionHandle == g_IPv6OutboundMACInjectionHandle ||
                    injectionHandle == g_OutboundMACInjectionHandle)
               status = FwpsInjectMacSendAsync(injectionHandle,
                                               injectionContext,
                                               0,
                                               pClassifyValues->layerId,
                                               interfaceIndex,
                                               ndisPort,
                                               pClonedNetBufferList,
                                               CompleteFastPacketInjection,
                                               0);
            else if(injectionHandle == g_IPv4IngressVSwitchEthernetInjectionHandle ||
                    injectionHandle == g_IPv6IngressVSwitchEthernetInjectionHandle ||
                    injectionHandle == g_IngressVSwitchEthernetInjectionHandle ||
                    injectionHandle == g_IPv4EgressVSwitchEthernetInjectionHandle ||
                    injectionHandle == g_IPv6EgressVSwitchEthernetInjectionHandle ||
                    injectionHandle == g_EgressVSwitchEthernetInjectionHandle)
               status = FwpsInjectvSwitchEthernetIngressAsync(injectionHandle,
                                                              injectionContext,
                                                              0,
                                                              0,
                                                              pVSwitchID,
                                                              sourcePortID,
                                                              sourceNICIndex,
                                                              pClonedNetBufferList,
                                                              CompleteFastPacketInjection,
                                                              0);

#endif ///(NTDDI_VERSION >= NTDDI_WIN8)

            HLPR_BAIL_LABEL:
            
            if(status != STATUS_SUCCESS)
            {
               if(pClonedNetBufferList)
                  FwpsFreeCloneNetBufferList(pClonedNetBufferList,
                                             0);

               DbgPrintEx(DPFLTR_IHVNETWORK_ID,
                          DPFLTR_ERROR_LEVEL,
                          " !!!! ClassifyFastPacketInjection : FwpsInjectAsync() [status: %#x]\n",
                          status);
            }
         }
      }
   }

   return;
}

#else

/**
 @classify_function="ClassifyFastPacketInjection"
 
   Purpose:  Blocks the current NET_BUFFER_LIST and injects a clone back to the stack without 
             modification.                                                                      <br>
                                                                                                <br>
   Notes:    Applies to the following layers:                                                   <br>
                FWPS_LAYER_INBOUND_IPPACKET_V{4/6}                                              <br>
                FWPS_LAYER_OUTBOUND_IPPACKET_V{4/6}                                             <br>
                FWPS_LAYER_IPFORWARD_V{4/6}                                                     <br>
                FWPS_LAYER_INBOUND_TRANSPORT_V{4/6}                                             <br>
                FWPS_LAYER_OUTBOUND_TRANSPORT_V{4/6}                                            <br>
                FWPS_LAYER_DATAGRAM_DATA_V{4/6}                                                 <br>
                FWPS_LAYER_INBOUND_ICMP_ERROR_V{4/6}                                            <br>
                FWPS_LAYER_OUTBOUND_ICMP_ERROR_V{4/6}                                           <br>
                FWPS_LAYER_ALE_AUTH_CONNECT_V{4/6}                                              <br>
                FWPS_LAYER_ALE_FLOW_ESTABLISHED_V{4/6}                                          <br>
                                                                                                <br>
             Intended for test performance purposes only.                                       <br>
                                                                                                <br>
   MSDN_Ref: HTTP://MSDN.Microsoft.com/En-US/Library/Windows/Hardware/FF544890.aspx             <br>
             HTTP://MSDN.Microsoft.com/En-US/Library/Windows/Hardware/FF551202.aspx             <br>
             HTTP://MSDN.Microsoft.com/En-US/Library/Windows/Hardware/FF551134.aspx             <br>
             HTTP://MSDN.Microsoft.com/En-US/Library/Windows/Hardware/FF551183.aspx             <br>
             HTTP://MSDN.Microsoft.com/En-US/Library/Windows/Hardware/FF551185.aspx             <br>
             HTTP://MSDN.Microsoft.com/En-US/Library/Windows/Hardware/FF551177.aspx             <br>
             HTTP://MSDN.Microsoft.com/En-US/Library/Windows/Hardware/FF551186.aspx             <br>
             HTTP://MSDN.Microsoft.com/En-US/Library/Windows/Hardware/FF551188.aspx             <br>
             HTTP://MSDN.Microsoft.com/En-US/Library/Windows/Hardware/FF551170.aspx             <br>
*/
_IRQL_requires_min_(PASSIVE_LEVEL)
_IRQL_requires_max_(DISPATCH_LEVEL)
_IRQL_requires_same_
VOID ClassifyFastPacketInjection(_In_ const FWPS_INCOMING_VALUES* pClassifyValues,
                                  _In_ const FWPS_INCOMING_METADATA_VALUES0* pMetadata,
                                  _Inout_opt_ VOID* pNetBufferList,
                                  _In_ const FWPS_FILTER* pFilter,
                                  _In_ UINT64 flowContext,
                                  _Inout_ FWPS_CLASSIFY_OUT* pClassifyOut)
{
   UNREFERENCED_PARAMETER(pFilter);
   UNREFERENCED_PARAMETER(flowContext);

   if(pClassifyOut->rights & FWPS_RIGHT_ACTION_WRITE)
   {
      NTSTATUS                    status                = STATUS_SUCCESS;
      UINT32                      ipHeaderSize          = 0;
      UINT32                      transportHeaderSize   = 0;
      COMPARTMENT_ID              compartmentID         = UNSPECIFIED_COMPARTMENT_ID;
      UINT64                      endpointHandle        = 0;
      ADDRESS_FAMILY              addressFamily         = AF_UNSPEC;
      FWP_DIRECTION               direction             = FWP_DIRECTION_MAX;
      UINT32                      flags                 = 0;
      BOOLEAN                     isALEClassifyRequired = FALSE;
      VOID*                       pRemoteAddress        = 0;
      IF_INDEX                    interfaceIndex        = 0;
      IF_INDEX                    subInterfaceIndex     = 0;
      HANDLE                      injectionHandle       = 0;
      FWPS_PACKET_INJECTION_STATE injectionState        = FWPS_PACKET_INJECTION_STATE_MAX;
      HANDLE                      injectionContext      = 0;
      UINT32                      bytesRetreated        = 0;
      NET_BUFFER_LIST*            pClonedNetBufferList  = 0;

      if(FWPS_IS_METADATA_FIELD_PRESENT(pMetadata,
                                        FWPS_METADATA_FIELD_IP_HEADER_SIZE))
         ipHeaderSize = pMetadata->ipHeaderSize;

      if(FWPS_IS_METADATA_FIELD_PRESENT(pMetadata,
                                        FWPS_METADATA_FIELD_TRANSPORT_HEADER_SIZE))
         transportHeaderSize = pMetadata->transportHeaderSize;

      if(FWPS_IS_METADATA_FIELD_PRESENT(pMetadata,
                                        FWPS_METADATA_FIELD_COMPARTMENT_ID))
         compartmentID = (COMPARTMENT_ID)pMetadata->compartmentId;

      if(FWPS_IS_METADATA_FIELD_PRESENT(pMetadata,
                                        FWPS_METADATA_FIELD_TRANSPORT_ENDPOINT_HANDLE))
         endpointHandle = pMetadata->transportEndpointHandle;

      if(FWPS_IS_METADATA_FIELD_PRESENT(pMetadata,
                                        FWPS_METADATA_FIELD_PACKET_DIRECTION))
         direction = pMetadata->packetDirection;

      if(FWPS_IS_METADATA_FIELD_PRESENT(pMetadata,
                                        FWPS_METADATA_FIELD_ALE_CLASSIFY_REQUIRED))
         isALEClassifyRequired = TRUE;

      switch(pClassifyValues->layerId)
      {
         case FWPS_LAYER_INBOUND_IPPACKET_V4:
         {
            addressFamily = AF_INET;

            interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_IPPACKET_V4_INTERFACE_INDEX].value.uint32;

            subInterfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_IPPACKET_V4_SUB_INTERFACE_INDEX].value.uint32;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_IPPACKET_V4_FLAGS].value.uint32;

            injectionHandle = g_IPv4InboundNetworkInjectionHandle;

            bytesRetreated = ipHeaderSize;

            break;
         }
         case FWPS_LAYER_INBOUND_IPPACKET_V6:
         {
            addressFamily = AF_INET6;

            interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_IPPACKET_V6_INTERFACE_INDEX].value.uint32;

            subInterfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_IPPACKET_V6_SUB_INTERFACE_INDEX].value.uint32;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_IPPACKET_V6_FLAGS].value.uint32;

            injectionHandle = g_IPv6InboundNetworkInjectionHandle;

            bytesRetreated = ipHeaderSize;

            break;
         }
         case FWPS_LAYER_OUTBOUND_IPPACKET_V4:
         {
            addressFamily = AF_INET;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_OUTBOUND_IPPACKET_V4_FLAGS].value.uint32;

            injectionHandle = g_IPv4OutboundNetworkInjectionHandle;
      
            break;
         }
         case FWPS_LAYER_OUTBOUND_IPPACKET_V6:
         {
            addressFamily = AF_INET6;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_OUTBOUND_IPPACKET_V6_FLAGS].value.uint32;

            injectionHandle = g_IPv6OutboundNetworkInjectionHandle;
      
            break;
         }
         case FWPS_LAYER_IPFORWARD_V4:
         {
            addressFamily = AF_INET;

            interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_IPFORWARD_V4_DESTINATION_INTERFACE_INDEX].value.uint32;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_IPFORWARD_V4_FLAGS].value.uint32;

            if(direction == FWP_DIRECTION_OUTBOUND)
               injectionHandle = g_IPv4OutboundForwardInjectionHandle;
            else
               injectionHandle = g_IPv4InboundForwardInjectionHandle;
      
            break;
         }
         case FWPS_LAYER_IPFORWARD_V6:
         {
            addressFamily = AF_INET6;

            interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_IPFORWARD_V6_DESTINATION_INTERFACE_INDEX].value.uint32;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_IPFORWARD_V6_FLAGS].value.uint32;

            if(direction == FWP_DIRECTION_OUTBOUND)
               injectionHandle = g_IPv6OutboundForwardInjectionHandle;
            else
               injectionHandle = g_IPv6InboundForwardInjectionHandle;
      
            break;
         }
         case FWPS_LAYER_INBOUND_TRANSPORT_V4:
         {
            addressFamily = AF_INET;

            interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_TRANSPORT_V4_INTERFACE_INDEX].value.uint32;

            subInterfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_TRANSPORT_V4_SUB_INTERFACE_INDEX].value.uint32;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_TRANSPORT_V4_FLAGS].value.uint32;

            injectionHandle = g_IPv4InboundTransportInjectionHandle;

            if(pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_TRANSPORT_V4_IP_PROTOCOL].value.uint8 == ICMPV4)
               bytesRetreated = ipHeaderSize;
            else
               bytesRetreated = ipHeaderSize + transportHeaderSize;

            break;
         }
         case FWPS_LAYER_INBOUND_TRANSPORT_V6:
         {
            addressFamily = AF_INET6;

            interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_TRANSPORT_V6_INTERFACE_INDEX].value.uint32;

            subInterfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_TRANSPORT_V6_SUB_INTERFACE_INDEX].value.uint32;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_TRANSPORT_V6_FLAGS].value.uint32;

            injectionHandle = g_IPv6InboundTransportInjectionHandle;

            if(pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_TRANSPORT_V6_IP_PROTOCOL].value.uint8 == ICMPV6)
               bytesRetreated = ipHeaderSize;
            else
               bytesRetreated = ipHeaderSize + transportHeaderSize;

            break;
         }
         case FWPS_LAYER_OUTBOUND_TRANSPORT_V4:
         {
            addressFamily = AF_INET;

            pRemoteAddress = &(pClassifyValues->incomingValue[FWPS_FIELD_OUTBOUND_TRANSPORT_V4_IP_REMOTE_ADDRESS].value.uint32);

            flags = pClassifyValues->incomingValue[FWPS_FIELD_OUTBOUND_TRANSPORT_V4_FLAGS].value.uint32;

            injectionHandle = g_IPv4OutboundTransportInjectionHandle;
      
            break;
         }
         case FWPS_LAYER_OUTBOUND_TRANSPORT_V6:
         {
            addressFamily = AF_INET6;

            pRemoteAddress = pClassifyValues->incomingValue[FWPS_FIELD_OUTBOUND_TRANSPORT_V6_IP_REMOTE_ADDRESS].value.byteArray16->byteArray16;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_OUTBOUND_TRANSPORT_V6_FLAGS].value.uint32;

            injectionHandle = g_IPv6OutboundTransportInjectionHandle;
      
            break;
         }
         case FWPS_LAYER_DATAGRAM_DATA_V4:
         {
            addressFamily = AF_INET;

            direction = (FWP_DIRECTION)pClassifyValues->incomingValue[FWPS_FIELD_DATAGRAM_DATA_V4_DIRECTION].value.uint32;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_DATAGRAM_DATA_V4_FLAGS].value.uint32;

            if(direction == FWP_DIRECTION_INBOUND)
            {
               interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_DATAGRAM_DATA_V4_INTERFACE_INDEX].value.uint32;

               subInterfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_DATAGRAM_DATA_V4_SUB_INTERFACE_INDEX].value.uint32;

               injectionHandle = g_IPv4InboundTransportInjectionHandle;

               if(pClassifyValues->incomingValue[FWPS_FIELD_DATAGRAM_DATA_V4_IP_PROTOCOL].value.uint8 == ICMPV4)
                  bytesRetreated = ipHeaderSize;
               else
                  bytesRetreated = ipHeaderSize + transportHeaderSize;
            }
            else
            {
               pRemoteAddress = &(pClassifyValues->incomingValue[FWPS_FIELD_DATAGRAM_DATA_V4_IP_REMOTE_ADDRESS].value.uint32);

               injectionHandle = g_IPv4OutboundTransportInjectionHandle;
            }
      
            break;
         }
         case FWPS_LAYER_DATAGRAM_DATA_V6:
         {
            addressFamily = AF_INET6;

            direction = (FWP_DIRECTION)pClassifyValues->incomingValue[FWPS_FIELD_DATAGRAM_DATA_V6_DIRECTION].value.uint32;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_DATAGRAM_DATA_V6_FLAGS].value.uint32;

            if(direction == FWP_DIRECTION_INBOUND)
            {
               interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_DATAGRAM_DATA_V6_INTERFACE_INDEX].value.uint32;

               subInterfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_DATAGRAM_DATA_V6_SUB_INTERFACE_INDEX].value.uint32;

               injectionHandle = g_IPv6InboundTransportInjectionHandle;

               if(pClassifyValues->incomingValue[FWPS_FIELD_DATAGRAM_DATA_V6_IP_PROTOCOL].value.uint8 == ICMPV6)
                  bytesRetreated = ipHeaderSize;
               else
                  bytesRetreated = ipHeaderSize + transportHeaderSize;
            }
            else
            {
               pRemoteAddress = pClassifyValues->incomingValue[FWPS_FIELD_DATAGRAM_DATA_V6_IP_REMOTE_ADDRESS].value.byteArray16->byteArray16;

               injectionHandle = g_IPv6OutboundTransportInjectionHandle;
            }

            break;
         }
         case FWPS_LAYER_INBOUND_ICMP_ERROR_V4:
         {
            addressFamily = AF_INET;

            interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_ICMP_ERROR_V4_INTERFACE_INDEX].value.uint32;

            subInterfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_ICMP_ERROR_V4_SUB_INTERFACE_INDEX].value.uint32;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_ICMP_ERROR_V4_FLAGS].value.uint32;

            injectionHandle = g_IPv4InboundTransportInjectionHandle;

            bytesRetreated = ipHeaderSize + transportHeaderSize;

            break;
         }
         case FWPS_LAYER_INBOUND_ICMP_ERROR_V6:
         {
            addressFamily = AF_INET6;

            interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_ICMP_ERROR_V6_INTERFACE_INDEX].value.uint32;

            subInterfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_ICMP_ERROR_V6_SUB_INTERFACE_INDEX].value.uint32;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_INBOUND_ICMP_ERROR_V6_FLAGS].value.uint32;

            injectionHandle = g_IPv6InboundTransportInjectionHandle;

            bytesRetreated = ipHeaderSize + transportHeaderSize;

            break;
         }
         case FWPS_LAYER_OUTBOUND_ICMP_ERROR_V4:
         {
            addressFamily = AF_INET;

            pRemoteAddress = &(pClassifyValues->incomingValue[FWPS_FIELD_OUTBOUND_ICMP_ERROR_V4_IP_REMOTE_ADDRESS].value.uint32);

            flags = pClassifyValues->incomingValue[FWPS_FIELD_OUTBOUND_ICMP_ERROR_V4_FLAGS].value.uint32;

            injectionHandle = g_IPv4OutboundTransportInjectionHandle;

            bytesRetreated = ipHeaderSize;

            break;
         }
         case FWPS_LAYER_OUTBOUND_ICMP_ERROR_V6:
         {
            addressFamily = AF_INET6;

            pRemoteAddress = pClassifyValues->incomingValue[FWPS_FIELD_OUTBOUND_ICMP_ERROR_V6_IP_REMOTE_ADDRESS].value.byteArray16->byteArray16;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_OUTBOUND_ICMP_ERROR_V6_FLAGS].value.uint32;

            injectionHandle = g_IPv6OutboundTransportInjectionHandle;

            bytesRetreated = ipHeaderSize;

            break;
         }
         case FWPS_LAYER_ALE_AUTH_RECV_ACCEPT_V4:
         {
            addressFamily = AF_INET;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_FLAGS].value.uint32;

            if(direction == FWP_DIRECTION_OUTBOUND)
            {
               pRemoteAddress = &(pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_IP_REMOTE_ADDRESS].value.uint32);

               injectionHandle = g_IPv4OutboundTransportInjectionHandle;
            }
            else
            {
               interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_INTERFACE_INDEX].value.uint32;
               
               subInterfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_SUB_INTERFACE_INDEX].value.uint32;

               injectionHandle = g_IPv4InboundTransportInjectionHandle;

               if(pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V4_IP_PROTOCOL].value.uint8 == ICMPV4)
                  bytesRetreated = ipHeaderSize;
               else
                  bytesRetreated = ipHeaderSize + transportHeaderSize;
            }

            break;
         }
         case FWPS_LAYER_ALE_AUTH_RECV_ACCEPT_V6:
         {
            addressFamily = AF_INET6;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V6_FLAGS].value.uint32;

            if(direction == FWP_DIRECTION_OUTBOUND)
            {
               pRemoteAddress = pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V6_IP_REMOTE_ADDRESS].value.byteArray16->byteArray16;

               injectionHandle = g_IPv6OutboundTransportInjectionHandle;
            }
            else
            {
               interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V6_INTERFACE_INDEX].value.uint32;
               
               subInterfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V6_SUB_INTERFACE_INDEX].value.uint32;

               injectionHandle = g_IPv6InboundTransportInjectionHandle;

               if(pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_RECV_ACCEPT_V6_IP_PROTOCOL].value.uint8 == ICMPV6)
                  bytesRetreated = ipHeaderSize;
               else
                  bytesRetreated = ipHeaderSize + transportHeaderSize;
            }
      
            break;
         }
         case FWPS_LAYER_ALE_AUTH_CONNECT_V4:
         {
            addressFamily = AF_INET;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_CONNECT_V4_FLAGS].value.uint32;

            bytesRetreated = ipHeaderSize + transportHeaderSize;

            if(direction == FWP_DIRECTION_INBOUND)
            {
               interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_CONNECT_V4_INTERFACE_INDEX].value.uint32;

               subInterfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_CONNECT_V4_SUB_INTERFACE_INDEX].value.uint32;

               injectionHandle = g_IPv4InboundTransportInjectionHandle;
            }
            else
            {
               pRemoteAddress = &(pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_CONNECT_V4_IP_REMOTE_ADDRESS].value.uint32);

               injectionHandle = g_IPv4OutboundTransportInjectionHandle;
            }

            break;
         }
         case FWPS_LAYER_ALE_AUTH_CONNECT_V6:
         {
            addressFamily = AF_INET6;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_CONNECT_V6_FLAGS].value.uint32;

            bytesRetreated = ipHeaderSize + transportHeaderSize;

            if(direction == FWP_DIRECTION_INBOUND)
            {
               interfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_CONNECT_V6_INTERFACE_INDEX].value.uint32;

               subInterfaceIndex = pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_CONNECT_V6_SUB_INTERFACE_INDEX].value.uint32;

               injectionHandle = g_IPv6InboundTransportInjectionHandle;
            }
            else
            {
               pRemoteAddress = pClassifyValues->incomingValue[FWPS_FIELD_ALE_AUTH_CONNECT_V6_IP_REMOTE_ADDRESS].value.byteArray16->byteArray16;

               injectionHandle = g_IPv6OutboundTransportInjectionHandle;
            }

            break;
         }
         case FWPS_LAYER_ALE_FLOW_ESTABLISHED_V4:
         {
            addressFamily = AF_INET;

            direction = (FWP_DIRECTION)pClassifyValues->incomingValue[FWPS_FIELD_ALE_FLOW_ESTABLISHED_V4_DIRECTION].value.uint8;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_ALE_FLOW_ESTABLISHED_V4_FLAGS].value.uint32;

            if(direction == FWP_DIRECTION_INBOUND)
            {
               injectionHandle = g_IPv4InboundTransportInjectionHandle;

               if(pClassifyValues->incomingValue[FWPS_FIELD_ALE_FLOW_ESTABLISHED_V4_IP_PROTOCOL].value.uint8 == ICMPV4)
                  bytesRetreated = ipHeaderSize;
               else
                  bytesRetreated = ipHeaderSize + transportHeaderSize;
            }
            else
            {
               pRemoteAddress = &(pClassifyValues->incomingValue[FWPS_FIELD_ALE_FLOW_ESTABLISHED_V6_IP_REMOTE_ADDRESS].value.uint32);

               injectionHandle = g_IPv4OutboundTransportInjectionHandle;

               bytesRetreated = ipHeaderSize;
            }
      
            break;
         }
         case FWPS_LAYER_ALE_FLOW_ESTABLISHED_V6:
         {
            addressFamily = AF_INET6;

            direction = (FWP_DIRECTION)pClassifyValues->incomingValue[FWPS_FIELD_ALE_FLOW_ESTABLISHED_V6_DIRECTION].value.uint8;

            flags = pClassifyValues->incomingValue[FWPS_FIELD_ALE_FLOW_ESTABLISHED_V6_FLAGS].value.uint32;

            if(direction == FWP_DIRECTION_INBOUND)
            {
               injectionHandle = g_IPv6InboundTransportInjectionHandle;

               if(pClassifyValues->incomingValue[FWPS_FIELD_ALE_FLOW_ESTABLISHED_V6_IP_PROTOCOL].value.uint8 == ICMPV6)
                  bytesRetreated = ipHeaderSize;
               else
                  bytesRetreated = ipHeaderSize + transportHeaderSize;
            }
            else
            {
               pRemoteAddress = pClassifyValues->incomingValue[FWPS_FIELD_ALE_FLOW_ESTABLISHED_V6_IP_REMOTE_ADDRESS].value.byteArray16->byteArray16;

               injectionHandle = g_IPv6OutboundTransportInjectionHandle;

               bytesRetreated = ipHeaderSize;
            }

            break;
         }
      }

      pClassifyOut->actionType = FWP_ACTION_PERMIT;

      if(!((flags & FWP_CONDITION_FLAG_IS_LOOPBACK ||
         (flags & FWP_CONDITION_FLAG_IS_IPSEC_SECURED &&
         (flags & FWP_CONDITION_FLAG_REQUIRES_ALE_CLASSIFY ||
         isALEClassifyRequired)))))
      {
         injectionState = FwpsQueryPacketInjectionState(injectionHandle,
                                                        (NET_BUFFER_LIST*)pNetBufferList,
                                                        &injectionContext);
         if(injectionState != FWPS_PACKET_INJECTED_BY_SELF &&
            injectionState != FWPS_PACKET_PREVIOUSLY_INJECTED_BY_SELF)
         {
            pClassifyOut->actionType  = FWP_ACTION_BLOCK;
            pClassifyOut->flags      |= FWPS_CLASSIFY_OUT_FLAG_ABSORB;
            pClassifyOut->rights     ^= FWPS_RIGHT_ACTION_WRITE;


            if(bytesRetreated)
            {
               status = NdisRetreatNetBufferDataStart(NET_BUFFER_LIST_FIRST_NB((NET_BUFFER_LIST*)pNetBufferList),
                                                      bytesRetreated,
                                                      0,
                                                      0);
               HLPR_BAIL_ON_FAILURE(status);
            }

            status = FwpsAllocateCloneNetBufferList((NET_BUFFER_LIST*)pNetBufferList,
                                                    g_pNDISPoolData->nblPoolHandle,
                                                    g_pNDISPoolData->nbPoolHandle,
                                                    0,
                                                    &pClonedNetBufferList);

            if(bytesRetreated)
               NdisAdvanceNetBufferDataStart(NET_BUFFER_LIST_FIRST_NB((NET_BUFFER_LIST*)pNetBufferList),
                                             bytesRetreated,
                                             FALSE,
                                             0);

            HLPR_BAIL_ON_FAILURE(status);

            if(injectionHandle == g_IPv4InboundNetworkInjectionHandle ||
               injectionHandle == g_IPv6InboundNetworkInjectionHandle)
               status = FwpsInjectNetworkReceiveAsync(injectionHandle,
                                                      injectionContext,
                                                      0,
                                                      compartmentID,
                                                      interfaceIndex,
                                                      subInterfaceIndex,
                                                      pClonedNetBufferList,
                                                      CompleteFastPacketInjection,
                                                      0);
            else if(injectionHandle == g_IPv4OutboundNetworkInjectionHandle ||
                    injectionHandle == g_IPv6OutboundNetworkInjectionHandle)
               status = FwpsInjectNetworkSendAsync(injectionHandle,
                                                   injectionContext,
                                                   0,
                                                   compartmentID,
                                                   pClonedNetBufferList,
                                                   CompleteFastPacketInjection,
                                                   0);
            else if(injectionHandle == g_IPv4InboundForwardInjectionHandle ||
                    injectionHandle == g_IPv6InboundForwardInjectionHandle ||
                    injectionHandle == g_IPv4OutboundForwardInjectionHandle ||
                    injectionHandle == g_IPv6OutboundForwardInjectionHandle)
               status = FwpsInjectForwardAsync(injectionHandle,
                                               injectionContext,
                                               0,
                                               addressFamily,
                                               compartmentID,
                                               interfaceIndex,
                                               pClonedNetBufferList,
                                               CompleteFastPacketInjection,
                                               0);
            else if(injectionHandle == g_IPv4InboundTransportInjectionHandle ||
                    injectionHandle == g_IPv6InboundTransportInjectionHandle)
               status = FwpsInjectTransportReceiveAsync(injectionHandle,
                                                        injectionContext,
                                                        0,
                                                        0,
                                                        addressFamily,
                                                        compartmentID,
                                                        interfaceIndex,
                                                        subInterfaceIndex,
                                                        pClonedNetBufferList,
                                                        CompleteFastPacketInjection,
                                                        0);
            else if(injectionHandle == g_IPv4OutboundTransportInjectionHandle ||
                    injectionHandle == g_IPv6OutboundTransportInjectionHandle)
            {
               FWPS_TRANSPORT_SEND_PARAMS* pSendParams = 0;
               UINT32                      addressSize = addressFamily == AF_INET ? IPV4_ADDRESS_SIZE : IPV6_ADDRESS_SIZE;

#pragma warning(push)
#pragma warning(disable: 6014) /// pSendParams will be freed in completionFn using FastPacketInjectionCompletionDataDestroy

               HLPR_NEW(pSendParams,
                        FWPS_TRANSPORT_SEND_PARAMS,
                        WFPSAMPLER_CALLOUT_DRIVER_TAG);
               HLPR_BAIL_ON_ALLOC_FAILURE_2(pSendParams,
                                            status);

               HLPR_NEW_ARRAY(pSendParams->remoteAddress,
                              BYTE,
                              addressSize,
                              WFPSAMPLER_CALLOUT_DRIVER_TAG);
               HLPR_BAIL_ON_ALLOC_FAILURE_2(pSendParams->remoteAddress,
                                            status);

#pragma warning(pop)

               RtlCopyMemory(pSendParams->remoteAddress,
                             pRemoteAddress,
                             addressSize);

               if(FWPS_IS_METADATA_FIELD_PRESENT(pMetadata,
                                                 FWPS_METADATA_FIELD_REMOTE_SCOPE_ID))
                  pSendParams->remoteScopeId = pMetadata->remoteScopeId;

               status = FwpsInjectTransportSendAsync(injectionHandle,
                                                     injectionContext,
                                                     endpointHandle,
                                                     0,
                                                     pSendParams,
                                                     addressFamily,
                                                     compartmentID,
                                                     pClonedNetBufferList,
                                                     CompleteFastPacketInjection,
                                                     pSendParams);

               HLPR_BAIL_LABEL_2:

               if(status != STATUS_SUCCESS)
               {
                  if(pSendParams)
                     HLPR_DELETE_ARRAY(pSendParams->remoteAddress,
                                       WFPSAMPLER_CALLOUT_DRIVER_TAG);

                  HLPR_DELETE(pSendParams,
                              WFPSAMPLER_CALLOUT_DRIVER_TAG);
               }
            }

            HLPR_BAIL_LABEL:

            if(status != STATUS_SUCCESS)
            {
               if(pClonedNetBufferList)
                  FwpsFreeCloneNetBufferList(pClonedNetBufferList,
                                             0);

               DbgPrintEx(DPFLTR_IHVNETWORK_ID,
                          DPFLTR_ERROR_LEVEL,
                          " !!!! ClassifyFastPacketInjection : FwpsInjectAsync() [status: %#x]\n",
                          status);
            }
         }
      }
   }

   return;
}

#endif // (NTDDI_VERSION >= NTDDI_WIN7)
