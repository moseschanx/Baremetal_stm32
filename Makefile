CC = arm-none-eabi-gcc
OBJDUMP = arm-none-eabi-objdump
CCFLAGS = -march=armv7-m -mthumb -Wall -O0 -std=gnu11 $(INCLUDES)
LDFLAGS = -nostdlib -T stm32f103xx.ld

OPENOCD_DEBUG_CMDS = 
OPENOCD_DEBUG_CMDS += -c "reset halt"
OPENOCD_DEBUG_CMDS += -c "flash write_image erase final.elf"
OPENOCD_DEBUG_CMDS += -c "shutdown"

# OS dependence Variables 
ifeq ($(OS),Windows_NT) 
RM = del /Q /F 

OPENOCD = "C:\Program Files (x86)\GNU Arm Embedded Toolchain\xpack-openocd-0.11.0-3\bin\openocd.exe"
STLINK_CFG = "C:\Program Files (x86)\GNU Arm Embedded Toolchain\xpack-openocd-0.11.0-3\scripts\interface\stlink.cfg"
CHIP_CFG = "C:\Program Files (x86)\GNU Arm Embedded Toolchain\xpack-openocd-0.11.0-3\scripts\target\stm32f1x.cfg"

STD_PERIPH_DIR = C:\Users\moses\Desktop\STM32F10x_StdPeriph_Lib_V3.6.0
else
RM = rm -rvf

OPENOCD = openocd
STLINK_CFG = /usr/local/share/openocd/scripts/interface/stlink.cfg
CHIP_CFG = /usr/local/share/openocd/scripts/target/stm32f1x.cfg 

STD_PERIPH_DIR = /home/moses/Downloads/STM32F10x_StdPeriph_Lib_V3.6.0
endif

vpath %.c $(STD_PERIPH_DIR)/Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x/

INCLUDES = \
			-I$(STD_PERIPH_DIR)/Libraries/CMSIS/CM3/CoreSupport \
			-I$(STD_PERIPH_DIR)/Libraries/CMSIS/CM3/DeviceSupport/ST/STM32F10x \


all : final.elf
#	main.s stm32f103xx_startup.s main_debug stm32f103xx_debug final.elf final.map

       
final.elf : main.o  stm32f103xx_startup.o system_stm32f10x.o
	$(CC) $(LDFLAGS) -Wl,-Map=final.map -o $@ $^


main.o : main.c
	$(CC) $(CCFLAGS) -c $^ -o $@ 
main.s : main.c
	$(CC) $(CCFLAGS) -S $^ -o $@ 

stm32f103xx_startup.o : stm32f103xx_startup.c
	$(CC) $(CCFLAGS) -c $^ -o $@ 
stm32f103xx_startup.s : stm32f103xx_startup.c
	$(CC) $(CCFLAGS) -S $^ -o $@ 

system_stm32f10x.o : system_stm32f10x.c  
	$(CC) $(CCFLAGS) -c $^ -o $@ 

main_layout : main.o
	$(OBJDUMP) -h $^ > $@

main_disa : main.o
	$(OBJDUMP) -d $^ > $@

main_bin : main.o
	$(OBJDUMP) -s $^ > $@

main_debug : main_layout main_disa main_bin
	


stm32f103xx_layout : stm32f103xx_startup.o
	$(OBJDUMP) -h $^ > $@

stm32f103xx_disa : stm32f103xx_startup.o
	$(OBJDUMP) -d $^ > $@

stm32f103xx_bin : stm32f103xx_startup.o
	$(OBJDUMP) -s $^ > $@

stm32f103xx_debug : stm32f103xx_layout stm32f103xx_disa stm32f103xx_bin 



clean :
	$(RM) -rvf *.o *.s *_debug *_disa *_bin *_layout *.elf *.map
	

loadserver :
	$(OPENOCD) -f  $(STLINK_CFG) \
	       	-f  $(CHIP_CFG)

flash :
	$(OPENOCD) -f  $(STLINK_CFG) \
	       	-f  $(CHIP_CFG) \
			-c init $(OPENOCD_DEBUG_CMDS)


