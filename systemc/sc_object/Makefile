all: a.out
	./a.out

a.out: sc_object.cpp
	g++ -I$(SYSTEMC_HOME)/include -L$(SYSTEMC_HOME)/lib-linux64 -Wl,-rpath,$(SYSTEMC_HOME)/lib-linux64 -lsystemc sc_object.cpp

clean:
	rm -fr a.out
