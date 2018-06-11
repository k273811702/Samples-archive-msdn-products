# OEM Printer Customization Plug-in Samples
## Requires
* Visual Studio 2013
## License
* MS-LPL
## Technologies
* printer
* Windows Driver
## Topics
* Printing
## IsPublished
* True
## ModifiedDate
* 2014-04-02 12:48:08
## Description

<div id="mainSection">
<p>The OEMDLL samples are an illustration of OEM customization plug-ins. The BITMAP, OEMPS, OEMUI, OEMUNI, OEMPREAN, CUSTHLP, SyncSet, ThemeUI, PSUIRep, and Watermark samples do not affect the printer output. They are only examples of how to build OEM Customization
 DLLs of various types. </p>
<p>The following samples are included as part of this sample set:</p>
<table>
<tbody>
<tr>
<th>Sample</th>
<th>Description</th>
</tr>
<tr>
<td>
<p>BITMAP</p>
</td>
<td>
<p>a Unidrv-based bitmap rendering plug-in. This sample demonstrates how to write a Unidrv-based rendering plug-in that functions as a bitmap driver. The sample is based on the redesigned version of the OEMUNI sample.
</p>
</td>
</tr>
<tr>
<td>
<p>CUSTHLP</p>
</td>
<td>
<p>An OEM help-customization plug-in. This sample demonstrates adding OEM help to your customization plug-in and how to replace standard Microsoft supplied help with customized help.
</p>
</td>
</tr>
<tr>
<td>
<p>OEMPREAN</p>
</td>
<td>
<p>illustrates how you can leverage the pre-analysis feature in Unidrv. This sample is built on the redesigned version of the OEMUNI sample.
</p>
</td>
</tr>
<tr>
<td>
<p>OEMPS</p>
</td>
<td>
<p>A PostScript rendering plug-in. This sample demonstrates how to write a PostScript-based rendering plug-in.</p>
</td>
</tr>
<tr>
<td>
<p>OEMUI</p>
</td>
<td>
<p>A user interface plug-in (both PostScript and Unidrv flavors are available). The OEMUI sample demonstrates common UI tasks such as adding additional elements to the UI (that is, items and pages).
</p>
</td>
</tr>
<tr>
<td>
<p>OEMUNI</p>
</td>
<td>
<p>A user interface plug-in (both PostScript and Unidrv flavors are available). The OEMUI sample demonstrates common UI tasks such as adding additional elements to the UI (that is, items and pages).
</p>
</td>
</tr>
<tr>
<td>
<p>PSUIREP</p>
</td>
<td>
<p>A PostScript UI replacement sample. This sample demonstrates how to completely replace the standard printer driver UI for PostScript driver plug-ins.
</p>
</td>
</tr>
<tr>
<td>
<p>PTPCPIPR</p>
</td>
<td>
<p>The Unidrv Plug-in for Print Ticket Provider Interface sample contains a functional Unidrv configuration plug-in that implements the IPrintOemPrintTicketProvider interface. You can use this code as a starting point for developing new driver plug-ins that
 support PrintTicket functionality. </p>
</td>
</tr>
<tr>
<td>
<p>SYNCSET</p>
</td>
<td>
<p>A synchronization plug-in. This sample demonstrates how to synchronize driver settings between the OEM customization page and the standard device settings page.
</p>
</td>
</tr>
<tr>
<td>
<p>THEMEUI</p>
</td>
<td>
<p>A theming plug-in. This sample demonstrates how to use theming (that is, comctl v6) for printer driver UI.</p>
</td>
</tr>
<tr>
<td>
<p>UNIUIREP</p>
</td>
<td>
<p>This Universal Printer Driver (Unidrv) UI plugin sample shows how to fully replace Unidrv's standard UI and how to use the new IPrintCoreHelper interface to enumerate GDP features/options, enumerate constraints, get/set Unidrv settings, and create a GDL
 snapshot.</p>
</td>
</tr>
<tr>
<td>
<p>WATERMARK</p>
</td>
<td>
<p>Demonstrates how to produce customizable watermark page simulation by controlling PostScript injected in the printing stream. The components of the sample include a PostScript-based rendering module in conjunction with a UI module. The rendering module is
 responsible for the injection of the modified PostScript into the printing stream. This sample demonstrates the required COM interfaces, required functions with sample code and how to use the OEM's private DEVMODE section to communicate between the UI and
 rendering modules. </p>
</td>
</tr>
<tr>
<td>
<p>WATERMARKUNI</p>
</td>
<td>
<p>Demonstrates how to produce customizable watermark page simulation by controlling PCL data injected in the printing stream. The components of the sample include a UNIDRV-based rendering module in conjunction with a UI module. The rendering module is responsible
 for the injection of the PCL data into the printing stream. This sample demonstrates the required COM interfaces, required functions with sample code and how to use the OEM's private DEVMODE section to communicate between the UI and rendering modules. This
 sample works only if you have a page printer that has its own fonts. It doesn't download any fonts nor convert fonts to bitmap.
