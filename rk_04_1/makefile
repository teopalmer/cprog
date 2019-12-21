all: app.exe

app.exe: main.o user_interface.c list_funcs.c
	gcc -o $@ $^ -O0 -g3 

%.o: %.c
	gcc -c $^ -o $@ -O0 -g3

clean:
	rm *.o *.exe

