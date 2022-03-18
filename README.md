# Description 
A Baremetal stm32 programing environment based on ARM GNU Embedded Tool Chain and OpenOCD. ( for School or personal Project Using )

## Supported Devices
Currently tested on STM32F1xx series MCUs.

## Usage 

1. Setting up your **OpenOCD** tools and config files int Makefile and **STM32F10x_StdPeriph_Lib** libray. <br>
- To generate elf file  : make <br>
- To download           : make flash <br>
- To debug              : make loadserver <br>
