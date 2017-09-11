CC = gcc
CFLAGS = -std=c11 -Wall -pedantic-errors 
BIN = calculator.exe
OBJ = StackOfDoublesModule.o scanner.o
RM = rm -f
 
$(BIN): $(OBJ) calculator.c
	$(CC) calculator.c $(OBJ) -o $(BIN) $(CFLAGS) 

StackOfDoublesModule.o:StackOfDoublesModule.c StackOfDoublesModule.h
	$(CC) -c StackOfDoublesModule.c -o StackOfDoublesModule.o $(CFLAGS)
	
scanner.o: scanner.c scanner.h lex.yy.o
	$(CC) scanner.c lex.yy.o -o scanner.o $(CFLAGS)
	
lex.yy.o: lex.yy.c
	$(CC) -c lex.yy.c -o lex.yy.o $(CFLAGS)
	
lex.yy.c: lexCalcuPolaca.l	
	flex lexCalcuPolaca.l
	
.PHONY: clean
clean:
	$(RM) $(OBJ) $(BIN)