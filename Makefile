CC = gcc
CFLAGS = -O0

CC2 = arm-linux-gnueabihf-gcc
CFLAGS2 = -O0 -mcpu=cortex-a15

default: all

all:
	$(CC) $(CFLAGS) -o gcdv1 gcdv1.c
	$(CC) $(CFLAGS) -o gcdv2 gcdv2.c
	$(CC) $(CFLAGS) -o gcdv3 gcdv3.c
	$(CC2) $(CFLAGS2) -S gcdv1.c
	$(CC2) $(CFLAGS2) -S gcdv2.c
	$(CC2) $(CFLAGS2) -S gcdv3.c

clean:
	rm gcdv1 gcdv1.s
	rm gcdv2 gcdv2.s
	rm gcdv3 gcdv3.s
