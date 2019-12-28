all: app.exe test.exe

app.exe: main.o list_funcs.c main_funcs.c str_funcs.c user_interface.c
	gcc -o $@ $^ -O0 -g3 -pedantic -Wall -Werror

test.exe: test.o list_funcs.c main_funcs.c str_funcs.c user_interface.c
	gcc -o $@ $^ -O0 -g3 -pedantic -Wall -Werror

ftest:
	./create.sh

%.o: %.c
	gcc -c $^ -o $@ -O0 -g3

clean:
	rm *.o *.exe

