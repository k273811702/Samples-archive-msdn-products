# Radio Switch Test Driver for OSR USB-FX2 Development Board
## Requires
* Visual Studio 2013
## License
* MS-LPL
## Technologies
* KMDF
* Windows Driver
## Topics
* Networking
## IsPublished
* True
## ModifiedDate
* 2014-04-02 12:46:33
## Description

<div id="mainSection">
<p>This sample demonstrates how to structure a HID driver for radio switches for the OSR USB-FX2 Development Board.
</p>
<p>Starting with Windows&nbsp;8.1, the hardware switch or button to control wireless transmission and the global software switch (Airplane mode switch) in the Radio Management User Interface must be synchronized. To ensure the hardware and software switches that
 control radio transmission are synchronized, the hardware switch or button must have a HID-compliant driver.</p>
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
<td><dt>Windows&nbsp;8.1 </dt></td>
</tr>
<tr>
<th>Server</th>
<td><dt>None supported </dt></td>
</tr>
</tbody>
</table>
<h2>Build the sample</h2>
<p>For information on how to build a sample driver solution using Microsoft Visual Studio, see
<a href="http://msdn.microsoft.com/en-us/library/windows/hardware/ff554644">Building a Driver</a>.</p>
<h2>Run the sample</h2>
<h2><a id="Installation"></a><a id="installation"></a><a id="INSTALLATION"></a>Installation</h2>
<p>To install the driver, you must:</p>
<ol>
<li>
<p>Build the driver using Visual Studio and copy the following installation files to a folder on your hard drive:</p>
<ul>
<li><i>RadioSwitchHidUsbFx2.inf</i> </li><li><i>RadioSwitchHidUsbFx2.sys</i> </li></ul>
</li><li>
<p>Plug in the device and do the following, depending on the operating system that you are using:
</p>
<ol>
<li>Launch <b>Device Manager</b> by executing command devmgmt.msc in a command window, or from
<b>Hardware and Sound</b> program group in <b>Control Panel</b>. </li><li>Select <b>OSR USB-FX2</b> device from <b>Other Devices</b> category and click
<b>Update Driver Software…</b> from right-click menu. </li><li>Select <b>Browse</b> my computer for software and provide the location of the driver files.
</li><li>Select <b>Install this driver software anyway</b> when the <b>Windows Security</b> dialog box appears.
</li><li>After the driver is installed, you should see the device in <b>Device Manager</b> under &quot;Human Interface Devices&quot;.
</li></ol>
</li></ol>
<h2><a id="Switch_Pack_Mapping"></a><a id="switch_pack_mapping"></a><a id="SWITCH_PACK_MAPPING"></a>Switch Pack Mapping</h2>
<h3><a id="Switch_Mapping"></a><a id="switch_mapping"></a><a id="SWITCH_MAPPING"></a>Switch Mapping</h3>
<table>
<tbody>
<tr>
<th>1</th>
<th>2</th>
<th>3</th>
<th>4</th>
<th>5</th>
<th>6</th>
<th>7</th>
<th>8</th>
</tr>
<tr>
<td>
<p>Mode</p>
<p>Select</p>
<p>Bit 3</p>
</td>
<td>
<p>Mode </p>
<p>Select</p>
<p>Bit 2</p>
</td>
<td>
<p>Mode</p>
<p>Select</p>
<p>Bit 1</p>
</td>
<td>
<p>-</p>
</td>
<td>
<p>-</p>
</td>
<td>
<p>-</p>
</td>
<td>
<p>-</p>
</td>
<td>
<p>Radio</p>
<p>Switch</p>
</td>
</tr>
</tbody>
</table>
<h2><a id="Testing"></a><a id="testing"></a><a id="TESTING"></a>Testing</h2>
<h3><a id="Testing_Modes"></a><a id="testing_modes"></a><a id="TESTING_MODES"></a>Testing Modes</h3>
<p>The driver supports five modes representing the valid combinations of HID descriptors that we have defined for the USB forum. Modes are selected using switches 1, 2, and 3 on the switch pack.</p>
<h3><a id="Switch_Mapping"></a><a id="switch_mapping"></a><a id="SWITCH_MAPPING"></a>Switch Mapping</h3>
<table>
<tbody>
<tr>
<th>1</th>
<th>2</th>
<th>3</th>
<th>Mode</th>
</tr>
<tr>
<td>0</td>
<td>0</td>
<td>0</td>
<td>Mode 1</td>
</tr>
<tr>
<td>0</td>
<td>0</td>
<td>1</td>
<td>Mode 1</td>
</tr>
<tr>
<td>0</td>
<td>1</td>
<td>0</td>
<td>Mode 2</td>
</tr>
<tr>
<td>0</td>
<td>1</td>
<td>1</td>
<td>Mode 3</td>
</tr>
<tr>
<td>1</td>
<td>0</td>
<td>0</td>
<td>Mode 4</td>
</tr>
<tr>
<td>1</td>
<td>0</td>
<td>1</td>
<td>Mode 5</td>
</tr>
<tr>
<td>1</td>
<td>1</td>
<td>0</td>
<td>Mode 1</td>
</tr>
<tr>
<td>1</td>
<td>1</td>
<td>1</td>
<td>Mode 1</td>
</tr>
</tbody>
</table>
<h3><a id="Mode_1_Radio_Push_Button"></a><a id="mode_1_radio_push_button"></a><a id="MODE_1_RADIO_PUSH_BUTTON"></a>Mode 1 Radio Push Button</h3>
<p>In this mode the radio switch (switch 8 on the switch pack) represents a momentary push button. A HID report is generated when the switch transitions to the On state (switch down).</p>
<h3><a id="Mode_2_Radio_Push_Button___LED"></a><a id="mode_2_radio_push_button___led"></a><a id="MODE_2_RADIO_PUSH_BUTTON___LED"></a>Mode 2 Radio Push Button &amp; LED</h3>
<p>In this mode the radio switch (switch 8 on the switch pack) represents a momentary push button. A HID report is generated when the switch transitions to the On state (switch down). In addition, the LED array will reflect the state of the Radio LED: either
 all on or all off (note that the top 2 LEDs never illuminate as these are not wired in).</p>
<h3><a id="Mode_3_Radio_Slider_Switch"></a><a id="mode_3_radio_slider_switch"></a><a id="MODE_3_RADIO_SLIDER_SWITCH"></a>Mode 3 Radio Slider Switch</h3>
<p>In this mode the radio switch (switch 8 on the switch pack) represents a momentary push button. A HID report is generated when the switch transitions to the On state (switch down).</p>
<h3><a id="Mode_4_Radio_Slider_Switch___LED"></a><a id="mode_4_radio_slider_switch___led"></a><a id="MODE_4_RADIO_SLIDER_SWITCH___LED"></a>Mode 4 Radio Slider Switch &amp; LED</h3>
<p>In this mode the radio switch (switch 8 on the switch pack) represents an A-B slider switch. A HID report is generated in both cases: when the switch transitions to the On state (switch down) and to the Off state (switch up). In addition the LED array will
 reflect the state of the Radio LED: either all on or all off (note that the top 2 LEDs never illuminate as these are not wired in).</p>
<h3><a id="Mode_5_LED_only"></a><a id="mode_5_led_only"></a><a id="MODE_5_LED_ONLY"></a>Mode 5 LED only</h3>
<p>In this mode the radio switch (switch 8 on the switch pack) is ignored. The LED array will reflect the state of the Radio LED: either all on or all off (note that the top 2 LEDs never illuminate as these are not wired in).</p>
</div>
