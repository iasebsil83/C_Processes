#ifndef PROCESSES_H
#define PROCESSES_H




















// -------------------------------- DEFINITIONS --------------------------------

//structures
struct PROC{
	char* exePath;
	char** args;
	pid_t pid;
};
typedef struct PROC proc;




















// -------------------------------- PROCESSES --------------------------------

//create - delete
proc* proc_create(char* exePath, char** args);
void proc_delete(proc* p); //will NOT free the given data in proc_create() (exePath & args)

//start - stop
void proc_start(proc* p);
void proc_stop(proc* p);




















#endif
