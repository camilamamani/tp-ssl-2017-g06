CC = gcc
CFLAGS = -std=c11 
BIN = dcl.exe
OBJ = dcl.o
RM = rm -f
 
$(BIN): $(OBJ) dcl.c
	$(CC) dcl.c $(OBJ)  -o $(BIN) $(CFLAGS) 

dcl.o: dcl.c dcl.h 
	$(CC) -c dcl.c -o dcl.o $(CFLAGS)
		
.PHONY: clean
clean:
	$(RM) $(OBJ) $(BIN) 