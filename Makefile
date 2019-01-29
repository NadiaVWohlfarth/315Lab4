CC = gcc
CFLAGS = -pedantic -Wall -Werror

all: matadd_0

matadd_0: matadd.c testmain.o
	$(CC) $(CFLAGS) -O0 -c -o matadd.o matadd.c

matadd_1: matadd.c
	$(CC) $(CFLAGS) -O1 -c -o matadd.o matadd.c

matadd_2: matadd.c
	$(CC) $(CFLAGS) -O2 -c -o matadd.o matadd.c

matadd_3: matadd.c
	$(CC) $(CFLAGS) -O3 -c -o matadd.o matadd.c

clean: 
	rm matadd.o 
