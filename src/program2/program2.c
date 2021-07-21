// ---------------- IMPORTATIONS ----------------

//standard
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>












// ---------------- FUNCTIONS ----------------

//utilities
int char2int(char c){
	switch(c){
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
	}

	return 0;
}












// ---------------- EXECUTION ----------------

//main
int main(int argc, char** argv){

	//get arguments
	int low =
		10*char2int(argv[1][0]) +
		   char2int(argv[1][1])
	;
	int high =
		10*char2int(argv[2][0]) +
		   char2int(argv[2][1])
	;
	printf("P2 > PID[%i], PPID[%i] : Counting from %i to %i.\n", getpid(), getppid(), low, high-1);

	//count from #low# to #high#
	for(int i=low; i < high; i++){
		printf("P2 > PID[%i], PPID[%i] : %i.\n", getpid(), getppid(), i);
		usleep(1000000);
	}



	return EXIT_SUCCESS;
}
