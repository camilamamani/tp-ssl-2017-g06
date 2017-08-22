CC=gcc
CFLAGS=-I.
DEPS = StackOfCharsModule.h 
OBJ = parser.c StackOfCharsModule.c 

%.o: %.c $(DEPS)
	$(CC) -o $@ $< $(CFLAGS)

calculator: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
