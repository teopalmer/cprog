
apps.exe: main.o libstat.a
		$(CC) -o $@ main.o -L. -lstat

appd.exe: main.o
		$(CC) main.o -L. -ldyn -Wl,-rpath,. -o appd.exe

appl.exe:
		$(CC) main_d.c -ldl -o appl.exe

libstat.a: libstat.o
	libtool -static -o $@ libstat.o

dynamic:
	$(CC) -fPIC -c darray.c -o darray.o
	$(CC) -shared -o libdyn.so darray.o

static: libstat.o
	ar rc libstat.a libstat.o
	ranlib libstat.a

sprog:
	make static
	make apps.exe

dprog:
	make dynamic
	make appd.exe

lprog:
	make dynamic
	make appl.exe

%o: %c %h 
	gcc -std=c99 -Wall -Werror -c $< 

clean:
	rm *.o *.exe *.a *.so *.out *.txt
