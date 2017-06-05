CC=gcc
PATH=
DEPS = Test.c
OBJA = rc-a.c 
OBJB = rc-b.c 

RemoveCommentsA: $(OBJA)
	$(CC) -o $(PATH)$@ $(PATH)$^ $(CFLAGS)

RemoveCommentsB: $(OBJB)
	$(CC) -o $(PATH)$@ $(PATH)$^ $(CFLAGS)

.PHONY: execA execB 

execA: 
	$(PATH)RemoveCommentsA < $(PATH)Test.c > $(PATH)NoCommentA.c

execB:
	$(PATH)RemoveCommentsB < $(PATH)Test.c > $(PATH)NoCommentB.c
