CC = arm-none-eabi-gcc
OBJDUMP = arm-none-eabi-objdump
# -S for .s , -h for mem layout , -d for disassembly , -s for binary
CCFLAGS = -march=armv7-m -mthumb -Wall -O0 -std=gnu11 -g $(INCLUDES)
LDFLAGS = -nostdlib -T stm32f103xx.ld

OPENOCD_DEBUG_CMDS = 
OPENOCD_DEBUG_CMDS += -c "reset halt"
OPENOCD_DEBUG_CMDS += -c "flash write_image erase final.elf"
OPENOCD_DEBUG_CMDS += -c "shutdown"

# OS dependence Variables 
ifeq ($(OS),Windows_NT) 
RM = del /Q /F 

START = start ""
GDB_CMD = "C:\Program Files (x86)\GNU Arm Embedded Toolchain\10 2021.10\bin\arm-none-eabi-gdb.exe"
OPENOCD = "C:\Program Files (x86)\GNU Arm Embedded Toolchain\xpack-openocd-0.11.0-3\bin\openocd.exe"
STLINK_CFG = "C:\Program Files (x86)\GNU Arm Embedded Toolchain\xpack-openocd-0.11.0-3\scripts\interface\stlink.cfg"
CHIP_CFG = "C:\Program Files (x86)\GNU Arm Embedded Toolchain\xpack-openocd-0.11.0-3\scripts\target\stm32f1x.cfg"

STD_PERIPH_DIR = C:\Users\moses\Desktop\STM32F10x_StdPeriph_Lib_V3.6.0
else
RM = rm -rvf

MSG_SUPRESS = > ./server.log 2>&1 
GDB_CMD = arm-none-eabi-gdb-py
OPENOCD = openocd
STLINK_CFG = /usr/local/share/openocd/scripts/interface/stlink.cfg
CHIP_CFG = /usr/local/share/openocd/scripts/target/stm32f1x.cfg 

STD_PERIPH_DIR = /home/moses/code/STM32F10x_StdPeriph_Lib_V3.6.0
endif

vpath %.c $(STD_PERIPH_DIR)/Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/ : src 

INCLUDES = \
			-I$(STD_PERIPH_DIR)/Libraries/CMSIS/CM3/CoreSupport \
			-I$(STD_PERIPH_DIR)/Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x \
			-Iinc \


all : final.elf
#	main.s stm32f103xx_startup.s main_debug stm32f103xx_debug final.elf final.map

       
final.elf : main.o  stm32f103xx_startup.o system_stm32f10x.o user_stm32f10x.o
	$(CC) $(LDFLAGS) -Wl,-Map=final.map -o $@ $^


main.o : main.c
	$(CC) $(CCFLAGS) -c $^ -o $@ 
main.s : main.c
	$(CC) $(CCFLAGS) -S $^ -o $@ 

stm32f103xx_startup.o : stm32f103xx_startup.c
	$(CC) $(CCFLAGS) -c $^ -o $@ 

system_stm32f10x.o : system_stm32f10x.c  
	$(CC) $(CCFLAGS) -c $^ -o $@ 

user_stm32f10x.o : user_stm32f10x.c
	$(CC) $(CCFLAGS) -c $^ -o $@ 



clean :
	$(RM) -rvf *.o *.s *_debug *_disa *_bin *_layout *.elf *.map *.swp *.log
	

loadserver :
	$(START) $(OPENOCD) -f  $(STLINK_CFG) \
	       	-f  $(CHIP_CFG) $(MSG_SUPRESS) &

flash :
	$(OPENOCD) -f  $(STLINK_CFG) \
	       	-f  $(CHIP_CFG) \
			-c init $(OPENOCD_DEBUG_CMDS)

gdbflash : loadserver
	$(START) $(GDB_CMD) \
		-ex "target remote localhost:3333" \
		-ex "monitor reset halt" \
		-ex "monitor flash write_image erase ./final.elf" \
		-ex "detach" \
		-ex "quit"

gdbdbg : loadserver
	$(START) $(GDB_CMD) \
		-ex "file ./final.elf" \
		-ex "target remote localhost:3333" \
		-ex "monitor reset halt" \
		-ex "source ./svd_tool/gdb-svd.py" \
		-ex "svd ./svd_tool/STM32F103xx.svd" \


