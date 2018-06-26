# HID Client Sample Driver (UMDF Version 1)
## Requires
* Visual Studio 2013
## License
* MS-LPL
## Technologies
* UMDF
* Windows Driver
## Topics
* hid
## IsPublished
* False
## ModifiedDate
* 2014-04-02 12:46:30
## Description

<div id="mainSection">
<p>The HID Client Sample driver (<i>Fx2HID.dll</i>) illustrates how to expose vendor-specific functionality on a HID collection. This sample is designed to work with the
<a href="http://www.osronline.com/hardware/OSRFX2_32.pdf">OSR USB FX2 Learning Kit
</a>board and the <a href="http://go.microsoft.com/fwlink/p/?linkid=248288">Custom driver access</a> Windows Store app.
</p>
<p>The sample driver demonstrates how to load a User-Mode Driver Framework (UMDF) version 1 driver on a vendor-specific HID collection. It exposes the custom Fx2 device interface and was written to support Windows Store style apps. It includes device metadata
 that allows it to be called from the Custom Driver Access sample. This application demonstrates how to programmatically set the 7-segment and bar-graph LEDs on the learning kit board.
</p>
<p>The HID Client Sample driver requires an additional sample driver, HID USB FX2, in order to run. The projects for both drivers are included as part of the HID Client Sample solution. Instructions for building and running both of these samples appear later
 in this file. </p>
<p><b>Theory of operation</b> </p>
<p>A HID USB device provides a HID descriptor (through an interface descriptor) that identifies the device as HID-compliant and enables the system-supplied HID minidriver (<b>hidusb.sys</b>) and the HID class driver to load, parse the HID descriptor, and enumerate
 child HID device stacks. The system provides strong support for HID devices, so you do not typically have to write a HID minidriver. However, there are cases in which you might need to write your own HID minidriver (for example, if it is difficult to make
 desired changes to HID-compliant device firmware or if you need to make a non-HID compliant device into a HID device without updating the firmware).
</p>
<p><b>Overview of the device</b> </p>
<p>The device is loosely based on the development board that is supplied with the Cypress EZ-USB FX2 Development Kit (CY3681) and contains one interface and three endpoints (Interrupt IN, Bulk Out, and Bulk IN). The firmware supports vendor commands to query
 or set the LED bar graph display and 7-segment LED display, and to query toggle switch states.</p>
<p>The interrupt endpoint sends an 8-bit value that represents the state of the switches. This value is sent on startup, resume from suspend, and whenever the switch pack setting changes. The firmware does not de-bounce the switch pack. One switch change can
 cause multiple bytes to be sent. The bits are in the reverse order of the labels on the pack (for example, bit 0x80 is labeled 1 on the pack).
</p>
<p>Bulk endpoints are configured for loopback. </p>
<p><b>Overview of the driver stack</b> </p>
<p>Kernel-Mode Driver Framework (KMDF) does not support HID minidrivers natively because the HID architecture requires that the HID class driver (<b>hidclass.sys</b>) own the driver dispatch table for HID minidrivers. This requirement conflicts with the KMDF
 requirement that it own the driver dispatch table in order to handle Plug and Play (PnP), power, and I/O requests correctly.</p>
<p>You can resolve this ownership conflict by using a driver stack that consists of a minimal WDM driver as function driver and a complete KMDF driver as lower filter driver. The function driver registers with the HID class (so
<b>hidclass.sys</b> owns its dispatch table) and forwards all of the requests to the lower filter driver. The lower filter driver (KMDF owns the dispatch table) processes all of the requests.</p>
<p>The minimal function driver code is located in the src\hid\hidusbfx2\hidkmdf directory (the driver binary is named
<b>hidkmdf.sys</b>), and the lower filter driver code is located in the src\hid\hidusbfx2\sys folder (the binary is named
<b>hidusbfx2.sys</b> ). The function driver is a minimal WDM driver and you can reuse it without any modification. Remember to rename the driver binary when you reuse it, to avoid a name conflict. You need to modify the KMDF filter driver according to your
 device's requirements.</p>
