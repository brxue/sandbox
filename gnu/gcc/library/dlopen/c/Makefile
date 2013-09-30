all: main
	pwd && ./main

main: lib/libhello.so main.c
	gcc -g -o main main.c -ldl

lib/libhello.so: hello.o
	(test -d ./lib || mkdir lib) && gcc -g -fPIC -shared -o $@ $^

hello.o: hello.h hello.c
	gcc -fPIC -I.. -g -o $@ -c hello.c

clean: 
	rm -fr hello.o lib main core.*
