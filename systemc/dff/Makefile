all: a.out
	./a.out

a.out: dff.cpp
	g++ -I$(SYSTEMC_HOME)/include -L$(SYSTEMC_HOME)/lib-linux64 -Wl,-rpath,$(SYSTEMC_HOME)/lib-linux64 -lsystemc dff.cpp

gtkwave: dff.vcd
	gtkwave $^

clean:
	rm -fr *.vcd a.out
