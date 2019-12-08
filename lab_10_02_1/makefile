all: app.exe test.exe

app.exe: main.o main_funcs.o resizing_items.o user_interface.o
	gcc -o $@ $^ -O0 -g3 -Wpedantic -Wall -Werror -Wextra

test.exe: test.o main_funcs.o resizing_items.o user_interface.o
	gcc -o $@ $^ -O0 -g3 -Wpedantic -Wall -Werror -Wextra

utest: test.exe
	./test.exe
ftest: 
	cd ./tests && ./create.sh && cd ..

%.o: %.c
	gcc -c $^ -o $@ -O0 -g3 -Wpedantic -Wall -Werror -Wextra

clean:
	rm *.o *.exe stockpile.txt

