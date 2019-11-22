app.exe: main.o resize_matrix.o user_interface.o
	gcc -o $@ $^ -O0 -g3 -pedantic -Wall -Werror
	./app.exe

%.o: %.c
	gcc -c $^ -o $@ -O0 -g3

clean:
	rm *.o *.exe

