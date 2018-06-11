# SDV-FailDriver-KMDF
## Requires
* Visual Studio 2013
## License
* MS-LPL
## Technologies
* KMDF
* Windows Driver
## Topics
* Static Driver Verifier
## IsPublished
* True
## ModifiedDate
* 2014-04-02 12:49:57
## Description

<div id="mainSection">
<p>The SDV-FailDriver-KMDF sample driver contains intentional code errors that are designed to show the capabilities and features of
<a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff552808">Static Driver Verifier</a> (SDV). SDV is a static verification tool that systematically analyzes the source code of Windows kernel-mode drivers. SDV is included in the Windows Driver
 Kit (WDK) and can be run from Microsoft Visual Studio. The sample demonstrates how SDV can find errors in a KMDF driver.
</p>
<p class="note"><b>Caution</b>&nbsp;&nbsp;These sample drivers contain intentional code errors that are designed to show the capabilities and features of SDV. These sample drivers are not functional and are not intended as examples for real driver development projects.
</p>
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
<ol>
<li>Start Visual Studio. </li><li>In the <b>File</b> menu, select <b>Open</b> and choose <b>Project/Solution...</b>.
</li><li>Navigate to the directory that contains the sample driver source code and select the solution file (SDV-FailDriver-KMDF.sln).
</li><li>Select a release configuration as the Active solution configuration (<b>Build</b> &gt;
<b>Configuration Manager</b>). </li><li>Build the sample from the <b>Build</b> menu by selecting <b>Build Solution</b>. For more information about building sample solutions, see
<a href="http://msdn.microsoft.com/en-us/library/windows/hardware/">Building a Driver</a> in the WDK documentation.
</li></ol>
<p>When you build the solution, it builds two projects: fail_driver1.sys and a support library, fail_library1.lib.
</p>
<h2>Run the sample</h2>
<ol>
<li>
<p>In the <b>Solutions Explorer </b>window, select the driver project (fail_driver1).
</p>
<p>From the <b>Driver</b> menu, click <b>Launch Static Driver Verifier…</b>. </p>
<p>This opens the Static Driver Verifier application, where you can control, configure, and schedule when Static Driver Verifier performs an analysis.</p>
</li><li>
<p>The fail_driver1 sample driver includes a library. To add the library, click the
<b>Libraries</b> tab and click <b>Add Library</b>.</p>
<p>Browse to the sample library directory and select the library project file (fail_library1.vcxProj). The library must be added before SDV analyzes the driver. For more information, see
<a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff548182">Library Processing in Static Driver Verifier</a>.</p>
</li><li>
<p>Click the <b>Rules</b> tab to select which driver DDI usage rules to verify when you start the analysis.</p>
<p>Static Driver Verifier detects the type of driver you are analyzing (WDF, WDM, NDIS, or Storport) and selects the default set of rules for your driver type. If this is the first time you are running SDV on your driver, you should run the default rule set.
 To shorten the amount of time it takes to analyze the fail_driver1 driver sample, you can select the
<b>Custom rule selection</b>. </p>
<p>Use the default rule set, or select <b>Custom rule selection</b>, click <b>Clear All</b>, and then select the following rules for the KMDF fail_driver1 sample:</p>
<ul>
<li><a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff544957">DriverCreate</a>
</li><li><a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff544843">DeviceInitAPI</a>
</li><li><a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff543607">CtlDeviceFinishInitDeviceAdd</a>
</li><li><a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff549047">MdlAfterReqCompletedIoctl</a>
</li><li><a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff549090">MemAfterReqCompletedIntIoctlA</a>
</li><li><a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff549042">MdlAfterReqCompletedIntIoctlA</a>
</li><li><a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff549011">MarkCancOnCancReqLocal</a>
</li><li><a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff552846">StopAckWithinEvtIoStop</a>
</li></ul>
<p>For information about the rules, see <a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff552840">
DDI Compliance Rules</a>. </p>
</li><li>
<p>Start the static analysis. Click the <b>Main</b> tab, and then click <b>Start</b>. When you click
<b>Start</b>, a message is displayed to let you know that static analysis is scheduled and that the analysis can take a long time to run. Click
<b>OK</b> to continue.</p>
</li></ol>
<h2><a id="viewing_and_analyzing_the_results"></a><a id="VIEWING_AND_ANALYZING_THE_RESULTS"></a>View and analyze the results</h2>
<p>As the static analysis proceeds, SDV reports the status of the analysis. When the analysis is complete, SDV reports the results and statistics. If the driver fails to satisfy a DDI usage rule, the result is reported as a defect. SDV finds 8 defects in this
 sample. </p>
<p>On the <b>Main</b> tab, under <b>Results</b>, click the <b>Rules</b> tab. This tab displays the name of each rule that was verified in the last run and the results of the analysis. To view the reported defects, click the
<b>Defect</b> link in the <b>Results</b> column. This opens the <a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff552834">
Static Driver Verifier Report Page</a> and the <a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff544659">
Trace Viewer</a>, which displays a trace of the code path to the rule violation. For more information, see
<a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff547228">Interpreting Static Driver Verifier Results</a>.</p>
</div>