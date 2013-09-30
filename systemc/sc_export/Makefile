all: a.out
	./a.out

a.out: sc_export.cpp
	g++ -I$(SYSTEMC_HOME)/include -L$(SYSTEMC_HOME)/lib-linux64 -Wl,-rpath,$(SYSTEMC_HOME)/lib-linux64 -lsystemc sc_export.cpp

clean:
	rm -fr a.out
