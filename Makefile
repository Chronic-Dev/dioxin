all: linux test

linux:
	g++ -Wall -fPIC -c dioxin.c
	g++ -limobiledevice -shared -Wl,-soname,libdioxin.so -o libdioxin.so *.o

test:
	g++ -L. -ldioxin test.c -o test -I.

clean:
	rm *.o
	rm *.so
	rm test

install:
	cp *.so /usr/lib
	mkdir -p /usr/include/dioxin/
	cp includes/*.h /usr/include/dioxin/
