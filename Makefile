CC = cc
CFLAGS = -std=c99 -pedantic -Wall -Wextra

all: main

main: main.c
	${CC} ${CFLAGS} -o main main.c

clean:
	rm -f main *.o *.ppm

.PHONY: all clean
