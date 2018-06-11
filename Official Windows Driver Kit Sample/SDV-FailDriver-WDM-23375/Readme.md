# SDV-FailDriver-WDM
## Requires
* Visual Studio 2012
## License
* MS-LPL
## Technologies
* WDM
* Windows Driver
## Topics
* Static Driver Verifier
## IsPublished
* False
## ModifiedDate
* 2013-06-25 10:20:56
## Description

<div id="mainSection">
<p>The SDV-FailDriver-WDM sample driver contains intentional code errors that are designed to show the capabilities and features of
<a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff552808">Static Driver Verifier</a> (SDV). SDV is a static verification tool that systematically analyzes the source code of Windows kernel-mode drivers. SDV is included in the Windows Driver
 Kit (WDK) and can be run from Microsoft Visual Studio. The sample demonstrates how SDV can find errors in a WDM driver.
</p>
<p class="note"><b>Caution</b>&nbsp;&nbsp;These sample drivers contain intentional code errors that are designed to show the capabilities and features of SDV. These sample drivers are not functional and are not intended as examples for real driver development projects.
</p>
<h3>Operating system requirements</h3>
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
<h3>Build the sample</h3>
<ol>
<li>Start Visual Studio. </li><li>In the <b>File</b> menu, select <b>Open</b> and choose <b>Project/Solution...</b>.
</li><li>Navigate to the directory that contains the sample driver source code and select the solution file (SDV-FailDriver-WDM.sln).
</li><li>Select a release configuration as the Active solution configuration (<b>Build</b> &gt;
<b>Configuration Manager</b>). </li><li>Build the sample from the <b>Build</b> menu by selecting <b>Build Solution</b>. For more about building sample solutions, see
<a href="http://msdn.microsoft.com/en-us/library/windows/hardware/">Building a Driver</a> in the WDK documentation.
</li></ol>
<p>When you build the solution, it builds fail_driver1.sys. </p>
<h3>Run the sample</h3>
<ol>
<li>
<p>In the <b>Solutions Explorer </b>window, select the driver project (fail_driver1).
</p>
<p>From the <b>Driver</b> menu, click <b>Launch Static Driver Verifier…</b>. </p>
<p>This opens the Static Driver Verifier application, where you can control, configure, and schedule when Static Driver Verifier performs an analysis.</p>
</li><li>
<p>Click the <b>Rules</b> tab to select which driver DDI usage rules to verify when you start the analysis.
</p>
<p>Static Driver Verifier detects the type of driver you are analyzing (WDF, WDM, NDIS, or Storport) and selects the default set of rules for your driver type. If this is the first time you are running SDV on your driver, you should run the default rule set.
 To shorten the amount of time it takes to analyze the fail_driver1 driver sample, you can select the
<b>Custom rule selection</b>. </p>
<p>Use the default rule set, or select <b>Custom rule selection</b>, click <b>Clear All</b>, and then select the following rules for the WDM fail_driver1 sample:</p>
<ul>
<li><a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff542478">CancelSpinLock</a>
</li><li><a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff547759">IrqlIoApcLte</a>
</li><li><a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff547835">IrqlKeSetEvent</a>
</li><li><a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff548273">LowerDriverReturn</a>
</li><li><a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff551861">SpinLock (WDM)</a>
</li></ul>
<p>For information about the rules, see <a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff552840">
DDI Compliance Rules</a>. </p>
</li><li>
<p>Start the static analysis. Click the <b>Main</b> tab, and click <b>Start</b>. When you click
<b>Start</b>, a message is displayed to let you know that static analysis is scheduled and that the analysis can take a long time to run. Click
<b>OK</b> to continue. </p>
</li></ol>
<h3><a id="viewing_and_analyzing_the_results"></a><a id="VIEWING_AND_ANALYZING_THE_RESULTS"></a>View and analyze the results</h3>
<p>As the static analysis proceeds, SDV reports the status of the analysis. When the analysis is complete, SDV reports the results and statistics. If the driver fails to satisfy a DDI usage rule, the result is reported as a defect. SDV finds 5 defects in this
 sample. </p>
<p>To view specific defects in the <a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff552834">
Static Driver Verifier Report</a>, click the Defect in the <b>Results</b> pane. This opens the
<a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff544659">Trace Viewer</a>, which displays a trace of the code path to the rule violation. For more information, see
<a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff547228">Interpreting Static Driver Verifier Results</a>.</p>
</div>