<p>The following illustration depicts the complete driver stack for these samples.</p>
<img src="111957-image.png" alt="" align="middle">
<p><b>Mapping a non-HID USB device to HID</b> </p>
<p>When the HIDclass driver queries the minidriver, the minidriver returns a hard-coded report descriptor that enables the HID class driver to create child devices as described by the report descriptor. The report descriptor has one top-level application collection:
 vendor-defined.</p>
<p>The HID class driver creates a driver stack for the top-level collection. The vendor-defined collection exposes a feature button to control the 7-segment display and bar graph display. The switch pack state is exposed as an input report. Any client application
 can open the vendor-defined collection to send feature requests and retrieve input reports.</p>
<p><b>Switch pack mapping</b> </p>
<p>The switch pack on the USB device is exposed by an input report. The HID Client Driver uses the input report to get the current state of the switches so that it can work with the Custom Device Access sample (MoFx2App).</p>
<p>To see how these can be exposed as hot keys, refer to the <i>hidusbfx2</i> sample.</p>
<p><b>Segment Display and Bar Graph</b> </p>
<p>The segment display and bar graph are mapped as HID feature controls that you can manipulate by using the
<b>HidD_SetFeature</b> function from a user-mode application. The feature controls are mapped as vendor-defined usage page 0xff00. The SEVEN_SEGMENT_REPORT_ID and BARGRAPH_REPORT_ID usages are listed in the following tables. You can also use
<b>Hidclient.exe</b>, an application that is available in the Windows Driver Kit (WDK), to manipulate the segment display and bar graph. For more information about this mapping, see the following two tables.</p>
<p><b>Segment Display Mapping</b> </p>
<table>
<tbody>
<tr>
<th>Usage ID</th>
<th>0xD7</th>
<th>0x06</th>
<th>0xB3</th>
<th>0xA7</th>
<th>0x66</th>
<th>0xE5</th>
<th>0xF4</th>
<th>0x07</th>
<th>0xF7</th>
<th>0x67</th>
</tr>
<tr>
<th>Mapping</th>
<th>Display 0</th>
<th>Display 1</th>
<th>Display 2</th>
<th>Display 3</th>
<th>Display 4</th>
<th>Display 5</th>
<th>Display 6</th>
<th>Display 7</th>
<th>Display 8</th>
<th>Display 9</th>
</tr>
</tbody>
</table>
<p><b>Bar Graph Mapping</b> </p>
<p>Note that you can OR these values to light multiple LEDs.</p>
<table>
<tbody>
<tr>
<th>Usage ID</th>
<th>0x01</th>
<th>0x02</th>
<th>0x04</th>
<th>0x08</th>
<th>0x10</th>
<th>0x20</th>
<th>0x40</th>
<th>0x80</th>
<th>0xFF</th>
<th>0x00</th>
</tr>
<tr>
<th>Mapping</th>
<th>LED 1 ON</th>
<th>LED 2ON</th>
<th>LED 3ON</th>
<th>LED 4ON</th>
<th>LED 5ON</th>
<th>LED 6ON</th>
<th>LED 7ON</th>
<th>LED 8ON</th>
<th>All LEDS ON</th>
<th>All LEDS OFF</th>
</tr>
</tbody>
</table>
<p><b>Support for selective suspend</b> </p>
<p>The HID class driver provides support for selective suspend. The minidriver participates in this feature by handling HID class IOCTLs appropriately. To enable the selective suspend feature for your device, you need to add a &quot;SelectiveSuspend&quot; = 1 value in
 the registry in the device hardware key through the INF file. For an example, see the
