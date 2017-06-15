#
# Makefile
#

CIRCLEHOME = ../..

OBJS	= main.o kernel.o

LIBS	= $(CIRCLEHOME)/lib/libcircle.a

EXTRACLEAN = sound.h

include ../Rules.mk

kernel.o: song.h # sound.h

sound.h: sound.h.gz
	gunzip -c sound.h.gz > sound.h
