all: app.exe

app.exe: main.o main_funcs.o resizing_items.o user_interface.o
	gcc -o $@ $^ -O0 -g3 -pedantic -Wall -Werror

%.o: %.c
	gcc -c $^ -o $@ -O0 -g3

clean:
	rm *.o *.exe

