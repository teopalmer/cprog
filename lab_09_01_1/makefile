all: app.exe test.exe

app.exe: main.o resizing_matrix.o calculating_matrix.o user_interface.o
	gcc -o $@ $^ -O0 -g3 -pedantic -Wall -Werror

test.exe: test.o resizing_matrix.o calculating_matrix.o user_interface.o
	gcc -o $@ $^ -O0 -g3 -pedantic -Wall -Werror

%.o: %.c
	gcc -c $^ -o $@ -O0 -g3

clean:
	rm *.o *.exe

