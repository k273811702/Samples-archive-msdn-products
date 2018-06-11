# Msfilter Sample Codec
## Requires
* Visual Studio 2013
## License
* MS-LPL
## Technologies
* Windows Driver
## Topics
* Audio Processing
## IsPublished
* True
## ModifiedDate
* 2014-10-01 01:36:15
## Description

<div id="mainSection">
<p>The Msfilter codec sample provides routines for volume and echo effects that you can apply to any audio content.
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
<td><dt>Windows&nbsp;7 </dt></td>
</tr>
<tr>
<th>Server</th>
<td><dt>Windows Server&nbsp;2008&nbsp;R2 </dt></td>
</tr>
</tbody>
</table>
<h2>Build the sample</h2>
<p>Starting in the WDK, you can build the sample in two ways: using the Visual Studio Integrated Development Environment (IDE) or from the command line using the Visual Studio Command Prompt window and the Microsoft Build Engine (MSBuild.exe).</p>
<h3><a id="Building_the_sample_using_Visual_Studio"></a><a id="building_the_sample_using_visual_studio"></a><a id="BUILDING_THE_SAMPLE_USING_VISUAL_STUDIO"></a>Building the sample using Visual Studio</h3>
<ol>
<li>Open Visual Studio. From the <b>File</b> menu, select <b>Open Project/Solution</b>. Within your WDK installation, navigate to src\mmedia\msfilter and open the
<i>msfilter.sln</i> project file. </li><li>Right-click the solution in the <b>Solution Explorer</b> and select <b>Configuration Manager</b>.
</li><li>From the <b>Configuration Manager</b>, select the <b>Active Solution Configuration</b> (for example, Windows&nbsp;8.1 Debug or Windows&nbsp;8.1 Release) and the
<b>Active Solution Platform</b> (for example, Win32) that correspond to the type of build you are interested in.
</li><li>From the <b>Build</b> menu, click <b>Build Solution</b> (Ctrl&#43;Shift&#43;B). </li></ol>
<p>Previous versions of the WDK used the Windows Build utility (Build.exe) and provided separate build environment windows for each of the supported build configurations. Starting in the WDK, you can use the Visual Studio Command Prompt window for all build
 configurations.</p>
<h3><a id="Building_the_sample_using_the_command_line__MSBuild_"></a><a id="building_the_sample_using_the_command_line__msbuild_"></a><a id="BUILDING_THE_SAMPLE_USING_THE_COMMAND_LINE__MSBUILD_"></a>Building the sample using the command line (MSBuild)</h3>
<ol>
<li>Open a Visual Studio Command Prompt window. Click <b>Start</b> and search for
<b>Developer Command Prompt</b>. If your project is under %PROGRAMFILES%, you need to open the command prompt window using elevated permissions (<b>Run as administrator</b>). From this window you can use MsBuild.exe to build any Visual Studio project by specifying
 the project (.VcxProj) or solutions (.Sln) file. </li><li>Navigate to the project directory and enter the <b>MSbuild</b> command for your target. For example, to perform a clean build of a Visual Studio driver project called msfltr32.vcxproj, navigate to the project directory and enter the following MSBuild command:
<b>msbuild /t:clean /t:build .\msfltr32.vcxproj</b>. </li><li>If the build succeeds, you will find the driver (msfltr32.acm) in the binary output directory corresponding to the target platform, for example src\mmedia\msfilter\Windows&nbsp;8.1 Debug.
</li></ol>
<h2>Run the sample</h2>
<h2><a id="Operation"></a><a id="operation"></a><a id="OPERATION"></a>Operation</h2>
<p>This sample, like the Msgsm610 sample, illustrates how to implement an Audio Compression Manager (ACM) software codec.</p>
<p>The sample does not support Plug and Play (PnP), power management, or OnNow. These features are not applicable to ACM software codecs.</p>
</div>