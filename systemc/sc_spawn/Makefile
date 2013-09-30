all: a.out
	./a.out

a.out: sc_spawn.cpp
	g++ -I$(SYSTEMC_HOME)/include -L$(SYSTEMC_HOME)/lib-linux64 -Wl,-rpath,$(SYSTEMC_HOME)/lib-linux64 -lsystemc sc_spawn.cpp

gtkwave: sc_spawn.vcd
	gtkwave $^

clean:
	rm -fr *.vcd a.out
