LIB_A=libfunc.a
SRC=libfunc.c

LIBFLAGS=-mmacosx-version-min=10.1

TESTSRC=test.c
TESTCFLAGS=-mmacosx-version-min=10.7

$(LIB_A): libfunc.o
	libtool -static -o $@ libfunc.o

%.o: %.c
	$(CC) -c -o $@ $<

test: $(LIB_A) test.c
	$(CC) $(TESTCFLAGS) -o $@ test.c -L. -libfunc


clean:
	$(RM) test $(LIB_A) $(OBJ)