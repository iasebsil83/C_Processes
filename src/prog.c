// ---------------- IMPORTATIONS ----------------

//standard
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>




//processes utility
#include "../lib/processes.h"








/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Prog [V.V.V] ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                          processes.h demonstration program

        Blablabla about the subject.

    DD/MM/YYYY > [V.V.V] :
    - Added something.
    - Added something else.

    DD/MM/YYYY > [V.V.V] :
    - Added something that wasn't before.
    - Fixed a bug.
    - Added something else.
    - Added something else again.

    BUGS : Active bugs in last version.
    NOTES : Notes.

    Contact : ...
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */








// ---------------- DECLARATIONS ----------------

//string allocation shortcut
char* malloc_string(char* s){
	char* newS = malloc(strlen(s));
	if(newS == NULL){
		printf("FATAL ERROR > prog.c : malloc_string() : PID[%i], PPID[%i] : Computer refuses to give more memory.\n", getpid(), getppid());
		exit(EXIT_FAILURE);
	}

	//write text
	sprintf(newS, "%s", s);
	return newS;
}








// ---------------- EXECUTION ----------------

//main
int main(){
	//presentation
	printf("I.A. > PID[%i], PPID[%i] : This is a basic example of process management using \"processes.c/.h\".\n", getpid(), getppid());



	//create subprocess 1
	printf("I.A. > PID[%i], PPID[%i] : Creating process 1.\n", getpid(), getppid());
	char** command1 = malloc(4*sizeof(char*));
	if(command1 == NULL){
		printf("FATAL ERROR > prog.c : main() : PID[%i], PPID[%i] : Computer refuses to give more memory.\n", getpid(), getppid());
		exit(EXIT_FAILURE);
	}
	command1[0] = malloc_string("run");
	command1[1] = malloc_string("02");
	command1[2] = malloc_string("25");
	command1[3] = NULL;
	proc* p1 = proc_create(
		"src/program1/run",
		command1
	);



	//create subprocess 2
	printf("I.A. > PID[%i], PPID[%i] : Creating process 2.\n", getpid(), getppid());
	char** command2 = malloc(4*sizeof(char*));
	if(command2 == NULL){
		printf("FATAL ERROR > prog.c : main() : PID[%i], PPID[%i] : Computer refuses to give more memory.\n", getpid(), getppid());
		exit(EXIT_FAILURE);
	}
	command2[0] = malloc_string("run");
	command2[1] = malloc_string("22");
	command2[2] = malloc_string("35");
	command2[3] = NULL;
	proc* p2 = proc_create(
		"src/program2/run",
		command2
	);



	//start subprocess 1
	printf("I.A. > PID[%i], PPID[%i] : Starting process 1 (path \"src/program1/run\" with command \"./run 02 25\").\n", getpid(), getppid());
	proc_start(p1);

	//sleep 2 seconds
	printf("I.A. > PID[%i], PPID[%i] : Sleeping 2 seconds.\n", getpid(), getppid());
	usleep(2000000);

	//start subprocess 2
	printf("I.A. > PID[%i], PPID[%i] : Starting process 2 (path \"src/program2/run\" with command \"./run 22 45\").\n", getpid(), getppid());
	proc_start(p2);

	//sleep 10 seconds
	printf("I.A. > PID[%i], PPID[%i] : Sleeping 4 seconds.\n", getpid(), getppid());
	usleep(4000000);




	//stop subprocess 1
	printf("I.A. > PID[%i], PPID[%i] : Stopping process 1 in \"kill\" mode.\n", getpid(), getppid());
	proc_stop(p1, PROC__STOP_KILL);
	printf("I.A. > PID[%i], PPID[%i] : Process 1 stopped.\n", getpid(), getppid());

	//sleep 4 seconds
	printf("I.A. > PID[%i], PPID[%i] : Sleeping 4 seconds.\n", getpid(), getppid());
	usleep(4000000);

	//stop subprocess 2
	printf("I.A. > PID[%i], PPID[%i] : Stopping process 2 in \"wait\" mode.\n", getpid(), getppid());
	proc_stop(p2, PROC__STOP_WAIT);
	printf("I.A. > PID[%i], PPID[%i] : Process 2 stopped.\n", getpid(), getppid());



	//delete subprocesses
	printf("I.A. > PID[%i], PPID[%i] : Deleting processes.\n", getpid(), getppid());
	proc_delete(p1);
	proc_delete(p2);



	return EXIT_SUCCESS;
}
