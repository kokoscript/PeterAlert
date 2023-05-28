LIBMENUET := ../../menuet32-plus/libmenuet

all: PETER

PETER: PeterAlert.c peter.h
	smlrcc -I $(LIBMENUET)/include -Wall -flat32 -origin 0 -o $@ $(LIBMENUET)/libmenuet.a $<
