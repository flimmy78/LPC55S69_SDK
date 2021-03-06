Overview
========
The Secure GPIO demo application demonstrates using of secure GPIO peripheral and GPIO mask feature in
AHB secure controller. The secure GPIO is standard GPIO peripheral supporting 32 pins on port 0.
Having two GPIO peripherals allows user to configure one GPIO peripheral into secure world and another
one into normal world. Thus for all pins on port 0, user can select whether the pin is controlled
from secure or non-secure domain (using IOCON).
Since the every GPIO pin allows to read its state regardless of its configuration, the AHB secure
controller has build in feature GPIO mask for all GPIO pins. It is recommended to mask GPIO pins
for all peripherals assigned to secure domain in order to eliminate information leak from GPIO pins.
For example UART is assigned to secure world. But GPIO peripheral still allows to read state of
TxD and RxD pins. This information can be use to decode UART communication from normal world, which
can lead to unwanted information leak. 

This Secure GPIO demo uses secure GPIO to read SW1 button from secure world and standard GPIO to read
SW1 button. If SW1 button is pushed (logical zero is read) the GREEN LED is switched on in secure world
and blue led is switched on from normal world.
If SW1 button pin is masked in AHB secure controller, the state of SW1 button cannot be read in
normal world and blue LED is permanently switched on, because logical 0 is read only.
To mask/unmask SW1 button pin comment/uncomment GPIO mask feature settings in tzm_config.c file.
 

Hardware requirements
=====================
- Mini/micro USB cable
- LPCXpresso54114 board
- Personal Computer

Board settings
==============
Keep jumper J10 open for proper SW1 button operation.

Prepare the Demo
================
1.  Connect a micro USB cable between the PC host and the CMSIS DAP USB port (P6) on the board
2. Download the program to the target board.
3. Either press the reset button on your board or launch the debugger in your IDE to begin running the demo.

Running the demo
================
Green/blue LEDs are turned on, while button SW1 on your board is pressed.  
If the software is configured to mask SW1 button (see tzm_config.c file) in normal world, the blue led lit permanently. 
(The GPIO port cannot see status of SW1 button. Only the logic 0 is read, so the blue LED permanently lights.) Only the green LED is controller by SW1 button. 
If the software is configured to allow read SW1 status in normal world both green and blue LEDs are controlled by SW1 button.
The green LED is managed in secure part of the application and blue LED is managed in non-secure part of application.


TrustZone Application Development in SDK
Every TrustZone based application consists of two independent parts - secure part/project and non-secure part/project.

The secure project is stored in <application_name>\<application_name>_s directory.
The non-secure project is stored in <application_name>\<application_name>_ns directory. 

The secure projects always contains TrustZone configuration and it is executed after device RESET. The secure project usually
ends by jump to non-secure application/project.
If IDE allows the two projects in single workspace, the user can also find the project with <application_name>.
This project contains both secure and non-secure projects in one workspace (Keil MDK, IAR) and it allows to user easy transition from
one to another project.

Project Structure
The all TrustZone files related to TrustZone are located in trustzone virtual directory. The files are:

- tzm_config.c
- tzm_config.h
- veneer_table.c
- veneer_table.h

File tzm_config.c, tzm_config.h
This file is used by secure project only. It contains one function BOARD_InitTrustZone(), which configures complete TrustZone
environment. It includes SAU, MPU's, AHB secure controller and some TrustZone related registers from System Control Block.
This function is called from SystemInitHook() function, it means during system initialization.

File veneer_table.c, veneer_table.h
This file defines all secure functions (secure entry functions) exported to normal world. This file is located in secure
project only. While header file is used by both secure and non-secure projects. The secure entry functions usually contain
validation of all input parameters in order to avoid any data leak from secure world.

The files veneer_table.h and <application_name>_s_import_lib.o or <application_name>_s_CMSE_lib.o create the connection
between secure and non-secure projects. The library file is generated by linker during compilation of secure project and
it is linked to the non-secure project as any other library.

TrustZone application compilation
As first compile secure project since CMSE library is needed for compilation of non-secure project. 
After successful compilation of secure project, compile non-secure project.

TrustZone application debugging
- Download both output file into device memory
- Start execution of secure project since secure project is going to be executed after device RESET.

If IDE (Keil MDK, IAR) allows to manage download both output files as single download, the secure project
is configured to download both secure and non-secure output files so debugging can be fully managed
from secure project.

Device header file and system start up files
Both secure and non-secure project uses identical device header file. The access to secure and non-secure aliases for all peripherals
is managed using compiler macro __ARM_FEATURE_CMSE.

For secure project using <PERIPH_BASE> means access through secure alias (address bit A28=1), 
using <PERIPH_BASE>_NS means access through non-secure alias(address bit A28=0)
For non-secure project using <PERIPH_BASE> means access through non-secure alias (address bit A28=0). 
The non-secure project doesn't have access to secure memory or peripherals regions so the secure access is not defined.

Both projects have it's own start up file startup_<device_name>_s.s or startup_<device_name>_ns.s. 
However for the most of SDK examples the files are identical.

Both projects have it's own system file system_<device_name>_s.c or system_<device_name>_ns.c. 
The secure project uses standard SystemInit() function.
The SystemInit() function in non-secure project is empty for the most of SDK examples, 
and can be customized by user according to application needs.

Toolchain supported
===================
- GCC ARM Embedded 
- Keil MDK 
- IAR embedded Workbench 
- MCUXpresso

