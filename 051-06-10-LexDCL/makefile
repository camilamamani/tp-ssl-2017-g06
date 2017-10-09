CC = gcc
CFLAGS = -std=c11 -Wall -pedantic-errors 
BIN = calculator.exe
OBJ = StackOfDoublesModule.o scanner.o lex.yy.o
RM = rm -f
 
$(BIN): $(OBJ) calculator.c
	$(CC) calculator.c $(OBJ)  -o $(BIN) $(CFLAGS) 

StackOfDoublesModule.o:StackOfDoublesModule.c StackOfDoublesModule.h
	$(CC) -c StackOfDoublesModule.c -o StackOfDoublesModule.o $(CFLAGS)
	
scanner.o: scanner.c scanner.h 
	$(CC) -c scanner.c -o scanner.o $(CFLAGS)
	
lex.yy.o: lex.yy.c
	$(CC) -c lex.yy.c -o lex.yy.o $(CFLAGS)
	
lex.yy.c: lexCalcuPolaca.l	
	flex lexCalcuPolaca.l
	
.PHONY: clean
clean:
	$(RM) $(OBJ) $(BIN) lex.yy.c