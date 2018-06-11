# SpbTestTool
## Requires
* Visual Studio 2013
## License
* MS-LPL
## Technologies
* KMDF
* Windows Driver
## Topics
* SPB
## IsPublished
* True
## ModifiedDate
* 2014-04-02 12:50:40
## Description

<div id="mainSection">
<p>The SpbTestTool sample serves two purposes. First, it demonstrates how to open a handle to the
<a href="http://msdn.microsoft.com/en-us/library/windows/hardware/hh698220">SPB controller</a>, use the SPB interface from a KMDF driver, and employ GPIO
<a href="http://msdn.microsoft.com/en-us/library/windows/hardware/hh451035">passive-level interrupts</a>. Second, it implements a set of commands for communicating with a peripheral device to aid in debugging.
</p>
<p>This sample is incomplete as a driver and merely demonstrates use of the <a href="http://msdn.microsoft.com/en-us/library/windows/hardware/hh698224">
SPB I/O request interface</a> and <a href="http://msdn.microsoft.com/en-us/library/windows/hardware/hh406467">
GPIO interrupts</a>. It is not intended for use in a production environment.</p>
<p class="note"><b>Note</b>&nbsp;&nbsp;</p>
<p class="note">To build this sample, you can use Microsoft Visual Studio&nbsp;2013 (Express, Professional, or Ultimate) and Windows Driver Kit (WDK)&nbsp;8.1 Update. You can get Visual Studio&nbsp;2013 and WDK&nbsp;8.1 Update
<a href="http://go.microsoft.com/fwlink/p/?LInkID=239721">here</a>.</p>
<p class="note">You can also build this sample with Visual Studio&nbsp;2013 (Professional or Ultimate) and
<a href="http://go.microsoft.com/fwlink/p/?LInkID=391348">Windows Driver Kit (WDK)&nbsp;8.1</a>.</p>
<p class="note">For Windows Driver Kit (WDK)&nbsp;8 samples, download the <a href=" http://go.microsoft.com/fwlink/?LinkId=317090">
WDK&nbsp;8 samples pack</a>. The samples in the WDK&nbsp;8 samples pack will build only with Microsoft Visual Studio Professional&nbsp;2012 (Professional or Ultimate) and WDK&nbsp;8.</p>
<p></p>
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
<p>To build the SpbTestTool peripheral driver, follow these instructions:</p>
<ol>
<li>
<p>Navigate to src\SPB\SpbTestTool\sys and launch the Vcxproj file.</p>
</li><li>
<p>Modify SpbTestTool.inx as follows:</p>
<ul>
<li>Replace ACPI\SpbTestTool with appropriate peripheral HWID. </li><li>Set the &quot;ConnectInterrupt registry&quot; setting to 1 to connect the first interrupt resource found. Otherwise, leave at this setting at 0 to leave disconnected. See the SpbTestTool_AddReg section in SpbTestTool.inx.
</li></ul>
</li><li>
<p>Build the project in Visual Studio.</p>
<ul>
<li>Produces SpbTestTool.inf and SpbTestTool.sys. </li></ul>
</li></ol>
<p>To build the SpbTestTool application, follow these instructions:</p>
<ol>
<li>
<p>Navigate to src\SPB\SpbTestTool\exe and launch the Vcxproj file.</p>
</li><li>
<p>Build the project in Visual Studio.</p>
<ul>
<li>Produces SpbTestTool.exe. </li></ul>
</li></ol>
<h2>Run the sample</h2>
<p>To install the SpbTestTool peripheral driver, follow these steps:</p>
<ol>
<li>
<p>Ensure that the driver builds without errors.</p>
</li><li>
<p>Copy the SYS and INF files to a separate folder.</p>
</li><li>
<p>Run Devcon.exe. You can find this program in the tools\devcon folder where you installed the WDK. Type the following command in the command window:</p>
<dl><dd><code>devcon.exe update SpbTestTool.inf ACPI\&lt;hwid&gt;</code> </dd></dl>
<p></p>
</li></ol>
<p>To launch the SpbTestTool application, follow these steps:</p>
<ol>
<li>
<p>Navigate to the directory that contains SpbTestTool.exe.</p>
</li><li>
<p>Type the following command in the command window:</p>
<dl><dd><code>SpbTestTool.exe</code> </dd></dl>
</li><li>
<p>By default, the SpbTestTool application uses the SpbTestTool sample driver. However, an alternate peripheral driver can be used instead. To specify an alternate driver, use the following format for the command line:</p>
<dl><dd><code>SpbTestTool.exe /p \\.\&lt;alternate_path&gt;</code> </dd></dl>
<p>The <code>alternate_path</code> parameter in this command is the path name of the alternate driver.</p>
<p class="note"><b>Note</b>&nbsp;&nbsp;The alternate driver must implement the private SpbTestTool interface.</p>
</li><li>
<p>An input script can used instead of an interactive prompt. The script format requires one command per line. To run the script, use the following format for the command line in the command window:</p>
<dl><dd><code>SpbTestTool.exe /i &lt;script.txt&gt;</code> </dd></dl>
<p>The <code>script.txt</code> parameter in this command is the name of the file that contains the input script. For the list of available commands, see
<a href="#executing_commands">Executing commands</a>.</p>
</li></ol>
<h2><a id="executing_commands"></a><a id="EXECUTING_COMMANDS"></a>Executing commands</h2>
<p>The SpbTestTool application loops indefinitely waiting for one of the following commands. The commands are translated to the appropriate SPB I/O request without any state tracking in the driver. Transfer status, buffer contents, and error codes are returned
 as necessary. Type <code>help</code> at any time to display this command list. Press Ctrl-C at any time to cancel the current command and exit the application.</p>
