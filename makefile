CFLAGS=-Wall -Wextra -std=c11 -pedantic -ggdb `pkg-config --cflags sdl2`
LIBS=`pkg-config --libs sdl2`

main: main.c
	cc main.c $(CFLAGS) -o search_destroy $(LIBS)
