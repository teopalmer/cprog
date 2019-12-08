all: test.exe

test.exe: test.o snprintf.c str_funcs.c
	gcc -o $@ $^ -O0 -g3 -pedantic -Wall -Werror

utest: test.exe
	./test.exe

%.o: %.c
	gcc -c $^ -o $@ -O0 -g3

clean:
	rm *.o *.exe