</p>
</td>
</tr>
</tbody>
</table>
<p>For information about how to develop a plug-in for customizing the print driver UI, see
<a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff546237(v=vs.85).aspx">
COM Interfaces for UI Plug-Ins</a>.</p>
<p class="note"><b>Note</b>&nbsp;&nbsp;The OEMDLL samples are for the v3 print driver model only.</p>
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
<p>To build a driver solution using Windows&nbsp;8.1 driver kit (Windows Driver Kit (WDK)) and Visual Studio&nbsp;2013, perform the following steps.</p>
<dl><dd>
<p>1. Open the solution file in Visual Studio&nbsp;2013</p>
</dd><dd>
<p>2. Add all non-binary files (usually located in the \install directory of the sample) to the Package project</p>
<dl><dd>
<p>a. In the <b>Solution Explorer</b>, right click <b>Driver Files</b></p>
</dd><dd>
<p>b. Select <b>Add</b>, then click <b>Existing Item</b></p>
</dd><dd>
<p>c. Navigate to the location to which you downloaded the sample, and select all the files in the install directory, or the equivalent set of non-binary files such as INFs, INIs, GPD, PPD files, etc.</p>
</dd><dd>
<p>d. Click <b>Add</b></p>
</dd></dl>
</dd><dd>
<p>3. Configure these files to be added into the driver package</p>
<dl><dd>
<p>a. In the <b>Solution Explorer</b>, right click the Package project and select
<b>Properties</b></p>
</dd><dd>
<p>b. In the left pane, click <b>Configuration Properties</b> &gt; <b>Driver Install</b> &gt;
<b>Package Files</b>.</p>
</dd><dd>
<p>c. In the right pane, use the ellipsis button (...) to browse to the set of files that needs to be added to the driver package. All the data files that you added in
<b>Step 2-c</b>, except the INF file, should be added.</p>
<p class="note"><b>Note</b>&nbsp;&nbsp;This configuration is per-architecture, so this configuration must be repeated for each architecture that will be built.</p>
</dd><dd>d. Click <b>OK</b> </dd></dl>
</dd><dd>
<p>4. Open the INF file and edit it to match the built output</p>
<dl><dd>
<p>a. Open the INF file</p>
</dd><dd>
<p>b. In the Version section, add a reference to a catalog file like this: CatalogFile=XpsDrvSmpl.cat
</p>
</dd><dd>
<p>c. In the SourceDisksFiles section, change the location of the DLL files you are building, to =1. This indicates that there is no architecture specific directory in this driver. If you ship multiple architectures simultaneously, you will need to collate
 the driver INF manually. </p>
</dd></dl>
</dd></dl>
<p></p>
<p>At this point, Visual Studio&nbsp;2013 will be able to build a driver package and output the files to disk. In order to configure driver signing and deployment, see
<a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff554651(v=vs.85).aspx">
Developing, Testing, and Deploying Drivers</a>.</p>
<p>For more information about how to build a driver solution using Microsoft Visual Studio, see
<a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff554644">Building a Driver</a>.</p>
<h2>Run the sample</h2>
<h2><a id="Installation"></a><a id="installation"></a><a id="INSTALLATION"></a>Installation</h2>
<p>After building the samples, you can install them by using the <b>Add Printer Wizard</b>. Select the local printer, click
<b>Have Disk</b>, and point to the directory that contains the relevant INF (oemdll.inf, bitmap.inf, oemprean.inf, and so on) file.
</p>
<h2><a id="Design_and_Operation"></a><a id="design_and_operation"></a><a id="DESIGN_AND_OPERATION"></a>Design and Operation</h2>
<h3><a id="BITMAP"></a><a id="bitmap"></a>BITMAP</h3>
<p></p>
<p>This sample includes the following features:</p>
<ul>
<li>The supported ColorMode options in the bitmap driver's GPD are monochrome, 4bpp, 8bpp, and 24bpp.
</li><li>The bitmap driver implements the IPrintOemUni::ImageProcessing callback to access bitmap data one band at a time. The driver's implementation of ImageProcessing buffers the band data every time it is called. The function is also responsible for filling
 the BITMAPINFOHEADER and COLORTABLE structures that are necessary for dumping the data out to a bitmap file.
