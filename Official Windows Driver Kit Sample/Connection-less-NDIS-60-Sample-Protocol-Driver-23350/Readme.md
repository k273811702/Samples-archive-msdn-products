# Connection-less NDIS 6.0 Sample Protocol Driver
## Requires
* Visual Studio 2012
## License
* MS-LPL
## Technologies
* KMDF
* Windows Driver
## Topics
* Networking
## IsPublished
* False
## ModifiedDate
* 2013-06-25 10:18:48
## Description

<div id="mainSection">
<p>This sample demonstrates a connection-less NDIS 6.0 protocol driver. </p>
<p>The driver supports sending and receiving raw Ethernet frames using ReadFile/WriteFile calls from user-mode. As an NDIS protocol, it illustrates how to establish and tear down bindings to Ethernet adapters, i.e. those that export medium type
<i>NdisMedium802_3</i>. It shows how to set a packet filter, send and receive data, and handle plug-and-play events.</p>
<p>The sample also demonstrates how to write a Notify Object dll. The Notify Object is used for calling into the Wdf Coinstaller to install and load the framework library.</p>
<h3>Related technologies</h3>
<a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff540778">Creating Framework-based Miniport Drivers</a>
<h3>Operating system requirements</h3>
<table>
<tbody>
<tr>
<th>Client</th>
<td><dt>Windows&nbsp;Vista </dt></td>
</tr>
<tr>
<th>Server</th>
<td><dt>Windows Server&nbsp;2008 </dt></td>
</tr>
</tbody>
</table>
<h3>Build the sample</h3>
<p>For information on how to build a driver solution using Microsoft Visual Studio, see
<a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff554644">Building a Driver</a>.</p>
<p>The 60 subdirectory (src\network\ndis\ndisprot_kmdf\60) indicates that the built sample will be NDIS 6.0 compatible and will work on Windows&nbsp;Vista and later operating systems.</p>
<h3><a id="_______Installation"></a><a id="_______installation"></a><a id="_______INSTALLATION"></a>Installation</h3>
<p>Use the following steps to install the sample.</p>
<ol>
<li>When you build the sample, the build engine produces ndisprot.inf in the build target directory. Copy nprt6wdf.sys, protnotify.dll, and ndisprot.inf to a directory.
</li><li>
<p>Copy the KMDF coinstaller (wdfcoinstaller<i>MMmmm</i>.dll) to the same directory.</p>
<p class="note"><b>Note</b>&nbsp;&nbsp; </p>
<p class="note">You can obtain redistributable framework updates by downloading the
<i>wdfcoinstaller.msi</i> package from <a href="http://go.microsoft.com/fwlink/p/?LinkID=226396">
WDK 8 Redistributable Components</a>. This package performs a silent install into the directory of your Windows Driver Kit (WDK) installation. You will see no confirmation that the installation has completed. You can verify that the redistributables have been
 installed on top of the WDK by ensuring there is a redist\wdf directory under the root directory of the WDK, %ProgramFiles(x86)%\Windows Kits\8.0.</p>
<p></p>
</li><li>
<p>In Control Panel, in the <b>Network and Internet</b> group, open <b>Network Connections</b>, select an adapter, and then open
<b>Properties</b>. </p>
</li><li>
<p>Click <b>Install</b>, and then click <b>Protocol</b>.</p>
</li><li>
<p>Click <b>Add</b>, and then click <b>Have disk</b>. </p>
</li><li>
<p>Point to the location of the INF file and driver, click <b>Sample NDIS Protocol Driver</b>, and then click
<b>OK</b>. </p>
</li><li>
<p>After installing the protocol, copy the test application Uiotest.exe to a convenient location. Note that the driver service has been set to manual start in the INF file. As a result, it doesn't get loaded automatically when you install the driver.</p>
</li></ol>
<h3><a id="usage"></a><a id="USAGE"></a>Usage</h3>
<p>From an administrator command prompt, to start the driver, type <b>Net start ndisprot</b>.</p>
<p>To stop the driver, type <b>Net stop ndisprot</b>.</p>
<p>You can build Prottest.exe from source code located in the src\network\ndis\ndisprot\6x\test directory.</p>
<p>To test the NDIS 6.0 driver, run prottest. For help on usage, run <b>prottest -?</b>.</p>
<div class="code"><span>
<table>
<tbody>
<tr>
<th></th>
</tr>
<tr>
<td>
<pre>usage: PROTTEST [options] &lt;devicename&gt;
options:
 -e: Enumerate devices
 -r: Read
 -w: Write (default)
 -l &lt;length&gt;: length of each packet (default: 100)
 -n &lt;count&gt;: number of packets (defaults to infinity)
 -m &lt;MAC address&gt; (defaults to local MAC)
 -f Use a fake address to send out the packets.</pre>
