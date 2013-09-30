all: a.out
	./a.out

a.out: sc_port.cpp
	g++ -I$(SYSTEMC_HOME)/include -L$(SYSTEMC_HOME)/lib-linux64 -Wl,-rpath,$(SYSTEMC_HOME)/lib-linux64 -lsystemc sc_port.cpp

clean:
	rm -fr a.out
