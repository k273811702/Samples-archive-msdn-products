# Data Analysis Sample
## Requires
* Visual Studio 2010
## License
* MS-LPL
## Technologies
* Office
## Topics
* Data Analysis
* Office Automation
## IsPublished
* True
## ModifiedDate
* 2011-11-28 06:07:19
## Description

<div id="header">
<table width="100%" id="topTable">
</table>
</div>
<div id="mainSection">
<div id="mainBody">
<p><span class="style1">&#39; Copyright © Microsoft Corporation. All Rights Reserved.
</span><span class="style1">&#39; This code released under the terms of the </span>
<br>
<br>
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
<p>This sample runs in Microsoft Office Excel 2007 and higher. </p>
</td>
</tr>
</tbody>
</table>
</div>
<p>This sample demonstrates data analysis tasks executed using toolbar buttons and menus in Microsoft Office Excel 2007. The data is stored in XML files.</p>
<p>In addition, the sample is completely localizable; it demonstrates how to take advantage of System.Resources..::.ResourceManager and managed resource (RESX) files. The code was written to be globalized using culture-switching techniques that were necessary
 in earlier versions of Visual Studio Tools for Office. Those techniques are no longer necessary because of a change in how Visual Studio Tools for Office works with Excel. For more information, see Globalization and Localization of Office Solutions, Formatting
 Data in Excel with Various Regional Settings, and How to: Make String Literals Region-safe in Excel Using Reflection.
</p>
<div class="alert">
<table width="100%" cellspacing="0" cellpadding="0">
<tbody>
<tr>
<th align="left"><b>Note:</b></th>
</tr>
<tr>
<td>
<p>This sample does not run if you have an English language version of Office running on Windows with regional settings other than English (United States).</p>
</td>
</tr>
</tbody>
</table>
</div>
<p>The sample is a simple inventory management tool for a fictitious ice cream store. The workbook has systems for tracking sales, inventory in storage, and the products sold. Each of these systems stores data in XML files.</p>
<p>The store has the following constraints on inventory:</p>
<ul>
<li>
<p>Storage capacity is limited to 300 units of ice cream.</p>
</li><li>
<p>Ice cream orders are delivered once per week, in the morning.</p>
</li><li>
<p>Orders must be placed a minimum of two days before scheduled delivery date. The schedule is to place the order on Tuesday, and receive delivery on Thursday.</p>
</li><li>
<p>If additional stock is needed outside of the normal delivery schedule, there is an additional charge of 25 to have the order delivered.</p>
</li></ul>
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
<p>For information about how to install the sample project on your computer, see How to: Install and Use Sample Files Found in Help.</p>
</div>
<h3 class="procedureSubHeading">To run this sample</h3>
<div class="subSection">
<ol>
<li>
<p>Press F5.</p>
<p>The workbook opens to the Inventory worksheet, which displays a pivot table of average daily sales and average daily profits per flavor and a ListObject control that shows the previous day’s sales data. Notice that a group named
<span class="ui">Menu Commands</span> and a group named <span class="ui">Custom Toolbars</span> have been added to the
<span class="ui">Add-Ins</span> tab of the Ribbon. An <span class="ui">Orders</span> menu has been added to the
<span class="ui">Menu Commands</span> group, and two buttons that correspond to the two menu items have been added to the
<span class="ui">Custom Toolbars</span> group.</p>
</li><li>
<p>View historical sales data by selecting a different date in the Calendar control. If you select the last day of data in the data source, two additional columns (<span class="ui">Estimated Inventory</span> and
<span class="ui">Recommendation</span>) are displayed.</p>
</li><li>
<p>Click <span class="ui">Add New Date</span> to add data for a new day.</p>
<p>The ListObject control is cleared so you can enter the end-of-day inventory values for each flavor. As you enter the current inventory for each ice cream flavor, the
<span class="ui">Estimated Inventory</span> column shows expected end-of-week shortfalls or overages. The
<span class="ui">Recommendation</span> column shows whether it makes sense to create an unscheduled order. The actions pane shows a list of high inventory items and low inventory items.</p>
</li><li>
<p>Click <span class="ui">Save Data</span> to save your changes.</p>
</li><li>
<p>Click an ice cream flavor in one of the lists on the actions pane.</p>
<p>Historical sales data and a trend chart on that flavor appear in the Details worksheet.</p>
</li><li>
<p>If an unscheduled order is recommended, click <span class="ui">Create</span> to determine which flavors and how much to order.</p>
</li><li>
<p>A new worksheet named <span class="ui">Unscheduled Order_</span><span class="placeholder">&lt;Date&gt;</span> is added to the workbook. The worksheet estimates the quantity of each ice cream flavor that should be ordered to cover any shortage for the
 rest of the week.</p>
</li><li>
<p>Click <span class="ui">Create Weekly Order</span> on the <span class="ui">
Orders</span> menu to create the weekly order.</p>
<p>Sales information is read from the XML files for the previous two weeks, the average of the daily sales is calculated, and a standard deviation of the distribution is determined. An estimate of future sales is calculated based on average daily sales plus
 two standard deviations, multiplied by seven days. This gives a 95.4% probability that the amount ordered will cover the week’s expected sales.</p>
<p>A new worksheet named <span class="ui">Weekly Order_</span><span class="placeholder">&lt;Date&gt;</span> is added to the workbook.
<span class="placeholder">&lt;Date&gt;</span> is the projected order date.</p>
</li></ol>
</div>
<h1 class="heading"><span tabindex="0" style="">Demonstrates</span></h1>
<div id="demonstratesSection" class="section">
<p>The sample demonstrates the following tasks:</p>
<ul>
<li>
<p>Reading data from XML files.</p>
</li><li>
<p>Customizing menus and toolbars.</p>
</li><li>
<p>Using Excel built-in functions to analyze data.</p>
</li><li>
<p>Creating pivot tables that are linked to data in XML files.</p>
</li><li>
<p>Binding XML data to Excel list controls.</p>
</li><li>
<p>Creating charts.</p>
</li><li>
<p>Preparing user interface layout and strings for localization.</p>
</li></ul>
</div>
</div>
</div>