</td>
</tr>
</tbody>
</table>
</span></div>
<p>Prottest exercises the IOCTLs supported by NDISPROT, and sends and/or receives data on the selected device. In order to use Prottest, the user must have administrative privilege. Users should pass down a buffer that is large enough to contain the data returned.
 If the length of the buffer passed down is smaller than the length of the received data, NDISPROT will only copy part of the data and discard the rest when the given buffer is full.</p>
<p>For an NDIS 6.0 driver, use the -e option on prottest to enumerate all devices to which NDISPROT is bound:</p>
<div class="code"><span>
<table>
<tbody>
<tr>
<th></th>
</tr>
<tr>
<td>
<pre>C:\prot&gt;prottest -e
 0. \DEVICE\{9273DA7D-5275-4B9A-AC56-68A49D121F1F}
 - Intel-Based 10/100 Ethernet Card</pre>
</td>
</tr>
</tbody>
</table>
</span></div>
<p>The following command sends and receives 2 packets on a device. Since these packets are sent to the local MAC address (default), both packets are received. The device name parameter to prottest is picked up from the output of
<b>prottest -e</b> (see above).</p>
<div class="code"><span>
<table>
<tbody>
<tr>
<th></th>
</tr>
<tr>
<td>
<pre>C:\prot&gt;prottest -n 2 \DEVICE\{9273DA7D-5275-4B9A-AC56-68A49D121F1F}
DoWriteProc: finished sending 2 packets of 100 bytes each
DoReadProc finished: read 2 packets</pre>
</td>
</tr>
</tbody>
</table>
</span></div>
<p>For security reasons, this driver does not allow packets with fake MAC addresses to be sent from user-mode applications.</p>
<p>With a checked version of ndisprot.sys, you can control the volume of debug information generated by changing the variable
<b>ndisprotDebugLevel</b>. Refer to debug.h for more information.</p>
<h3><a id="_____________File_Manifest"></a><a id="_____________file_manifest"></a><a id="_____________FILE_MANIFEST"></a>File Manifest</h3>
<p><b>Directory: 60</b> </p>
<table>
<tbody>
<tr>
<th>File</th>
<th>Description</th>
</tr>
<tr>
<td>
<p>debug.c</p>
</td>
<td>
<p>Routines to aid debugging</p>
</td>
</tr>
<tr>
<td>
<p>debug.h</p>
</td>
<td>
<p>Debug macro definitions</p>
</td>
</tr>
<tr>
<td>
<p>excallbk.c</p>
</td>
<td>
<p>Handles load order dependency between this sample and NDISWDM sample</p>
</td>
</tr>
<tr>
<td>
<p>macros.h</p>
</td>
<td>
<p>Spinlock, event, referencing macros</p>
</td>
</tr>
<tr>
<td>
<p>ndisbind.c</p>
</td>
<td>
<p>NDIS protocol entry points to handle binding/unbinding from adapters</p>
</td>
</tr>
<tr>
<td>
<p>ndisprot.h</p>
</td>
<td>
<p>Data structure definitions</p>
</td>
</tr>
<tr>
<td>
<p>precomp.h</p>
</td>
<td>
<p>Contains the precompiled headers</p>
</td>
</tr>
<tr>
<td>
<p>protuser.h</p>
</td>
<td>
<p>Has the definitions of ioctls issued by protuser.exe application used on NDIS 6.0
</p>
</td>
</tr>
<tr>
<td>
<p>nuiouser.h</p>
</td>
<td>
<p>Has the definitions of ioctls issued by nuiouser.exe application used on NDIS 5.0
</p>
</td>
</tr>
<tr>
<td>
<p>ndisprot.inf</p>
</td>
<td>
<p>INF file for installing NDISPROT</p>
</td>
</tr>
<tr>
<td>
<p>ntdisp.c</p>
</td>
<td>
<p>NT Entry points and dispatch routines for NDISPROT</p>
</td>
</tr>
<tr>
<td>
<p>recv.c</p>
</td>
<td>
<p>NDIS protocol entry points for receiving data, and IRP_MJ_READ processing</p>
</td>
</tr>
</tbody>
</table>
<p><b>Directory: NotifyOb</b> </p>
<table>
<tbody>
<tr>
<th>File</th>
<th>Description</th>
</tr>
<tr>
<td>
<p>Common.hpp</p>
</td>
<td>
<p>Header file containing the common include files for the project</p>
</td>
</tr>
<tr>
<td>
<p>dllmain.cpp</p>
</td>
<td>
<p>Handles loading/unloading of Wdf Coinstaller and the notify object dll</p>
</td>
</tr>
<tr>
<td>
<p>ProtNotify.idl</p>
</td>
<td>
<p>Defines the interfaces for the notify object dll</p>
</td>
</tr>
<tr>
<td>
<p>ProtNotify.rc</p>
</td>
<td>
<p>Resource file for the notify object dll</p>
</td>
</tr>
</tbody>
</table>
</div>
