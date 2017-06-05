CC=gcc
PATH=
DEPS = Test.c
OBJA = rc-a.c 
OBJB = rc-b.c 

RemoveCommentsA: $(OBJA)
	$(CC) -o $(PATH)$@ $(PATH)$^ $(CFLAGS)

RemoveCommentsB: $(OBJB)
	$(CC) -o $(PATH)$@ $(PATH)$^ $(CFLAGS)

.PHONY: exec1 exce2 

exec1: 
	$(PATH)RemoveCommentsA < $(PATH)Test.c > $(PATH)NoCommentA.c

exec2:
	$(PATH)RemoveCommentsB < $(PATH)Test.c > $(PATH)NoCommentB.c