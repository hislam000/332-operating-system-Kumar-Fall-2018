/*
Csc332 - Operating System Lab
DUE: Octobar 12, 2018
Hasibul Islam

Part3: TASK 3
DUE: Oct. 05, 2018, 11:59 PM – 25 Points
Oct. 12, 2018, 11:59 PM – 15 Points
    [Step 3] Fork a child process, say Child 1 and execute Prcs_P1. This will create two destination files according
    to Step 1.
    [Step 4] After Child 1 finishes its execution, fork another child process, say Child 2 and execute Prcs_P2 that
    accomplishes the procedure described in Step 2.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){ char *const argv[] = {"Prcs_P1","Prcs_P2", NULL};
	
	int Step_1 = fork();
	
	if(Step_1 == 0) {
		
		printf("Child 1 and execute Prcs_P1.\n");
		execv(argv[0], argv); 
		printf("EXECV Failed!\n");

	}
	else { sleep(1); 
		
		int Step_2 = fork();
		if (Step_2 == 0) {
		
			printf("Child 2 and execute Prcs_P2.n");
			execv(argv[0], argv); 
			printf("EXECV Failed!\n");
		}
	}	return 0;
}
