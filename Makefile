CFLAGS = -Wall -Wextra -O2
LDFLAGS = -lm

main: main.o
	cc -o main main.o $(LDFLAGS)
clean:
	rm -f main *.o *.ppm
