# WHIDBOARD
🔥😎🏴‍☠️ **WHIDBOARD: Plug it in, Set it up &amp; Get ready to Hack!** 🏴‍☠️😎🔥<br>
WHIDBOARD is the ultimate tool-suite for Hardware Hackers. It is designed to act as the perfect Swiss-Army-Knife for hacking any (I)IoT & Embedded devices.
Thanks to its core controller (a.k.a. BRUSCHETTAPRO) it can support the interaction with multiple protocols (i.e. UART, SPI, I2C, JTAG & SWD) as well as different Logic Levels (i.e. 1.8V, 2.5V, 3.3V and the VREF of the target itself). Nonetheless, it also allows the hacker to enumerate (UART, JTAG & SWD) thanks to its 24 channels' Pin Enumerator feature, as well as the ability to act as a 8 channels Logic Analyzer at 24MHz. <br>

<img src="https://github.com/whid-injector/WHIDBOARD/assets/26245612/86d801be-93d6-4ebd-83dd-67e71f1b41a6" width=40% height=40%> 


## ​🇧​​🇷​​🇺​​🇸​​🇨​​🇭​​🇪​​🇹​​🇹​​🇦​-​🇵​​🇷​​🇴 : MULTIPROTOCOL PROGRAMMER & DEBUGGER

### Logic Levels & Voltage Range
  The BRUSCHETTA-PRO (i.e. part of the WHIDBOARD), supports the interaction with multiple protocols (i.e. UART, SPI, I2C, JTAG & SWD) as well as different Logic Levels (i.e. 1.8V, 2.5V, 3.3V and the VREF of the target itself). <br>
    𝐓𝐰𝐨 𝐭𝐡𝐢𝐧𝐠𝐬 𝐚𝐫𝐞 𝐯𝐞𝐫𝐲 𝐢𝐦𝐩𝐨𝐫𝐭𝐚𝐧𝐭: <br>
      1) You have to select the right Voltage **BEFORE** turning-on the DUT (Device Under Test) and **BEFORE** plugging-in the WHIDBOARD into the PC. <br>
      2) The operational range in case you prefer to use the DUT's Voltage Reference (i.e. VREF) must remain **within the 1.7V - 3.6V range**!!! <br>
      
  <img src="https://github.com/whid-injector/WHIDBOARD/assets/26245612/92120d67-7f03-4040-8826-610156db9fd9" width=30% height=30%> 

