#
# Makefile
#

CIRCLEHOME = .

OBJS	= main.o kernel.o Thread.o HTTPClient.o

LIBS = $(CIRCLEHOME)/lib/usb/libusb.a \
  $(CIRCLEHOME)/lib/input/libinput.a \
  $(CIRCLEHOME)/lib/net/libnet.a \
  $(CIRCLEHOME)/lib/fs/libfs.a \
  $(CIRCLEHOME)/lib/sched/libsched.a \
  $(CIRCLEHOME)/lib/libcircle.a

all:
	cd $(CIRCLEHOME)/lib && $(MAKE)
	$(MAKE) $(TARGET).img 

cleanall: clean
	cd $(CIRCLEHOME)/lib && rm -f *.o *.a *.elf *.lst *.img *.cir *.map *~

include $(CIRCLEHOME)/Rules.mk
