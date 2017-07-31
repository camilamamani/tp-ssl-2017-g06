CC=gcc
CFLAGS=-I.
DEPS = StackOfDoublesModule.h scanner.h
OBJ = calculator.c scanner.c StackOfDoublesModule.c 

%.o: %.c $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

calculator: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