<table>
<tbody>
<tr>
<th>Command</th>
<th>Description</th>
</tr>
<tr>
<td>
<p><i>open</i> </p>
</td>
<td>
<p>Open handle to SPB controller.</p>
</td>
</tr>
<tr>
<td>
<p><i>close</i> </p>
</td>
<td>
<p>Close handle to SPB controller.</p>
</td>
</tr>
<tr>
<td>
<p><i>lock</i> </p>
</td>
<td>
<p>Lock the bus for exclusive access.</p>
</td>
</tr>
<tr>
<td>
<p><i>unlock</i> </p>
</td>
<td>
<p>Unlock the bus.</p>
</td>
</tr>
<tr>
<td>
<p><i>lockconn</i> </p>
</td>
<td>
<p>Lock the shared connection for exclusive access. This command is used to synchronize bus transfers by the sample driver with op-region accesses by the ACPI firmware.</p>
</td>
</tr>
<tr>
<td>
<p><i>unlockconn</i> </p>
</td>
<td>
<p>Unlock the shared connection.</p>
</td>
</tr>
<tr>
<td>
<p><i>write {}</i> </p>
</td>
<td>
<p>Write a byte array to the peripheral device.</p>
<p>Example: <code>&gt; write {01, 02, 03}</code></p>
</td>
</tr>
<tr>
<td>
<p><i>read &lt;numBytes&gt;</i> </p>
</td>
<td>
<p>Read &lt;numBytes&gt; from the peripheral device.</p>
<p>Example: <code>&gt; read 5</code></p>
</td>
</tr>
<tr>
<td>
<p><i>writeread {} &lt;numBytes&gt;</i> </p>
</td>
<td>
<p>Atomically write a byte array to the peripheral device and read &lt;numBytes&gt; back.</p>
<p>Example: <code>&gt; writeread {01, 02, 03} 5</code></p>
</td>
</tr>
<tr>
<td>
<p><i>signal</i> </p>
</td>
<td>
<p>Inform the SpbTestTool driver that the interrupt has been handled.</p>
</td>
</tr>
<tr>
<td>
<p><i>help</i> </p>
</td>
<td>
<p>Display the list of supported commands.</p>
</td>
</tr>
<tr>
<td>
<p><i>Ctrl-C</i> </p>
</td>
<td>
<p>Press Ctrl-C at any time to cancel the outstanding command and exit the application.</p>
</td>
</tr>
</tbody>
</table>
<h2><a id="Code_tour"></a><a id="code_tour"></a><a id="CODE_TOUR"></a>Code tour</h2>
<p>The following are the relevant functions in the SpbTestTool peripheral driver for using the SPB interface from a KMDF driver.</p>
<table>
<tbody>
<tr>
<th>Function</th>
<th>Description</th>
</tr>
<tr>
<td>
<p><code>OnPrepareHardware</code> </p>
</td>
<td>
<p>Traverses the driver’s start resources and caches the connection ID of the I2C or SPI resource. This ID will be used to open the SPB controller later on.</p>
</td>
</tr>
<tr>
<td>
<p><code>SpbPeripheralOpen</code> </p>
</td>
<td>
<p>Opens a handle to the underlying SPB controller via the resource hub. This allows the peripheral driver to be developed without any underlying knowledge of the platform or hardware connections. Instead, the dependency between controller and peripheral is
 described in ACPI.</p>
