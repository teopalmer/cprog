app.exe: lab.o func.o
	gcc -o $@ $^ -O0 -g3 -pedantic -Wall -Werror
test.exe: test.o func.o
	gcc -o $@ $^ -O0 -g3 -pedantic -Wall -Werror

%.o: %.c
	gcc -c $^ -o $@ -O0 -g3

clean:
	rm *.o *.exe

