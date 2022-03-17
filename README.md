This is a Baremetal stm32 program framework which is based on ARM GNU Embedded Tool Chain and OpenOCD.
Currently tested on STM32F1xx series MCUs.

To use this Framework execute :
  make           # Generate target elf file and memory mapping file.
  make flash     # Flash generated target elf file into your MCU chip flash memory.
  make load      # Set up OpenOCD server for Debugging , connect via :4444 by telnet :3333 by GDB .
  
