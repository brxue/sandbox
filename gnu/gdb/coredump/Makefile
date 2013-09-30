run: compile
	rm -rf core.*
	./main

# To set core dump size
# Maximum size
#	unlimit coredumpsize
# Specific size
#	limit coredumpsize 1024
#	limit coredumpsize 0   (no coredump)
compile: main.c
	gcc main.c -g -o main

debug_dump: 
	mv core.* core
	gdb main core

clean: 
	rm -fr main core core.*