<b>hidusbfx2.inf</b> file.</p>
<p class="note"><b>Note</b>&nbsp;&nbsp;</p>
<p class="note">To build this sample, you can use Microsoft Visual Studio&nbsp;2013 (Express, Professional, or Ultimate) and Windows Driver Kit (WDK)&nbsp;8.1 Update. You can get Visual Studio&nbsp;2013 and WDK&nbsp;8.1 Update
<a href="http://go.microsoft.com/fwlink/p/?LInkID=239721">here</a>.</p>
<p class="note">You can also build this sample with Visual Studio&nbsp;2013 (Professional or Ultimate) and
<a href="http://go.microsoft.com/fwlink/p/?LInkID=391348">Windows Driver Kit (WDK)&nbsp;8.1</a>.</p>
<p class="note">For Windows Driver Kit (WDK)&nbsp;8 samples, download the <a href=" http://go.microsoft.com/fwlink/?LinkId=317090">
WDK&nbsp;8 samples pack</a>. The samples in the WDK&nbsp;8 samples pack will build only with Microsoft Visual Studio Professional&nbsp;2012 (Professional or Ultimate) and WDK&nbsp;8.</p>
<p></p>
<h2><a id="related_topics"></a>Related topics</h2>
<dl><dt><a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff539952">Human Input Devices Design Guide</a>
</dt><dt><a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff539956">Human Input Devices Reference</a>
</dt></dl>
<h2>Related technologies</h2>
<a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff540774">Creating Framework-based HID Minidrivers</a> ,
<a href="http://msdn.microsoft.com/en-us/library/windows/hardware/hh439579">Creating UMDF-based HID Minidrivers</a>
<h2>Operating system requirements</h2>
<table>
<tbody>
<tr>
<th>Client</th>
<td><dt>Windows&nbsp;8 </dt></td>
</tr>
<tr>
<th>Server</th>
<td><dt>Windows Server&nbsp;2012 </dt></td>
</tr>
</tbody>
</table>
<h2>Build the sample</h2>
<p>To build the sample driver:</p>
<ol>
<li>Start the Visual Studio&nbsp;2013 development environment with administrator privileges.
</li><li>Select the build configuration (for example, Wind8 Debug) and the architecture (for example, x64).
</li><li>From the File/Open/Project/Solution... menu, navigate to the VcxProj or sln file and load the project.
</li><li>Right-click the package project and choose Properties. </li><li>Choose the Driver Install option under Configuration Properties. </li><li>Choose the Deployment option and select the Enable deployment box. </li><li>Configure your remote test machine (as described in the WDK documentation). </li><li>Under Driver Installation Options (in the package Property Pages dialog), select the Custom Command Line radio button and enter &quot;pnputil -a *.inf&quot; in the corresponding text box.
</li><li>Choose the Apply button in the package Property Pages dialog. </li><li>From the <b>Build</b> menu, select <b>Build Solution</b>. </li></ol>
<p>If these steps were successful, Microsoft Visual Studio will build and deploy the sample (FX2Hid.dll) as well as hidusbfx2.sys and hidkmdf.sys to the remote test machine that you configured in step 7 (above).</p>
<h2>Run the sample</h2>
<p>To run and test the sample driver:</p>
<ol>
<li>Start the Visual Studio&nbsp;2013 development environment on your test machine. </li><li>From the File/Open/Project/Solution... menu, navigate to the VcxProj or sln file and load the HID Client Driver sample project.
</li><li>Open devicemetadatapackage\MultipleLocale\ 852E87BF-5B37-4E89-B516-3CC7C10B20ED.devicemetadata-ms using the driver metadata wizard in Visual Studio&nbsp;2013. In the finish tab of the wizard, check the box to copy to your local store.
</li><li>Build and deploy the <a href="http://go.microsoft.com/fwlink/p/?linkid=248288">
Custom driver access sample</a> - <b>MoFx2App.exe</b>. </li><li>Plug in OSR USB Fx2 device. (The <b>hidusbfx2</b> driver package loads on the OSR device node, and the
<b>Fx2Hid</b> driver loads on the HID collection.) </li></ol>
</div>
