CC=gcc
CFLAGS=-I.
DEPS = StackOfCharsModule.h 
OBJ = Parser.c StackOfCharsModule.c 

%.o: %.c $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

calculator: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
