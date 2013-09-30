all: main
	./main

# Note that main.cc must be specified before "-L. -lhello", 
# or else "undefined reference to hello()" will be reported
main: lib/libhello.a main.cc
	g++ -o main main.cc -L./lib -lhello 

lib/libhello.a: hello.o
	(test -d ./lib || mkdir lib) && ar rcs $@ $^

hello.o: hello.h hello.cc
	g++ -o $@ -c hello.cc

clean: 
	rm -fr hello.o lib main