</td>
</tr>
<tr>
<td>
<p><code>SpbPeripheralClose</code> </p>
</td>
<td>
<p>Sends IOCTL_SPB_LOCK_CONTROLLER to the SPB controller to lock the bus for exclusive access by this peripheral.</p>
</td>
</tr>
<tr>
<td>
<p><code>SpbPeripheralLock</code> </p>
</td>
<td>
<p>Sends IOCTL_SPB_LOCK_CONTROLLER to the SPB controller to lock the bus for exclusive access by this peripheral.</p>
</td>
</tr>
<tr>
<td>
<p><code>SpbPeripheralUnlock</code> </p>
</td>
<td>
<p>Sends IOCTL_SPB_UNLOCK_CONTROLLER to the SPB controller to unlock the bus from exclusive access by this peripheral.</p>
</td>
</tr>
<tr>
<td>
<p><code>SpbPeripheralLockConnection</code> </p>
</td>
<td>
<p>Sends IOCTL_SPB_LOCK_CONNECTION to the SPB controller to lock the shared connection for exclusive access by this target (file handle).</p>
</td>
</tr>
<tr>
<td>
<p><code>SpbPeripheralUnlockConnection</code> </p>
</td>
<td>
<p>Sends IOCTL_SPB_UNLOCK_CONNECTION to the SPB controller to unlock the shared connection from exclusive access by this target (file handle).</p>
</td>
</tr>
<tr>
<td>
<p><code>SpbPeripheralRead</code> </p>
</td>
<td>
<p>Sends a read request to the SPB controller.</p>
</td>
</tr>
<tr>
<td>
<p><code>SpbPeripheralWrite</code> </p>
</td>
<td>
<p>Sends a write request to the SPB controller.</p>
</td>
</tr>
<tr>
<td>
<p><code>SpbPeripheralWriteRead</code> </p>
</td>
<td>
<p>Builds a write-read sequence and sends IOCTL_SPB_EXECUTE_SEQUENCE to the SPB controller.</p>
</td>
</tr>
<tr>
<td>
<p><code>SpbPeripheralOnComplete</code> </p>
</td>
<td>
<p>Completion callback for all I/O requests.</p>
</td>
</tr>
</tbody>
</table>
<p>The following are the relevant functions in the SpbTestTool peripheral driver for managing GPIO passive-level interrupts from a KMDF driver.</p>
<table>
<tbody>
<tr>
<th>Function</th>
<th>Description</th>
</tr>
<tr>
<td>
<p><code>OnPrepareHardware</code> </p>
</td>
<td>
<p>Traverses the driver’s start resources. If &quot;ConnectInterrupt&quot; is set to 1 in the registry, the driver connects the first interrupt resource found and registers an interrupt service routine.</p>
</td>
</tr>
<tr>
<td>
<p><code>OnInterruptIsr</code> </p>
</td>
<td>
<p>The interrupt service routine, which has been configured to run at passive-level. Doing so enables the driver to acknowledge or quiesce the interrupt using the SPB interface, which cannot be called at DIRQL.</p>
<p>Typically a driver will clear the hardware interrupt and save any volatile information in its ISR, and then it will queue a workitem to continue processing. Our sample driver instead notifies the SpbTestTool app that an interrupt has occurred and calls KeWaitForSingleObject
 to wait until the interrupt is handled before returning. A &quot;real&quot; driver should never stall in the ISR like this.</p>
