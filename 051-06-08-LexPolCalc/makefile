CC = gcc
CFLAGS = -std=c11 -Wall -pedantic-errors 
BIN = calculator.exe
OBJ = StackOfDoublesModule.o scanner.o
RM = rm -f
 
$(BIN): $(OBJ) calculator.c
	$(CC) calculator.c $(OBJ) -o $(BIN) $(CFLAGS) 

StackOfDoublesModule.o:StackOfDoublesModule.c StackOfDoublesModule.h
	$(CC) -c StackOfDoublesModule.c -o StackOfDoublesModule.o $(CFLAGS)
	
scanner.o: scanner.c scanner.h
	$(CC) -c scanner.c -o scanner.o $(CFLAGS)
	
.PHONY: clean
clean:
	$(RM) $(OBJ) $(BIN)