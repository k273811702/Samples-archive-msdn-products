# COM Interop Part 1 Sample
## Requires
* Visual Studio 2010
## License
* MS-LPL
## Technologies
* .NET Framework
## Topics
* Interop
* COM Interop
* Language Samples
## IsPublished
* True
## ModifiedDate
* 2011-11-28 07:08:51
## Description

<h1>COM Interop Part 1 Sample</h1>
<div id="mainSection">
<div id="mainBody">
<div id="allHistory" class="saveHistory"></div>
<p></p>
<p>This sample demonstrates how a C# program can interoperate with an unmanaged COM component.</p>
<div class="alert">
<table width="100%" cellspacing="0" cellpadding="0">
<tbody>
<tr>
<th align="left">Security Note </th>
</tr>
<tr>
<td>
<p>This sample code is provided to illustrate a concept and should not be used in applications or Web sites, as it may not illustrate the safest coding practices. Microsoft assumes no liability for incidental or consequential damages should the sample code
 be used for purposes other than as intended.</p>
Note: You can't new a COM CoClass if the nopia option is turned on.
<p></p>
</td>
</tr>
</tbody>
</table>
</div>
<h1 class="heading">To build and run the COM Interop Part 1 samples within Visual Studio</h1>
<div id="procedureSection1" class="section">
<ol>
<li>
<p>In <b>Solution Explorer</b>, right-click the Interop1 project and click <b>Set as StartUp Project</b>.</p>
</li><li>
<p>In <b>Solution Explorer</b>, right-click the Interop1 project and click <b>Properties</b>.</p>
</li><li>
<p>Open the Configuration Properties folder, and click <b>Debug</b>.</p>
</li><li>
<p>In the Command-Line Arguments property, enter an AVI file such as <code>c:\winnt\clock.avi</code>.</p>
</li><li>
<p>Click <b>OK</b>.</p>
</li><li>
<p>From the <b>Debug</b> menu, click <b>Start Without Debugging</b>.</p>
</li><li>
<p>Repeat the preceding steps for Interop2.</p>
</li></ol>
</div>
<h1 class="heading">If the QuartzTypeLib.dll included with Interop1 is out of date</h1>
<div id="procedureSection2" class="section">
<ol>
<li>
<p>In <b>Solution Explorer</b>, open <b>References</b> for Interop1.</p>
</li><li>
<p>Right-click <b>QuartzTypeLib</b>, and click <b>Remove</b>.</p>
</li><li>
<p>Right-click <b>References</b>, and click <b>Add Reference</b>.</p>
</li><li>
<p>In the <b>COM</b> tab, select the component named &quot;ActiveMovie control type library.&quot;</p>
</li><li>
<p>Click <b>Select</b>, and then click <b>OK</b>.</p>
</li><li>
<p>Rebuild Interop1.</p>
<div class="alert">
<table width="100%" cellspacing="0" cellpadding="0">
<tbody>
<tr>
<th align="left">Note </th>
</tr>
<tr>
<td>
<p>Adding a reference to the component does the same thing as invoking tlbimp at the command line to create QuartzTypeLib.dll (as shown below).</p>
</td>
</tr>
</tbody>
</table>
</div>
</li><li>
<p></p>
</li></ol>
</div>
<h1 class="heading">To build and run the COM Interop Part 1 samples from the Command Line</h1>
<div id="procedureSection3" class="section">
<ol>
<li>
<p>Use the <b>Change Directory</b> command to change to the Interop1 directory.</p>
</li><li>
<p>Type the following: </p>
<div class="code"><span>
<table width="100%" cellspacing="0" cellpadding="0">
<tbody>
<tr>
<td colspan="2">
<pre>tlbimp %windir%\system32\quartz.dll /out:QuartzTypeLib.dll
csc /l:QuartzTypeLib.dll interop1.cs 
interop1 %windir%\clock.avi</pre>
</td>
</tr>
</tbody>
</table>
</span></div>
</li><li>
<p>Use the <b>Change Directory</b> command to change to the Interop2 directory.</p>
</li><li>
<p>Type the following: </p>
<div class="code"><span>
<table width="100%" cellspacing="0" cellpadding="0">
<tbody>
<tr>
<td colspan="2">
<pre>csc interop2.cs
interop2 %windir%\clock.avi</pre>
</td>
</tr>
</tbody>
</table>
</span></div>
</li></ol>
</div>
</div>
<div id="footer">
<div class="footerLine"></div>
Note: You can't new a COM CoClass if the nopia option is turned on.</div>
</div>
To make a suggestion or report a bug about Help or another feature of this product, go to the
<a href="http://go.microsoft.com/fwlink/?LinkId=9790442">feedback site</a>. 