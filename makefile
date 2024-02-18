
## Author	  : Ibrahim Diab   www.linkedin.com/in/ibrahim-diab1
## Description: makefile for simple program runs on arm controller.

debugDir = debug
startup  = STM32F103c8Startup
elf      = final

cc       = arm-none-eabi-gcc
cFlags   = -c -mcpu=$(mcu) -mthumb -std=gnu11 -Wall -mfloat-abi=soft -gdwarf-2
mcu      = cortex-m3
lFlags   = -T STM32F103C8.ld -nostdlib -gdwarf-2 -Wl,-Map=$(debugDir)/App.map -mfloat-abi=soft


Project : $(debugDir)/$(elf).elf 	
APP 	: $(debugDir)/main.o
MCAL 	: $(debugDir)/DIO.o $(debugDir)/RCC.o 
startup : $(debugDir)/$(startup).o

$(debugDir)/$(elf).elf :  $(debugDir)/RCC.o $(debugDir)/DIO.o   $(debugDir)/main.o $(debugDir)/$(startup).o
	mkdir -p $(debugDir)
	$(cc) $(lFlags) $^ -o $@

## Startup file for arm controller.
$(debugDir)/$(startup).o : $(startup).c 
	mkdir -p $(debugDir)
	$(cc) $(cFlags) $^ -o $@ 
	
## Application layer files. 
$(debugDir)/main.o : Src/APP/main.c
	mkdir -p $(debugDir)
	$(cc) $(cFlags) $^ -o $@
	


# MCAL Layer files.

$(debugDir)/DIO.o : Src/MCAL/DIO/DIO.c
	mkdir -p $(debugDir)
	$(cc) $(cFlags) $^ -o $@

$(debugDir)/RCC.o : Src/MCAL/RCC/RCC.c
	mkdir -p $(debugDir)
	$(cc) $(cFlags) $^ -o $@

	
clean : 
	rm -f $(debugDir)/*.o $(debugDir)/*.elf