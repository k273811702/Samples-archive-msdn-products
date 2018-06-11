# UI Manager Sample
## Requires
* Visual Studio 2010
## License
* MS-LPL
## Technologies
* Office
## Topics
* Office Ribbon
* Office Automation
## IsPublished
* True
## ModifiedDate
* 2011-11-28 06:20:03
## Description

<div id="header">
<table width="100%" id="topTable">
</table>
</div>
<div id="mainSection">
<div id="mainBody">
<p><span class="style1"></span><br>
</p>
<div class="introduction">
<div class="alert">
<table width="100%" cellspacing="0" cellpadding="0">
<tbody>
<tr>
<th align="left"><b>Note:</b></th>
</tr>
<tr>
<td>
<p>This sample runs in Microsoft Office Outlook 2007 and higher.</p>
</td>
</tr>
</tbody>
</table>
</div>
<p>This sample demonstrates how to customize the user interface (UI) of Microsoft Office Outlook 2007 by implementing extensibility interfaces in an add-in. This sample uses extensibility interfaces to create a Ribbon customization, a custom task pane, and
 a custom form region.</p>
<p>This sample also demonstrates one way to coordinate custom UI elements for a specific Inspector window. The code in this sample ensures that the Ribbon customization, custom task pane, and custom form region in an Inspector can correctly communicate with
 each other. They must communicate in a manner that is isolated from other instances of these custom UI elements that might be open in other Inspectors.</p>
<p>For example, the user might have several Inspectors open, each of which has a custom Ribbon, task pane, and form region. When the user interacts with one of these elements—for example, by clicking a button on the Ribbon—it can cause a change in another element—for
 example, hiding the task pane. The code must ensure that only the elements in the one Inspector are affected, and not other instances of these custom UI elements in other Inspectors.</p>
<p>This sample uses a set of classes that wrap Inspector and custom task pane objects to ensure that a new task pane is displayed with every task and e-mail message that the user opens. The sample also creates custom Ribbon buttons that can be used to hide
 or display the task pane in each task or e-mail message, and it displays a custom form region in each task. For more information about the structure of this sample, see Components of the UI Manager Sample.</p>
<p>For information about how to install the sample project on your computer, see How to: Install and Use Sample Files Found in Help.</p>
<div class="alert">
<table width="100%" cellspacing="0" cellpadding="0">
<tbody>
<tr>
<th align="left"><b>Note:</b></th>
</tr>
<tr>
<td>
<p>Although this sample uses extensibility interfaces to create a Ribbon customization, a custom task pane, and a form region, Visual Studio Tools for Office provides classes and designers that you can use instead. These classes and designers simplify the process
 of working with these features. For more information, see Ribbon Designer, Custom Task Panes Overview, and Creating Outlook Form Regions.</p>
</td>
</tr>
</tbody>
</table>
</div>
<div class="alert">
<table width="100%" cellspacing="0" cellpadding="0">
<tbody>
<tr>
<th align="left"><b>Security Note:</b></th>
</tr>
<tr>
<td>
<p>This sample code is intended to illustrate a concept, and it shows only the code that is relevant to that concept. It may not meet the security requirements for a specific environment, and it should not be used exactly as shown. We recommend that you add
 security and error-handling code to make your projects more secure and robust. Microsoft provides this sample code &quot;AS IS&quot; with no warranties.</p>