### 🐧LINUX
#### Udev Rules Configuration
  Copy [40-persistent-ch347.rules](https://github.com/whid-injector/WHIDBOARD/blob/main/Linux/40-persistent-ch347.rules) in the directory /etc/udev/rules.d <br>
  With the command: `sudo cp 40-persistent-ch347.rules /etc/udev/rules.d/`<br>
  Restart udev service with the command: `sudo udevadm control --reload-rules`

#### UART

  In order to use the WHIDBOARD as UART Serial debugger you need to use any preferred terminal tool. It is recommended to use the classic Screen Linux utility. <br>
  Usage Example: `sudo screen /dev/ttyACM1 115200`

#### SPI & I2C

  In order to use WHIDBOARD as SPI reader/programmer be sure you have the Jumper on the CS0-Cx as in the image below. <br>
  Nearby, there is also a DIP-switch to enable/disable the WP pin.<br>
  
  <img src="https://github.com/whid-injector/WHIDBOARD/assets/26245612/84e8acf0-5d6b-4e1e-9416-65b591129294" width=30% height=30%><br>
      
  + **SNANDer**<br>
      This is a tool for the BRUSCHETTABOARD-PRO to read/write both SPI & I2C flash memories. Its usage is pretty straight forward.  To compile SNANDer on Linux:
      ```
      sudo apt install mingw-w64 gcc-mingw-w64-x86-64 libusb-1.0-0-dev
      sudo ldconfig
      git clone https://github.com/whid-injector/SNANDer
      cd SNANDer
      ./build-for-linux.sh
      ```
      Now you can try if it works and then copy snander ELF into /usr/local/bin.<br>
      Usage Examples:<br>
      ```
      snander -i
      snander -E 24c08 -r I2C_Firmware_dump.bin
      snander -r SPI_Firmware_dump.bin
     ```

  + **Flashrom**<br>
      This is yet another tool for the BRUSCHETTABOARD-PRO to read/write both SPI flash memories. Its usage is pretty straight forward.
      You can refer to the following [guide](https://www.flashrom.org/dev_guide/building_from_source.html#installing-dependencies-1) to compile Flashrom on Linux OR use the following instructions:
      ```sudo su
      apt-get install -y gcc meson ninja-build pkg-config python3-sphinx libcmocka-dev libpci-dev libusb-1.0-0-dev libftdi1-dev libjaylink-dev
      git clone https://github.com/whid-injector/flashrom-whidboard flashrom
      cd flashrom/
      meson setup builddir
      meson compile -C builddir
      meson test -C builddir
      cd builddir/
      dmesg -wr
      sudo ./flashrom -p ch347_spi  -r firmware.bin
      ```
      <img src="https://github.com/whid-injector/WHIDBOARD/assets/26245612/1b29c895-e763-483b-8b8e-74b17e8d22f3" width=50% height=50%>
      
      If everything works, then you can install system-wide:
      ```
      cd ..
      sudo meson install -C builddir
      ```

#### JTAG & SWD

### 🪟WINDOWS

#### Drivers Installation
  Before plugging the WHIDBOARD on a Windows OS do install the driver [CH341PAR.EXE](https://github.com/whid-injector/WHIDBOARD/blob/main/Windows/Drivers/CH341PAR.EXE) <br>

#### UART
  When plugging WHIDBOARD [after installing the correct drivers as recommended above... It will spawn 2 different COM ports. One it is hard-wired to the Pin Enumerator feature (i.e. JTGR) and communicates with a baudrate of 115200bps. The other COM port, will be avialable to be connected at the UART's target device through TX & RX pins on the PCB]. Any serial terminal tool for Windows can be used at this point. I personally recommend [Putty](https://www.chiark.greenend.org.uk/~sgtatham/putty/latest.html). <br>

#### SPI & I2C
  + **WHIDBOARD Windows Tool**<br>
    This is a pre-compiled (GUI-based) tool for the BRUSCHETTABOARD-PRO to read/write both SPI & I2C flash memories. Its usage is pretty straight forward.<br>
      
      <img src="https://github.com/whid-injector/WHIDBOARD/assets/26245612/7b9c49de-485b-4eb2-9e7f-51d049ad2230" width=50% height=50%>
      
  + **SNANDer**<br>
    This is yet another pre-compiled tool for the BRUSCHETTABOARD-PRO to read/write both SPI & I2C flash memories. Its usage is pretty straight forward.
  
      Usage Example:<br>
      `snander.exe -i`<br>
      `snander.exe -r SPI_Dump_SNANDer.bin`<br>
      `snander.exe -E 24c08 -r I2C_24c08_Dump_SNANDer.bin`<br>
      
      <img src="https://github.com/whid-injector/WHIDBOARD/assets/26245612/3c82fc90-8efa-4d05-baba-33de20e48cb7" width=50% height=50%>
      <img src="https://github.com/whid-injector/WHIDBOARD/assets/26245612/1fb0a2e6-f313-4410-9465-b783772eed6c" width=50% height=50%>
  
  + **Flashrom**<br>
    This is yet another pre-compiled tool for the BRUSCHETTABOARD-PRO to read/write SPI flash memories. Its usage is pretty straight forward.
  
      Usage Example:<br>
      `flashrom.exe -p ch347_spi -r firmware.bin`<br>
  
    <img src="https://github.com/whid-injector/WHIDBOARD/assets/26245612/1bcf9bb0-76b1-45b0-83b9-0a8e001f7b78" width=50% height=50%>

####  JTAG & SWD

## ​🇵​​🇮​​🇳​ ​🇪​​🇳​​🇺​​🇲​​🇪​​🇷​​🇦​​🇹​​🇴​​🇷 (A.k.a. JTGR)
  	
The Pin Enumerator feature is based on the [JTAGULATOR](https://www.blackhat.com/docs/us-14/materials/arsenal/us-14-Grand-JTAGulator-Slides.pdf) design ([That reached End-of-Life and it has been discontinued AFAIK](https://www.parallax.com/product/jtagulator/)).
This tool is extremely useful to discover on-chip debug (OCD) interfaces. On-chip debug (OCD) interfaces can provide chip-level control of a target device and are a primary vector used by engineers, researchers, and hackers to extract program code or data, modify memory contents, or affect device operation on-the-fly. Depending on the complexity of the target device, manually locating available OCD connections can be a difficult and time consuming task, sometimes requiring physical destruction or modification of the device.

  Main Features:
  
+ Detection of UART serial, JTAG and SWD protocols' pins <br>
+ Adjustable target I/O voltage for level translation: 1.4 to 3.3 V <br>
+ 24 channels with input protection circuitry (i.e. both ESD and EM Filtering) <br>
+ Smooth interaction with OpenOCD (i.e. as JTAG/SWD debugger) and Pulseview (i.e. as a 24CH basic Logic Analyzer) <br>
+ USB interface for menu-based control from host computer (Windows, macOS, Linux) <br>   
  	
To interact with the Pin Enumerator you have to plug the WHIDBOARD and connect to one of the two UART serial ports spawned. Usually in Linux is identified as /dev/ttyACM0.  <br>   
Usage example: `sudo screen /dev/ttyACM0 115200` then press any key and you will be welcomed by the JTAGULATOR menu. <br>

### Flashing The Firmware
  
To flash new version of the JTAGULATOR firmware (available here https://github.com/grandideastudio/jtagulator) is **HEAVILY RECOMMENDED** to use Linux!

```
git clone https://github.com/grandideastudio/jtagulator
wget https://github.com/parallaxinc/PropLoader/releases/download/v1.0-37/proploader-linux.zip
unzip proploader-linux.zip 
chmod +x proploader
sudo cp proploader /usr/bin
cd jtagulator
```
   
**NOW PLUG-IN WHIDBOARD AND WAIT at least 60 seconds...**
  	
TEST LOAD IN RAM ONLY:
`sudo proploader -p /dev/ttyACM0 -v JTAGulator.eeprom` <br>
[IMPORTANT]: WAIT at least 60 seconds and then check if JTGR works: `sudo screen /dev/ttyACM0 115200`
  	
FLASH EEPROM:
`sudo proploader -p /dev/ttyACM0 -v -e JTAGulator.eeprom` <br>
[IMPORTANT]: WAIT at least 60 seconds and then check if JTGR works: `sudo screen /dev/ttyACM0 115200`

<img src="https://github.com/whid-injector/WHIDBOARD/assets/26245612/91b85693-23d0-4aaa-9b52-7cc4e0f8849d" width=50% height=50%>    <br>

[OPTIONAL STEPS] IN CASE YOU WANT TO COMPILE YOUR OWN FW:
      
```
wget https://www.maccasoft.com/wp-content/downloads/openspin_1_00_81-linux-x86_64.tar.gz
tar -xzvf openspin_1_00_81-linux-x86_64.tar.gz
chmod +x openspin
sudo cp openspin /usr/bin
cd /home/whid/WHIDBOARD/JTGR/jtagulator
openspin -o JTGR.eeprom -e -v JTAGulator.spin
sudo proploader -p /dev/ttyACM0 -v -e JTGR.eeprom
```

### Use Cases

## ​🇱​​🇴​​🇬​​🇮​​🇨​ ​🇦​​🇳​​🇦​​🇱​​🇾​​🇿​​🇪​​🇷​

This feature of WHIDBOARD supports a maximum sampling rate of up to 24MHz and can analyze more than a hundred different protocols. This makes it ideal for electronic engineers debugging tasks.<br>

### Hardware Introduction

This logic analyzer design is based on the Cypress CY7C6813A controller and its own the block-diagram is represented below:
![image](https://github.com/whid-injector/WHIDBOARD/assets/26245612/39fdee0a-c93d-4e06-8b07-5695950fb687)

### Flashing the Firmware on Linux
You can find fxload and all firmwares needed, [here](https://github.com/whid-injector/WHIDBOARD/tree/main/Linux/fxload).
```
cd /home/whid/WHIDBOARD/fxload
sudo ./fxload -I fx2lafw-sigrok-fx2-8ch.ihx -D /dev/bus/usb/XXX/YYY -d 1d50:608c -c 0x1 -s Vend_Ax.hex -t fx2lp -v
```
Where XXX and YYY are taken from the "lsusb" command's output. <br>
XXX = Bus = 002 in the example below <br>
YYY = Device =  007 in the example below <br>
**Example:** <br>
```
Bus 002 Device 007: ID 04b4:8613 Cypress Semiconductor Corp. CY7C68013 EZ-USB FX2 USB 2.0 Development
```
**Example:** <br>
```
sudo ./fxload -I fx2lafw-sigrok-fx2-8ch.ihx -D /dev/bus/usb/002/007 -d 1d50:608c -c 0x1 -s Vend_Ax.hex -t fx2lp -v
```

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

  https://s.click.aliexpress.com/e/_DkWdSpp <br>
  <img src="https://github.com/whid-injector/WHIDBOARD/assets/26245612/0e76ddfe-076e-4b81-91d7-d2fe16581b4c" width=50% height=50%>    <br>

  https://s.click.aliexpress.com/e/_DdUBzir <br>
  <img src="https://github.com/whid-injector/WHIDBOARD/assets/26245612/cb7be7b9-4236-481d-adad-9647c30d9ec5" width=50% height=50%>    <br>
  
  https://s.click.aliexpress.com/e/_DEcb3Zl <br>
  <img src="https://github.com/whid-injector/BRUSCHETTA-board/assets/26245612/b90da7b9-58e0-4b17-a58b-c8d496bca79d" width=50% height=50%>    <br>
  
  https://s.click.aliexpress.com/e/_DE1eEVh <br>
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
