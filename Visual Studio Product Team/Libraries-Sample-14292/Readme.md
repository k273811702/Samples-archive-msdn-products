# Libraries Sample
## Requires
* Visual Studio 2010
## License
* MS-LPL
## Technologies
* .NET Framework
## Topics
* Libraries
* Language Samples
## IsPublished
* True
## ModifiedDate
* 2011-11-28 07:10:44
## Description

<h1>
<h1>Libraries Sample</h1>
<div id="mainSection">
<div id="mainBody">
<div id="allHistory" class="saveHistory"></div>
<p></p>
<p>This sample shows how to create and use a DLL in C#. </p>
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
</td>
</tr>
</tbody>
</table>
</div>
<h1 class="heading">To build and run the Libraries sample within Visual Studio</h1>
<div id="procedureSection1" class="section">
<ol>
<li>
<p>In <b>Solution Explorer</b>, right-click the FunctionTest project, and click <b>
Set as StartUp Project</b>.</p>
</li><li>
<p>In <b>Solution Explorer</b>, right-click the FunctionTest project, and click <b>
Properties</b>.</p>
</li><li>
<p>Open the Configuration Properties folder and click <b>Debug</b>.</p>
</li><li>
<p>In the Command Line Arguments property, enter <code>3 5 10</code>.</p>
</li><li>
<p>Click <b>OK</b>.</p>
</li><li>
<p>From the <b>Debug</b><b></b>menu, click <b>Start Without Debugging</b>. This will automatically build the library in Functions and execute the program.</p>
</li></ol>
</div>
<h1 class="heading">To build and run the Libraries sample from the Command Line</h1>
<div id="procedureSection2" class="section">
<ol>
<li>
<p>Use the <b>Change Directory</b> command to change to the Functions directory.</p>
</li><li>
<p>Type the following: </p>
<div class="code"><span>
<table width="100%" cellspacing="0" cellpadding="0">
<tbody>
<tr>
<td colspan="2">
<pre>csc /target:library /out:Functions.dll Factorial.cs DigitCounter.cs</pre>
</td>
</tr>
</tbody>
</table>
</span></div>
</li><li>
<p>Use the <b>Change Directory</b> command to change to the FunctionTest directory.</p>
</li><li>
<p>Type the following: </p>
<div class="code"><span>
<table width="100%" cellspacing="0" cellpadding="0">
<tbody>
<tr>
<td colspan="2">
<pre>copy ..\Functions\Functions.dll .
csc /out:FunctionTest.exe /R:Functions.DLL FunctionClient.cs 
FunctionTest 3 5 10</pre>
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
To make a suggestion or report a bug about Help or another feature of this product, go to the
<a href="http://go.microsoft.com/fwlink/?LinkId=9790442">feedback site</a>. </div>
</div>
</h1>