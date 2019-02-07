CC = gcc
CFLAGS = -pedantic -Wall -Werror

all: matadd_0

matadd_0: matadd.c 
	$(CC) $(CFLAGS) -O0 -o matadd matadd.c

matadd_1: matadd.c
	$(CC) $(CFLAGS) -O1 -o matadd matadd.c

matadd_2: matadd.c
	$(CC) $(CFLAGS) -O2 -o matadd matadd.c

matadd_3: matadd.c
	$(CC) $(CFLAGS) -O3 -o matadd matadd.c

clean: 
	rm matadd 
