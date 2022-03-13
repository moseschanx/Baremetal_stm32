CC = arm-none-eabi-gcc
OBJDUMP = arm-none-eabi-objdump
CCFLAGS = -march=armv7-m -mthumb -O0 -std=gnu11 

all : main.o main.s stm32f103xx_startup.o stm32f103xx_startup.s \
	main_debug stm32f103xx_debug

main.o : main.c
	$(CC) $(CCFLAGS) -c $^ -o $@ 
main.s : main.c
	$(CC) $(CCFLAGS) -S $^ -o $@ 

stm32f103xx_startup.o : stm32f103xx_startup.c
	$(CC) $(CCFLAGS) -c $^ -o $@ 
stm32f103xx_startup.s : stm32f103xx_startup.c
	$(CC) $(CCFLAGS) -S $^ -o $@ 


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
	rm -rvf *.o *.s *_debug *_disa *_bin *_layout
	