</li><li>The bitmap driver implements the OEMEndDoc DDI hook to dump the buffered bitmap data to the spooler at the end of the print job. The driver's implementation of OEMEndDoc dumps the headers first and then the buffered data.
</li><li>The GrowBuffer helper function is called every time the buffer needs to be enlarged to hold the bitmap data.
</li><li>The bitmap driver renders multi-page documents into a single large output bitmap file.
</li></ul>
<p>This sample has the following limitations:</p>
<ul>
<li>The plug-in does not support landscape orientation although the option exists in the GPD.
</li><li>In 24bpp mode, documents larger than three pages will produce an extremely large bitmap (.bmp) file. Although the output is correct, you might not be able to view it because of memory limitations in the bitmap viewer.
</li></ul>
<p></p>
<h3><a id="OEMPREAN"></a><a id="oemprean"></a>OEMPREAN</h3>
<p>When preanalysis is enabled in the GPD (for more details about preanalysis, see the WDK documentation), Unidrv defines the surface as a banding surface but causes the first playback (that is, the first band) to be of the entire page. Unidrv performs this
 definition by setting the GDI clip window to the entire page. Unidrv enables all drawing commands to be hooked but returns before any drawing can be done. On the subsequent passes, Unidrv resets the clip window back to the original band size and bands normally.</p>
<p>In order for plugins to also take part in preanalysis, they can enable OEM preanalysis by specifying the &quot;*PreAnalysisOptions: 8&quot; parameter in the GPD. The OEM rendering plug-in must hook both DrvStartBanding and DrvNextBand when this mode is enabled in
 the GPD. The OEM rendering plug-in must test the pptl parameter of the OEMStartBanding call to determine whether preanalysis has been enabled on this page. If the pptl parameter is NULL, preanalysis has been enabled, and the OEM rendering plug-in should consider
 all drawing calls up to the first call to OEMNextBand to be part of preanalysis.
</p>
<p>During these preanalysis phase drawing calls, the plug-in should not draw on the surface. The plug-in should also not call back into unidrv. You should use this phase only for analysis of the objects on the page. For example, certain printers need to handle
 black objects that intersect with color objects differently from black objects that appear by themselves. Other printers might need to halftone StretchBlt objects differently from BitBlt objects.
</p>
<p>You should be aware that after preanalysis, you might get more calls than you saw in the normal rendering, because primitives that cross band boundaries yield two or more DDI calls after the preanalysis pass.
</p>
<p>The sample uses the bPreAnalysis flag in the OEMPDEV structure to denote whether a particular pass is the preanalysis pass or the actual rendering pass. If the bPreAnalysis flag is set, it indicates that the current pass is the preanalysis pass. The sample
 implements all of the drawing function hooks in Ddihook.cpp. The sample uses the OEMStartBanding and OEMNextBand functions to respectively set and reset the bPreAnalysis flag. The sample also uses the DBG_CLIPOBJ debug macro function to dump the bounds of
 the clipping rectangle available for preanalysis in each of the drawing functions during the preanalysis pass. To view all of the debug output in the debugger, you must set the debug level to VERBOSE. The rest of the sample is identical to the Oemuni sample
 that illustrates a basic OEM rendering plug-in.</p>
<p>Note that the surface used during preanalysis might differ from the surface passed in during the rendering pass.
</p>
<h3><a id="PTPCPIPR"></a><a id="ptpcpipr"></a>PTPCPIPR</h3>
<p>This sample is an educational example that illustrates the basic functionality that a Unidrv plug-in for the IPrintOemPrintTicketProvider interface should implement.
</p>
<p>The primary functionality of the plug-in is to support the PhotoPrintingIntent PrintSchema keyword. The PhotoPrintingIntent keyword is designed to provide a mechanism for photo printers to support enhancements that are specific to photo printing. An application
 or the user (through the print UI) can then specify whether a particular print job is a photo-printing job, in which case the device can apply appropriate enhancements.
</p>
<p>The intent setting is communicated to the device driver in a PrintTicket. The actual enhancements made are device-specific, and as such, the driver has to map the high-level intent setting into specific output settings, like resolution or bpp. This plug-in
 sample demonstrates the conversion. </p>
<p>The plug-in implements the ExpandIntentOptions method of the IPrintOemPrintTicketProvider interface. This method is called with an input print-ticket. The plug-in checks if the print-ticket contains a photo-printing intent setting, and if so, removes the
 setting, while instead adding to the print-ticket output settings as mentioned above. The code sample uses MSXML6 for all PrintTicket XML handling.</p>
<h3><a id="UINUIREP"></a><a id="uinuirep"></a>UINUIREP</h3>
<p>This sample shows how a plug-in for a Unidrv-based driver can replace the default UI. It provides new property sheets for the printer property and printing preferences pages.</p>
<p>Use this sample as an example of implementing full UI replacement in a Unidrv-based plugin. It also demonstrates the use of the new IPrintCoreHelper interface.
</p>
<p>This sample is only provided for educational purposes and should not be used in a production environment.
</p>
</div>