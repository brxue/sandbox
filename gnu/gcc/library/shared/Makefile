all: main
	./main

main: lib/libhello.so main.cc
	g++ -o main main.cc -L./lib -Wl,-rpath,./lib -lhello 

lib/libhello.so: hello.o
	(test -d ./lib || mkdir lib) && g++ -fPIC -shared -o $@ $^

hello.o: hello.h hello.cc
	g++ -fPIC -o $@ -c hello.cc

clean: 
	rm -fr hello.o lib main
