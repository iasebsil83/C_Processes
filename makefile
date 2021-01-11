#executable
run: processes.o prog.o
	gcc -Wall -o run prog.o processes.o -O2
	rm -f *.o



#example program
prog.o: prog.c processes.h
	gcc -Wall -c prog.c -O2



#processes library
processes.o: processes.c processes.h
	gcc -Wall -c processes.c -O2
