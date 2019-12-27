CC = gcc
CFLAGS = -std=c99 -Wall -Werror 

app_static.exe: main.o libstat.a
		$(CC) -o $@ main.o -L. -lstat

app_dynamic_d.exe: main.o
		$(CC) main.o -L. -ldyn -Wl,-rpath,. -o app_dynamic_d.exe

app_dynamic_l.exe:
		$(CC) main_d.c -ldl -o app_dynamic_l.exe

libstat.a: libstat.o
	libtool -static -o $@ libstat.o

%o: %c %h 
	$(CC) $(CFLAGS) -c $< 

clean:
	rm *.o *.exe *.a *.so *.out *.txt

dynamic:
	$(CC) -fPIC -c darray.c -o darray.o
	$(CC) -shared -o darray.so darray.o

static: libstat.o
	ar rc libstat.a libstat.o
	ranlib libstat.a

sprog:
	make static
	make app_static.exe

dprog:
	make dynamic
	make app_dynamic_d.exe

lprog:
	make dynamic
	make app_dynamic_l.exe
