RPVMHOME=..

OBJS = uart.o

all: boot.o librpvm.a

librpvm.a: $(OBJS)
	rm -f $@
	$(AR) cr $@ $(OBJS)

include ../Makefile