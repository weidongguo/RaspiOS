#for Raspberry PI 2
ARMA7    = arm-eabi
ARCH_PI2 = -march=armv7-a -mfpu=vfp -mfloat-abi=hard -mtune=cortex-a7
#for Raspberry PI 3
ARMA53   = aarch64-elf
ARCH_PI3 = -march=armv8-a -mtune=cortex-a53 -mlittle-endian -mcmodel=small

RASPPI	?= 2

ifeq ($(strip $(RASPPI)),2)
ARM  ?= $(ARMA7)
ARCH ?= $(ARCH_PI2)
else ifeq ($(strip $(RASPPI)),3)
ARM  ?= $(ARMA53)
ARCH ?= $(ARCH_PI3)
endif

AS  = $(ARM)-as
AR  = $(ARM)-ar
CC  = $(ARM)-gcc
#C preprocessor
CPP = $(ARM)-cpp 
#C++ compiler
CXX = $(ARM)-g++
LD  = $(ARM)-ld

#strip Removes leading and trailing whitespace from string and replaces each internal sequence of one or more whitespace characters with a single space. 
RPVMHOME  ?= .
INCLUDE	  += -I $(RPVMHOME)/include 
OPTIMIZE  ?= -O2
DEBUG     ?= -DDEBUG -g
BAREMETAL ?= -Wall -nostdlib -nostartfiles -ffreestanding
CFLAGS	  += $(ARCH) $(INCLUDE) $(OPTIMIZE) $(DEBUG) $(BAREMETAL) -DRASPPI=$(RASPPI) 
CPPFLAGS  += $(CFLAGS) -fno-exceptions -fno-rtti -std=c++14

.PHONY: kernel7 prerequiste clean run runimg install code dockerbuildimage dockerupdateimage

kernel7 : clean prerequiste kernel7.o $(RPVMHOME)/lib/boot.o memmap
	$(ARM)-ld $@.o $(RPVMHOME)/lib/*.a $(RPVMHOME)/lib/boot.o -T memmap -o $@.elf
	$(ARM)-objdump -D $@.elf > $@.list
	$(ARM)-objcopy $@.elf -O binary $@.img

%.o: %.S
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c -o $@ $<

prerequiste:
	$(MAKE) -C lib 

run : 
	qemu-system-arm -M raspi2 -m 128M -serial stdio -kernel kernel7.elf

runimg:
	qemu-system-arm -M raspi2 -m 128M -serial stdio -bios kernel7.img

#FILES DURING PI BOOT PROCESS
bootcode.bin:
	wget -nc https://raw.githubusercontent.com/raspberrypi/firmware/master/boot/bootcode.bin
start.elf:
	wget -nc https://raw.githubusercontent.com/raspberrypi/firmware/master/boot/start.elf	 
config.txt:
	echo '' > config.txt

install : kernel7 bootcode.bin start.elf config.txt 
	echo 'unimplemented! copy files to sd card on real RP2'

code:
	docker run --rm --name arm -i -t -p 5900:5900 -v "$(shell pwd)":/work arm zsh

dockerbuildimage: ./docker/Dockerfile 
	docker build -t arm docker

dockerupdateimage: ./docker/Dockerfile
	docker commit arm
	docker attach arm

clean :
	rm -f *.o *.elf *.bin *.list *.img

cleanall: clean
	$(MAKE) -C lib clean

# AS=as 
# AR=ar 
# CC=gcc 
# CPP=cpp 
# CXX=g++ 
# LD=ld
# 
# apt-get install -y libglib2.0-dev libfdt-dev libpixman-1-dev zlib1g-dev
# git clone https://github.com/0xabu/qemu.git -b raspi
# 
# to install, just untar, and set path at the bin dir, 
# you may also need to set LD_LIBRARY_PATH at the lib dir 
# https://releases.linaro.org/components/toolchain/binaries/latest/arm-eabi/gcc-linaro-6.3.1-2017.02-x86_64_arm-eabi.tar.xz