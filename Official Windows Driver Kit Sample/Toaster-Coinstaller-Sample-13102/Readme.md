# Toaster - Coinstaller Sample
## Requires
* Visual Studio 2012
## License
* MS-LPL
## Technologies
* WDK
* WDM
## Topics
* general
## IsPublished
* False
## ModifiedDate
* 2011-09-14 12:22:19
## Description

<h3>Toaster - Coinstaller Sample</h3>
<p>Toaster directory contains a huge collection of samples meant to demonstrate most of the fundamental aspects of Windows driver development. All the samples are built for a hypothetical computer bus, called &ldquo;Toaster Bus&rdquo;, meant for connecting
 toasters devices to PCs. Understanding the structure and working of all these various samples will provide a basic understanding of windows driver model and get you started on driver development. At a high level, these samples are meant to teach you how to
 write:</p>
<ul>
<li>Bus driver &ndash; one that controls the toaster bus and enumerates devices. </li><li>Function driver &ndash; one that talks to a toaster device connected to toaster bus.
</li><li>Filter driver &ndash; how to write class &amp; device filters that layer above and below the function driver to enhance or alter the I/O packets.
</li><li>Coinstaller &ndash; Used to customize the installation of a specific instance of a device. It can also used to configure device properties through device-manager property page.
</li><li>Classinstaller &ndash; Used to customize or provide additional properties to all the devices that plug to toaster bus.
</li><li>Device metadata &ndash; Used to display device-specific information to the user in &lsquo;Devices and Printers&rsquo; folder on Windows7 and later OSes.
</li><li>How to interact from one driver to another driver (disjoint stack) in PNP friendly way.
</li><li>How to enumerate PnP devices in usermode application, and how to interact with them in pnp friendly way.
</li><li>How to write INF files to install all the various drivers described above. </li><li>How to install custom application along with driver installation. </li></ul>
<p>&nbsp;</p>
<p>Some of the sample drivers are written using different technologies (KMDF, UMDF) and placed side-by-side to show the difference in the programming model. The table below describes what&rsquo;s contained in each of the top-level directories.</p>
<ul>
<li>KMDF--This folder contains sample drivers written using Kernel mode driver framework. Please read the toaster.htm file to learn more about the drivers under this folder.
</li><li>UMDF--This folder contains sample drivers written using User mode driver framework. There is no bus driver sample in UMDF because UMDF doesn&rsquo;t support writing bus drivers. Please read the Windows Driver Foundation book to learn the difference between
 KMDF and UMDF and how to decide which framework to use. Please read the toaster.htm file to learn more about the drivers under this folder.
</li><li>ClassInstaller--This folder contains a sample code to show how to write a class installer DLL. This DLL provides a custom icon for &ldquo;Toaster&rdquo; class and provides a customer property sheet in the device manager to change the friendly name of the
 device. This DLL is referred in the INF file used to install driver for toaster device.
</li><li>CoInstaller--This folder contains a sample code to show how to write a coinstaller DLL. This DLL shows how to create a friendly name based on the instance number of the device and also how parse custom section in the INF. This DLL is referred in the INF
 file used to install driver for toaster device. </li><li>Devicemetadatapackage--The sample files under this folder show how to create a device metadata package for Toaster devices. Device metadata contains the information that describes the device, including the following:
<ul>
<li>The vendor name. </li><li>The model name and description of the device. </li><li>One or more device categories. </li></ul>
A device metadata package consists of multiple XML documents, with each document specifying various components of the device&rsquo;s attributes. Starting with Windows&reg; 7, the Devices and Printers folder uses these XML documents to display device-specific
 information to the user. Through these XML documents, the vendor can customize how this information appears, as well as the specific information that is included.
<p>This sample has the following:</p>
<ul>
<li>The source XML metadata files and device icon file for the English and Japanese locales.
</li><li>The compiled device metadata package for both the English and Japanese locales.
</li></ul>
<p>&nbsp;</p>
For more information on compiling metadata packages, refer to the &ldquo;Building Device Metadata Packages&rdquo; section in the WDK.
<p class="proch"><strong>To install the device metadata package on Windows 7</strong></p>
<ol>
<li>Copy the device metadata package from the floppy drive or temporary file in the target system.
</li><li>If the target system is in the Japanese locale, paste it into %programdata%\microsoft\windows\devicemetadatastore\ja-jp.
</li><li>If the target system is not in the Japanese locale, paste it into %programdata%\microsoft\windows\devicemetadatastore\en-us.
</li><li>Note that this action requires administrator privilege. Elevate the privilege when you are prompted by entering the administrator&rsquo;s user name and password.
</li></ol>
After installing a toaster device, open the &ldquo;Devices and Printers&rdquo;. You will see the sample toaster icon and sample information for the toaster sample.
<p>More information on how to install device metadata packages is introduced in the device metadata package section in WDK document.</p>
</li><li>Exe--Exes under this folder are used to interact with the toaster bus driver and function driver. Since the drivers, be it written in KMDF or UMDF, are functionally equivalent and expose same interfaces, these application work with all of them.
<p>This directory contains three subdirectories notify, enum, and toast:</p>
<ul>
<li>Enum.exe is a user-mode enumerator, a simple console application. Because the toaster bus is not real, you use this application to tell the bus driver to plug in, unplug, and eject devices from the system. Type Enum.exe to see the usage.
</li><li>Toast.exe: This is a user-mode console application to control the toaster. This application enumerates toaster device open the last enumerated device and sends read request to it.
</li><li>Notify.exe: This GUI application not only combines the functionality of Enum.exe and toast.exe but also shows how to handle PnP notification in user-mode. You should install the coinstaller for the toaster device by using toastco.inf to get meaningful display
 of PnP notification. Another cool feature of this exe is that you can specify some other HW ID (Instead of the default toaster device id) and cause other drivers to be loaded as a function driver.
