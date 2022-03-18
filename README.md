# Description 
A Baremetal STM32 programing environment based on [***ARM GNU Embedded Tool Chain***](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads) and [***OpenOCD***](https://openocd.org/pages/getting-openocd.html). 
<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;( For school or personal projects using )

## Supported Devices
Currently tested on **STM32F1xx** series MCUs.

## Usage 

1. Setting up your **OpenOCD** `binary path` and `config files path` in ***Makefile*** and **STM32F10x_StdPeriph_Lib** `libray path`. <br>
- To generate elf file :
  - `make` <br>
- To download :
  - `make flash` <br>
- To debug :
  - `make loadserver` <br>