</td>
</tr>
</tbody>
</table>
</div>
</div>
<h3 class="procedureSubHeading">To run this sample</h3>
<div class="subSection">
<ol>
<li>
<p>Press F5.</p>
</li><li>
<p>In Outlook, create a new task.</p>
</li><li>
<p>On the Ribbon of the task, click the <span class="ui">Add-Ins</span> tab. </p>
</li><li>
<p>In the <span class="ui">UI Manager</span> group, click the <span class="ui">
TaskPane</span> button.</p>
<p>Verify that the <span class="ui">SimpleControl</span> task pane appears next to the task window.</p>
</li><li>
<p>In the <span class="ui">Show</span> group, click the <span class="ui">UIM</span> button.</p>
<p>Verify that the custom form region appears in the Reading Pane of the open task. The form region displays a list of coffee beans and a text box that contains the number of coffee orders that have been placed.</p>
</li><li>
<p>Select one or more types of coffee beans in the form region.</p>
<p>Verify that each type of coffee bean you select is added to the <span class="ui">
SimpleControl</span> task pane.</p>
</li><li>
<p>On the Ribbon, in the <span class="ui">Add-in Services</span> group, click the
<span class="ui">Send</span> button.</p>
<p>Verify that a new e-mail message is sent to the recipient <span class="input">
someone@example.com</span>, and the e-mail message contains all of the types of coffee beans that you selected in the form region.
</p>
<p>Because the e-mail message represents a coffee order, the number of placed orders on the form region is incremented.</p>
</li></ol>
</div>
<h1 class="heading"><span tabindex="0" style="">Requirements</span></h1>
<div id="requirementsTitleSection" class="section">
<p>This sample requires the following applications:</p>
<ul>
<li>
<p>Visual Studio Tools for Office.</p>
</li><li>
<p>Microsoft Office Outlook 2007.</p>
</li></ul>
</div>
<h1 class="heading"><span tabindex="0" style="">Demonstrates</span></h1>
<div id="demonstratesSection" class="section">
<p>This sample demonstrates the following concepts:</p>
<ul>
<li>
<p>Creating a Ribbon customization by implementing the <b>Microsoft.Office.Core.IRibbonExtensibility</b> interface in an add-in.</p>
</li><li>
<p>Creating a custom task pane by implementing the <b>Microsoft.Office.Core.ICustomTaskPaneConsumer</b> interface in an add-in.</p>
</li><li>
<p>Creating a custom form region by implementing the <b>Microsoft.Office.Interop.Outlook.FormRegionStartup</b> interface in an add-in.</p>
</li><li>
<p>Managing and synchronizing the Ribbon customization, custom task pane, and form region in different e-mail messages and tasks in Outlook.</p>
</li></ul>
</div>
<h1 class="heading"><span tabindex="0" style="">Components of the UI Manager Sample</span></h1>
<div id="sectionSection0" class="section">
<p>The sample solution includes two projects:</p>
<ul>
<li>
<p>Microsoft.Samples.Vsto.UiManager is an add-in project for Outlook. This project contains the implementations of the extensibility interfaces, and other classes and files that support these implementations.
</p>
</li><li>
<p>Microsoft.Samples.Vsto.AddinUtilities is a class library that includes UI management classes and interfaces that are used by the Outlook add-in project.
</p>
</li></ul>
<p>These projects provide components that implement the custom task pane, Ribbon customization, and form region, and also components that help to synchronize and manage these features.</p>
<h3 class="subHeading">UI Management Components</h3>
<div class="subsection">
<p>The following table describes the project files that provide code for the Ribbon customization.</p>
<div class="caption"></div>
<div class="tableSection">
<table width="50%" cellspacing="2" cellpadding="5" frame="lhs">
<tbody>
<tr>
<th>
<p>File</p>
</th>
<th>
<p>Description</p>
</th>
</tr>
<tr>
<td>
<p>ThisAddIn.cs/vb</p>
</td>
<td>
<p>Contains the override of the RequestService method and code that creates a new custom task pane for every Inspector window. For more information about this method, see Customizing UI Features By Using Extensibility Interfaces.</p>
</td>
</tr>
<tr>
<td>
<p>UserInterfaceContainer.cs/vb</p>
</td>
<td>
<p>Defines the <span class="code">UserInterfaceContainer</span> class. Each <span class="code">
UserInterfaceContainer</span> object manages the form region, task pane, and Ribbon customization for a single e-mail message or task.</p>
</td>
</tr>
<tr>
<td>
<p>UserInterfaceElements.cs/vb</p>
</td>
<td>
<p>Defines the <span class="code">UserInterfaceElements</span> class. This maintains the collection of
<span class="code">UserInterfaceContainter</span> objects used by the add-in. </p>
</td>
</tr>
<tr>
<td>
<p>IFormRegionControls.cs/vb</p>
<p>IRibbonConnector.cs/vb</p>
</td>
<td>
<p>Defines interfaces that several classes in the Microsoft.Samples.Vsto.UiManager and Microsoft.Samples.Vsto.AddinUtilities projects use to communicate with each other.</p>
</td>
</tr>
</tbody>
</table>
</div>
</div>
<h3 class="subHeading">Custom Task Pane Components</h3>
<div class="subsection">
<p>The following table describes the project files that provide code for the custom task pane.</p>
<div class="caption"></div>
<div class="tableSection">
<table width="50%" cellspacing="2" cellpadding="5" frame="lhs">
<tbody>
<tr>
<th>
<p>File</p>
</th>
<th>
<p>Description</p>
</th>
</tr>
<tr>
<td>
<p>TaskPaneConnector.cs/vb</p>
</td>
<td>
<p>Defines the <span class="code">TaskPaneConnector</span> class. This class implements the<b> Microsoft.Office.Core.ICustomTaskPaneConsumer</b> interface.</p>
</td>
</tr>
<tr>
<td>
<p>SimpleControl.cs/vb</p>
</td>
<td>
<p>Defines the UserControl that provides the UI of the custom task pane. This control has attributes that expose the control to COM.</p>
</td>
</tr>
</tbody>
</table>
</div>
</div>
<h3 class="subHeading">Ribbon Components</h3>
<div class="subsection">
<p>The following table describes the project files that provide code for the Ribbon customization.</p>
<div class="caption"></div>
<div class="tableSection">
<table width="50%" cellspacing="2" cellpadding="5" frame="lhs">
<tbody>
<tr>
<th>
<p>File</p>
</th>
<th>
<p>Description</p>
</th>
</tr>
<tr>
<td>
<p>RibbonConnector.cs/vb</p>
</td>
<td>
<p>Defines the <span class="code">RibbonConnector</span> class. This class implements the<b> Microsoft.Office.Core.IRibbonExtensibility</b> interface.</p>
</td>
</tr>
<tr>
<td>
<p>SimpleRibbon.xml</p>
<p>TaskRibbon.xml</p>
</td>
<td>
<p>Contains the Ribbon XML strings that are returned by the <b>GetCustomUI</b> method of the
<b>Microsoft.Office.Core.IRibbonExtensibility</b> interface implementation.</p>
</td>
</tr>
</tbody>
</table>
</div>
</div>
<h3 class="subHeading">Form Region Components</h3>
<div class="subsection">
<p>The following table describes the project files that provide code for the custom form region that is displayed in task Inspectors.</p>
<div class="caption"></div>
<div class="tableSection">
<table width="50%" cellspacing="2" cellpadding="5" frame="lhs">
<tbody>
<tr>
<th>
<p>File</p>
</th>
<th>
<p>Description</p>
</th>
</tr>
<tr>
<td>
<p>FormRegionConnector.cs/vb</p>
</td>
<td>
<p>Defines the <span class="code">FormRegionConnector</span> class. This class implements the<b> Microsoft.Office.Interop.Outlook.FormRegionStartup</b> interface.</p>
</td>
</tr>
<tr>
<td>
<p>FormRegionControls.cs/vb</p>
</td>
<td>
<p>Defines a class that manages the controls on each form region instance.</p>
</td>
</tr>
<tr>
<td>
<p>PictureConverter.cs/vb</p>
</td>
<td>
<p>Converts an Image to an <b>IPictureDisp</b> that can be used to display an icon on a form region.</p>
</td>
</tr>
<tr>
<td>
<p>SimpleFormRegion.ofs</p>
</td>
<td>
<p>Defines the UI of the form region.</p>
</td>
</tr>
<tr>
<td>
<p>SimpleFormRegion.xml</p>
</td>
<td>
<p>Contains the manifest for the form region.</p>
</td>
</tr>
<tr>
<td>
<p>SimpleFormRegion.reg</p>
</td>
<td>
<p>Creates the registry entries that are required to load the form region. </p>
</td>
</tr>
</tbody>
</table>
</div>
</div>
</div>
</div>
</div>