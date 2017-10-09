CC = gcc
CFLAGS = -std=c11 
BIN = lexdcl.exe
OBJ = dcl.o lex.yy.o
RM = rm -f
 
$(BIN): $(OBJ) 
	$(CC) $(OBJ)  -o $(BIN) $(CFLAGS) 
	
dcl.o: dcl.c dcl.h 
	$(CC) -c dcl.c -o dcl.o $(CFLAGS)
	
lex.yy.o: lex.yy.c
	$(CC) -c lex.yy.c -o lex.yy.o $(CFLAGS)
	
lex.yy.c: lex.l	
	flex lex.l
	
.PHONY: clean
clean:
	$(RM) $(OBJ) $(BIN) lex.yy.c