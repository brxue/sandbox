all: main
	pwd && ./main

main: lib/libhello.so main.cc
	g++ -g -o main main.cc -ldl

lib/libhello.so: hello.o
	(test -d ./lib || mkdir lib) && g++ -g -fPIC -shared -o $@ $^

hello.o: hello.h hello.cc
	g++ -fPIC -I.. -g -o $@ -c hello.cc

clean: 
	rm -fr hello.o lib main core.*
