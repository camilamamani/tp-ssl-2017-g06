CC = gcc
CFLAGS = -std=c11 
BIN = yaccdcl.exe
OBJ =  yacc.tab.o lex.yy.o
RM = rm -f
 
$(BIN): $(OBJ) 
	$(CC) $(OBJ)  -o $(BIN) $(CFLAGS) 
	
lex.yy.o: lex.yy.c
	$(CC) -c lex.yy.c -o lex.yy.o $(CFLAGS)
	
lex.yy.c: lex.l	
	flex lex.l

yacc.tab.o: yacc.tab.c yacc.tab.h
	$(CC) -c yacc.tab.c -o yacc.tab.o $(CFLAGS)

yacc.tab.c: yacc.y
	bison -d yacc.y
	
.PHONY: clean
clean:
	$(RM) $(OBJ) $(BIN) lex.yy.c
