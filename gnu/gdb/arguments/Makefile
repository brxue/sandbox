a.out: main.cpp
	g++ -g $^

args1: a.out
	gdb --args a.out -DDEBUG -width 10 --height 20

args2: a.out
	gdb --eval-command 'set args -DDEBUG -width 10 --height 20' a.out

args3: a.out
	gdb --eval-command 'file a.out' --eval-command 'start -DDEBUG -width 10 --height 20'

args4: a.out
	gdb --eval-command 'file a.out' --eval-command 'run -DDEBUG -width 10 --height 20'

clean:
	rm -fr a.out
