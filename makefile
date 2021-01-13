#executable
run: processes.o more_strings.o prog.o
	gcc -Wall -o run prog.o processes.o more_strings.o -O2
	rm -f *.o



#example program
prog.o: prog.c processes.h src/more_strings.h
	gcc -Wall -c prog.c -O2



#processes library
processes.o: processes.c processes.h
	gcc -Wall -c processes.c -O2



#more_strings library
more_strings.o: src/more_strings.c src/more_strings.h
	gcc -Wall -c src/more_strings.c -O2
