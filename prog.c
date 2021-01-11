// ---------------- IMPORTATIONS ----------------

//standard
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



//processes utility
#include "processes.h"




















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

    Contact : 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */




















// ---------------- EXECUTION ----------------

//main
int main(){
	//presentation
	printf("I.A. > PID[%i], PPID[%i] : This is a basic example of process management using \"processes.c/.h\".\n", getpid(), getppid());






	//create subprocess 1
	printf("I.A. > PID[%i], PPID[%i] : Creating process 1.\n", getpid(), getppid());
	char* command1[] = {
		"run", "02", "25", NULL
	};
	proc* p1 = proc_create(
		"examples/program1/run",
		command1
	);



	//create subprocess 2
	printf("I.A. > PID[%i], PPID[%i] : Creating process 2.\n", getpid(), getppid());
	char* command2[] = {
		"run", "22", "45", NULL
	};
	proc* p2 = proc_create(
		"examples/program2/run",
		command2
	);



	//start subprocess 1
	printf("I.A. > PID[%i], PPID[%i] : Starting process 1 (path \"examples/program1/run\" with command \"./run 02 25\").\n", getpid(), getppid());
	proc_start(p1);

	//sleep 2 seconds
	printf("I.A. > PID[%i], PPID[%i] : Sleeping 2 seconds.\n", getpid(), getppid());
	usleep(2000000);

	//start subprocess 2
	printf("I.A. > PID[%i], PPID[%i] : Starting process 2 (path \"examples/program2/run\" with command \"./run 22 45\").\n", getpid(), getppid());
	proc_start(p2);

	//sleep 10 seconds
	printf("I.A. > PID[%i], PPID[%i] : Sleeping 5 seconds.\n", getpid(), getppid());
	usleep(10000000);




	//stop subprocess 1
	printf("I.A. > PID[%i], PPID[%i] : Stopping process 1.\n", getpid(), getppid());
	proc_stop(p1);

	//sleep 4 seconds
	printf("I.A. > PID[%i], PPID[%i] : Sleeping 4 seconds.\n", getpid(), getppid());
	usleep(4000000);

	//stop subprocess 2
	printf("I.A. > PID[%i], PPID[%i] : Stopping process 2.\n", getpid(), getppid());
	proc_stop(p2);



	//delete subprocesses
	printf("I.A. > PID[%i], PPID[%i] : Deleting processes.\n", getpid(), getppid());
	proc_delete(p1);
	proc_delete(p2);






	return EXIT_SUCCESS;
}
