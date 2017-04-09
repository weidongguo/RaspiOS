#for Raspberry PI 2
ARMA7  = arm-eabi
ARCH_PI2 = -march=armv7-a -mfpu=vfp -mfloat-abi=hard -mtune=cortex-a7
#for Raspberry PI 3
ARMA53 = aarch64-elf
ARCH_PI3 = -march=armv8-a -mtune=cortex-a53 -mlittle-endian -mcmodel=small

ARM  = $(ARMA7)
ARCH = $(ARCH_PI2)

AS=$(ARM)-as 
AR=$(ARM)-ar
CC=$(ARM)-gcc
CPP=$(ARM)-cpp
CXX=$(ARM)-g++
LD=$(ARM)-ld

#AOPS = --warn --fatal-warnings $(ARCH)
CFLAGS	 += $(ARCH) -Wall -O2 -nostdlib -nostartfiles -ffreestanding 
CPPFLAGS += $(CFLAGS) -fno-exceptions -fno-rtti -std=c++14

default_target: kernel7

kernel7 : clean kernel7.o boot.o memmap
	$(ARM)-ld $@.o boot.o -T memmap -o $@.elf
	$(ARM)-objdump -D $@.elf > $@.list
	$(ARM)-objcopy $@.elf -O binary $@.img

%.o: %.S
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c -o $@ $<

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