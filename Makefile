all: main

CC = gcc
CFLAGS += -O2 -s -w -lm

SRCS = main.c

main: $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o "$@"

clean:
	rm -f main
