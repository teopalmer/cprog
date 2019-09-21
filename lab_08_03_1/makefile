app.exe: lab.o func.o test.exe
	gcc -o $@ $^ -O0 -g3
test.exe: test.o func.o
	gcc -o $@ $^ -O0 -g3

%.o: %.c
	gcc -c $^ -o $@ -O0 -g3

clean:
	rm *.o *.exe