</li></ul>
<p>&nbsp;</p>
</li><li>ToastPkg-- Toaster Installation Package This sample describes how you can install your driver package on an end user system in a consistent, robust manner that works cooperatively with Plug and Play. This has the sources for an integrated device installation
 solution that illustrates how to provide support for the various user approaches to adding new hardware, while providing optional value-added software. Please read toastpkg.htm for more information on this sample.
</li></ul>
<p>&nbsp;</p>
<p>The Windows Developer Preview Samples Gallery contains a variety of code samples that exercise the various new programming models, platforms, features, and components available for the BUILD conference. These downloadable samples are provided as compressed
 ZIP files that contain a Visual Studio Express (BUILD release) solution (SLN) file for the sample, along with the code pages, assets, and metadata necessary to successfully compile and run the sample. For more information on the programming models, platforms,
 languages and APIs demonstrated in this sample, please refer to the guidance, tutorials, and reference provided in the Windows Developer Preview documentation available in the BUILD-specific version of the Windows Developer Center. This sample is not the final
 shipping version of the sample, and is provided &ldquo;as-is&rdquo; in order to indicate or demonstrate the early functionality of the programming models and feature APIs for a forthcoming version of Windows. Please provide feedback on this sample.</p>
<h3>Operating System Requirements</h3>
<table>
<tbody>
<tr>
<th>Client</th>
<td><dt>Windows Developer Preview </dt></td>
</tr>
<tr>
<th>Server</th>
<td><dt>Windows Server Developer Preview </dt></td>
</tr>
</tbody>
</table>
<h3>Build the Sample</h3>
<p>You can build the sample in two ways: using Visual Studio or the command line (MSBuild).</p>
<p><strong>Building a Driver Using Visual Studio</strong></p>
<p>You build a driver the same way you build any project or solution in Visual Studio. When you create a new driver project using a Windows driver template, the template defines a default (active) project configuration and a default (active) solution build
 configuration. When you create a project from existing driver sources or convert existing driver code that was built with previous versions of the WDK, the conversion process preserves the target version information (operating systems and platform).</p>
<p>The default Solution build configuration is Win8-Debug and Win32. In previous versions of the WDK, this build configuration would correspond to building a driver using the Windows 8 x86 Checked Build Environment.</p>
<p class="proch"><strong>To select a configuration and build a driver</strong></p>
<ol>
<li>Open the driver project or solution in Visual Studio. </li><li>Right-click the solution in the Solutions Explorer and select Configuration Manager.
</li><li>From the Configuration Manager, select the Active Solution Configuration (for example, Win8-Debug or Win8-Release) and the Active Solution Platform (for example, Win32) that correspond to the type of build you are interested in.
</li><li>From the Build menu, click Build Solution (Ctrl&#43;Shift&#43;B). </li></ol>
<p><strong>Building a Driver Using the Command Line (MSBuild)</strong></p>
<p>You can build a driver from the command line using the Visual Studio Command Prompt window and the Microsoft Build Engine (MSBuild.exe) Previous versions of the WDK used the Windows Build utility (Build.exe) and provided separate build environment windows
 for each of the supported build configurations. You can now use the Visual Studio Command Prompt window for all build configurations.</p>
<p class="proch"><strong>To build a driver using the Visual Studio Command Prompt window</strong></p>
<ol>
<li>Open a Visual Studio Command Prompt window. Click Start, point to All Programs, point to Microsoft Visual Studio, point to Visual Studio Tools, and then click Visual Studio Command Prompt. From this window you can use MsBuild.exe to build any Visual Studio
 project by specifying the project (.VcxProj) or solutions (.Sln) file. </li><li>Navigate to the project directory and enter the MSbuild command for your target. For example, to perform a clean build of a Visual Studio driver project called MyDriver.vcxproj, navigate to the project directory and enter the following MSBuild command:
 msbuild /t:clean /t:build .\MyDriver.vcxproj. </li></ol>
<h3>Run the Sample</h3>