</td>
</tr>
<tr>
<td>
<p><code>SpbPeripheralWaitOnInterrupt</code> </p>
</td>
<td>
<p>Called to pend a WaitOnInterrupt request in the driver, which will be completed when the next interrupt occurs.</p>
</td>
</tr>
<tr>
<td>
<p><code>SpbPeripheralInterruptNotify</code> </p>
</td>
<td>
<p>Completes an outstanding WaitOnInterrupt request to inform the SpbTestTool app that an interrupt has occurred.</p>
</td>
</tr>
<tr>
<td>
<p><code>SpbPeripheralSignalInterrupt</code> </p>
</td>
<td>
<p>Notifies the interrupt service routine that the interrupt has been handled and the ISR should return.</p>
</td>
</tr>
</tbody>
</table>
<h2><a id="File_manifest"></a><a id="file_manifest"></a><a id="FILE_MANIFEST"></a>File manifest</h2>
<p>The following source files are in the src\SPB\SpbTestTool\sys folder and are used to build the SpbTestTool.sys and SpbTestTool.inf files.</p>
<table>
<tbody>
<tr>
<th>File</th>
<th>Description</th>
</tr>
<tr>
<td>
<p>driver.h, driver.cpp</p>
</td>
<td>
<p>Events on the Device Object, and read, write, and IOCTLs from the SpbTestTool application. Implements the driver’s interrupt service routine.</p>
</td>
</tr>
<tr>
<td>
<p>internal.h</p>
</td>
<td>
<p>Common includes and typedefs</p>
</td>
</tr>
<tr>
<td>
<p>makefile</p>
</td>
<td>
<p>Redirects to the real makefile that is shared by all components of the WDK.</p>
</td>
</tr>
<tr>
<td>
<p>peripheral.h, peripheral.cpp</p>
</td>
<td>
<p>Reflection of the SpbTestTool IOCTLs to the SPB API, including opening the controller via the resource hub and using lock, unlock, read, write, and sequence.</p>
</td>
</tr>
<tr>
<td>
<p>resource.rc</p>
</td>
<td>
<p>Resource descriptor file used for versioning</p>
</td>
</tr>
<tr>
<td>
<p>sources</p>
</td>
<td>
<p>Lists source files and build options.</p>
</td>
</tr>
<tr>
<td>
<p>sources.dep</p>
</td>
<td>
<p>Defines build dependencies.</p>
</td>
</tr>
<tr>
<td>
<p>spbtesttool.asl</p>
</td>
<td>
<p>Sample ASL file for a peripheral device node. It declares I2C and GPIO interrupt resources. Note each macro specifies an ACPI path to describe direct dependencies.</p>
</td>
</tr>
<tr>
<td>
<p>spbtesttool.h</p>
</td>
<td>
<p>Private SpbTestTool IOCTLs for use between the application and peripheral driver, and driver path names.</p>
</td>
</tr>
<tr>
<td>
<p>spbtesttool.inx</p>
</td>
<td>
<p>Describes the installation of the driver. The build process converts this into an INF.</p>
</td>
</tr>
<tr>
<td>
<p>trace.h</p>
</td>
<td>
<p>Sets up WPP tracing.</p>
</td>
</tr>
</tbody>
</table>
<p>The following source files are in the src\SPB\SpbTestTool\exe folder and are used to build the SpbTestTool.exe file.</p>
<table>
<tbody>
<tr>
<th>File</th>
<th>Description</th>
</tr>
<tr>
<td>
<p>command.h, command.cpp</p>
</td>
<td>
<p>Classes respresenting each of the SpbTestTool commands. For the list of commands, see
<a href="#executing_commands">Executing commands</a>.</p>
</td>
</tr>
<tr>
<td>
<p>internal.h</p>
</td>
<td>
<p>Common includes and function definitions</p>
</td>
</tr>
<tr>
<td>
<p>main.cpp</p>
</td>
<td>
<p>Application entry point, input parsing, and main execution loop. Also contains the interrupt notification thread.</p>
</td>
</tr>
<tr>
<td>
<p>makefile</p>
</td>
<td>
<p>Redirects to the real makefile that is shared by all components of the WDK.</p>
</td>
</tr>
<tr>
<td>
<p>sources</p>
</td>
<td>
<p>Lists source files and build options.</p>
</td>
</tr>
<tr>
<td>
<p>util.cpp</p>
</td>
<td>
<p>Helper functions</p>
</td>
</tr>
</tbody>
</table>
</div>