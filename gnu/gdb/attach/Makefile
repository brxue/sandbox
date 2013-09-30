run: a.out
	./$^

a.out: main.cpp
	g++ -g $^

attach1: a.out
	gdb a.out `ps x | grep a.out | head -n 1 | cut -d ' ' -f 1`

attach2: a.out
	gdb --eval-command "attach `ps x | grep a.out | head -n 1 | cut -d ' ' -f 1`" a.out

clean: 
	rm -fr a.out
