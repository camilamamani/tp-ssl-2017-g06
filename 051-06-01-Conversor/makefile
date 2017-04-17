CC=gcc
CFLAGS=-I.
DEPS = conversor.h
OBJ = main.c conversor.c 

%.o: %.c $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

conversor: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
