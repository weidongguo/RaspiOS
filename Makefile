#
# Makefile
#

CIRCLEHOME = .

OBJS	= main.o kernel.o Thread.o HTTPClient.o CoreManager.o Keyboard.o

LIBS = $(CIRCLEHOME)/lib/usb/libusb.a \
  $(CIRCLEHOME)/lib/input/libinput.a \
  $(CIRCLEHOME)/lib/net/libnet.a \
  $(CIRCLEHOME)/lib/fs/libfs.a \
  $(CIRCLEHOME)/lib/sched/libsched.a \
  $(CIRCLEHOME)/lib/libcircle.a

all:
	cd $(CIRCLEHOME)/lib && $(MAKE)
	cd $(CIRCLEHOME)/lib/sched && $(MAKE)
	cd $(CIRCLEHOME)/lib/net && $(MAKE)
	cd $(CIRCLEHOME)/lib/input && $(MAKE)
	cd $(CIRCLEHOME)/lib/usb && $(MAKE)

	$(MAKE) $(TARGET).img 

cleanall: clean
	cd $(CIRCLEHOME)/lib && rm -f *.o *.a *.elf *.lst *.img *.cir *.map *~
	cd $(CIRCLEHOME)/lib/sched && rm -f *.o *.a *.elf *.lst *.img *.cir *.map *~
	cd $(CIRCLEHOME)/lib/net && rm -f *.o *.a *.elf *.lst *.img *.cir *.map *~
	cd $(CIRCLEHOME)/lib/input && rm -f *.o *.a *.elf *.lst *.img *.cir *.map *~
	cd $(CIRCLEHOME)/lib/usb && rm -f *.o *.a *.elf *.lst *.img *.cir *.map *~


include $(CIRCLEHOME)/Rules.mk
