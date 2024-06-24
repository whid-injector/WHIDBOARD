# WHIDBOARD
🔥😎🏴‍☠️ **WHIDBOARD: Plug it in, Set it up &amp; Get ready to Hack!** 🏴‍☠️😎🔥<br>
WHIDBOARD is the ultimate tool-suite for Hardware Hackers. It is designed to act as the perfect Swiss-Army-Knife for hacking any (I)IoT & Embedded devices.
Thanks to its core controller (a.k.a. BRUSCHETTAPRO) it can support the interaction with multiple protocols (i.e. UART, SPI, I2C, JTAG & SWD) as well as different Logic Levels (i.e. 1.8V, 2.5V, 3.3V and the VREF of the target itself). Nonetheless, it also allows the hacker to enumerate (UART, JTAG & SWD) thanks to its 24 channels' Pin Enumerator feature, as well as the ability to act as a 8 channels Logic Analyzer at 24MHz.

<img src="https://github.com/whid-injector/WHIDBOARD/assets/26245612/86d801be-93d6-4ebd-83dd-67e71f1b41a6" width=50% height=50%> 


## BRUSCHETTA-PRO: MULTIPROTOCOL PROGRAMMER & DEBUGGER

### LINUX

#### UART
#### SPI
#### I2C
#### JTAG & SWD

### WINDOWS

#### Drivers Installation
Before plugging the WHIDBOARD on a Windows OS do install the driver CH341PAR.EXE <br>

#### UART
When plugging WHIDBOARD [after installing the correct drivers as recommended above... It will spawn 2 different COM ports. Once is hardwired with the Pin Enumerator feature (i.e. JTGR) with a baudrate of 115200bps. The other COM port will be avialable to be connected at the UART's target device through TX & RX pins on the PCB]. Any serial terminal too can be used. I personally recommend [Putty](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html). <br>

#### SPI
+ WHIDBOARD Windows Tool
+ SNANDer
+ Flashrom
  
#### I2C

####  JTAG & SWD

## PIN ENUMERATOR (A.k.a. JTGR)

### Flashing The Firmware

### Use Cases

## LOGIC ANALYZER

### Hardware Introduction

### Flashing the Firmware on Linux

### Flashing the Firmware on Windows

### Use Cases

## 3D Printed Case
In this repo you can find the STL CAD file to print your own case for WHIDBOARD. <br>
If you do not own a 3D printer... there are plenty of cheap services out there.  <br>
If you live in EU, I do love the guys from [Craftrum](https://www.craftrum.eu), they already printed ton of cases for me 🥇 <br>
The screws used are a 2x6mm Flat-Head Screws (e.g. https://s.click.aliexpress.com/e/_DEYh5yR) <br>
<img src="https://github.com/whid-injector/WHIDBOARD/assets/26245612/591f14fd-56c5-457f-a79b-716c6789c808" width=50% height=50%>    <br>

## Compatible SOP8 & SOP16 Adaptors
https://s.click.aliexpress.com/e/_DFY8wcn <br>
<img src="https://github.com/whid-injector/BRUSCHETTA-board/assets/26245612/21575245-8296-4e93-9a1f-955bf56e8e4e" width=50% height=50%>    <br>

https://s.click.aliexpress.com/e/_DmAewbN <br>
<img src="https://github.com/whid-injector/BRUSCHETTA-board/assets/26245612/e3e6a079-be43-4891-ba33-9f0e9faee293" width=50% height=50%>    <br>

https://s.click.aliexpress.com/e/_DEcb3Zl <br>
<img src="https://github.com/whid-injector/BRUSCHETTA-board/assets/26245612/b90da7b9-58e0-4b17-a58b-c8d496bca79d" width=50% height=50%>    <br>

https://www.aliexpress.com/item/1005005709533214.html <br>
<img src="https://github.com/whid-injector/BRUSCHETTA-board/assets/26245612/aaec8cd1-3615-4089-9931-4b4a7f478b36" width=50% height=50%>    <br>

## Tips & Tricks
In case you plan to use WHIDBOARD on a VM I do recommend to enable the USB3.1 controller. <br>
<img src="https://github.com/whid-injector/WHIDBOARD/assets/26245612/d9d47e8d-c61d-4c0e-a5e2-f8fc679b357b" width=70% height=70%> 


## How To Report Bugs
I won't spend time explaining in depth how to report issues, since I am pretty sure you have done it tons of times. 
The main idea can be summed up in the following points:
1. Expected Behavior
2. Unexpected Behavior
3. which OS you using?
4. (Windows) Did you install the drivers before connecting?
5. (Windows) Did you try all the tools? Multiprogrammer, BruschettaTool.exe and Flashrom?
6. (Windows) Is the SPI/I2C flash connected properly? Is on-PCB? Or detached from the DUT?
7. Is the target computer an Apple Product?
8. Is the target USB port an USB3.0?
9. Eventual Explanation Notes, Screenshots, Videos, etc.
