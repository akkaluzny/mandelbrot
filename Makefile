CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -g

mandel: main.o mandel.o
	$(CC) $(LDFLAGS) main.o mandel.o -o mandel -lncurses

main.o: main.c mandel.h
	$(CC) $(CFLAGS) -c main.c

mandel.o: mandel.c mandel.h
	$(CC) $(CFLAGS) -c mandel.c

.PHONY: clean
clean:
	rm -f *.o mandel
