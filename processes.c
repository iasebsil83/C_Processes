// -------------------------------- IMPORTATIONS --------------------------------

//standard
#include <stdio.h>
#include <stdlib.h>



//processes management
#include <unistd.h>
#include <sys/wait.h>
#include <stdint.h>
#include <signal.h>
#include <sys/wait.h>



//own header
#include "processes.h"




















/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Processes [0.1.0] ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                                 Processes by I.A.

        Processes is just an utility program that allows you to manipulate
    processes more simply than standard c does.

    This program only adds 4 functions :
     - proc_create()
     - proc_delete()
     - proc_start()
     - proc_stop()

    08/01/2021 > [0.1.0] :
    - Created processes.c/.h.

    BUGS : .
    NOTES : .

    Contact     : i.a.sebsil83@gmail.com
    Youtube     : https://www.youtube.com/user/IAsebsil83
    GitHub repo : https://github.com/iasebsil83

    Let's Code !                                  By I.A.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */




















// -------------------------------- PROCESSES --------------------------------

//create - delete
proc* proc_create(char* exePath, char** args){
	if(exePath == NULL || args == NULL){
		printf("RUNTIME ERROR > processes.c : proc_create() : Process executable path or arguments are NULL.\n");
		return NULL;
	}

	//create new process
	proc* p = malloc(sizeof(proc));
	if(p == NULL){
		printf("FATAL ERROR > processes.c : proc_create() : Computer refuses to give more memory.\n");
		exit(EXIT_FAILURE);
	}

	//set struct values
	p->exePath = exePath;
	p->args = args;
	p->pid = 0;

	return p;
}

void proc_delete(proc* p){ //will NOT free the given data in proc_create() (exePath & args)

	//error cases
	if(p == NULL){
		printf("RUNTIME ERROR > processes.c : proc_delete() : Process is NULL.\n");
		return;
	}
	if(p->exePath == NULL || p->args == NULL){
		printf("RUNTIME ERROR > processes.c : proc_delete() : Process executable path or arguments are NULL.\n");
		return;
	}

	//liberation
	free(p);
}



//start - stop
void proc_start(proc* p){

	//error cases
	if(p == NULL){
		printf("RUNTIME ERROR > processes.c : proc_start() : Process is NULL.\n");
		return;
	}
	if(p->exePath == NULL || p->args == NULL){
		printf("RUNTIME ERROR > processes.c : proc_start() : Process executable path or arguments are NULL.\n");
		return;
	}

	//launch new process
	pid_t error = fork();
	int errorCode = 0;
	switch(error){

		//cannot create fork
		case -1:
			printf("RUNTIME ERROR > processes.c : proc_start() : Unable to create a subprocess (called for \"%s\").\n", p->exePath);
			return;
		break;

		//fork created
		case 0:
			//set pid
			p->pid = getpid();

			//launch subprocess execution
			errorCode = execv(p->exePath, p->args);

			//error case
			printf("FATAL ERROR > processes.c : proc_start() : New subprocess [%i] was unable to run executable \"%s\" with error code (%i).\n", p->pid, p->exePath, errorCode);
			exit(EXIT_FAILURE);
		break;

		//parent fork continues
		default:
			p->pid = error;
		break;
	}
}

void proc_stop(proc* p){

	//error cases
	if(p == NULL){
		printf("RUNTIME ERROR > processes.c : proc_stop() : Process is NULL.\n");
		return;
	}
	if(p->exePath == NULL || p->args == NULL){
		printf("RUNTIME ERROR > processes.c : proc_stop() : Process executable path or arguments are NULL.\n");
		return;
	}
	if(p->pid <= 0){
		printf("RUNTIME ERROR > processes.c : proc_stop() : Invalid pid [%i] (must be strict positive).\n", p->pid);
		return;
	}

	//stop process
	if( kill(p->pid, SIGKILL) ){
		printf("RUNTIME ERROR > processes.c : proc_stop() : Could not send stop signal to process.\n");
		return;
	}

	//wait for process reception
	int status;
	if( waitpid(p->pid, &status, 0) == -1){
		printf("RUNTIME ERROR > processes.c : proc_stop() : Problem occured when waiting for process return status.\n");
		return;
	}
}
