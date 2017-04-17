#
# Makefile
#

CIRCLEHOME = .

OBJS	= main.o kernel.o

LIBS	= $(CIRCLEHOME)/lib/libcircle.a

include ./Rules.mk

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

cleanall: clean
	cd lib && rm -f *.o *.a *.elf *.lst *.img *.cir *.map *~