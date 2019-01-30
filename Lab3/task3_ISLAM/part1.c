
/*
Csc332 - Operating System Lab
DUE: Octobar 12, 2018
Hasibul Islam


TASK 3
DUE: Oct. 05, 2018, 11:59 PM – 25 Points
Oct. 12, 2018, 11:59 PM – 15 Points
	Part 1 Write a program where a child is created to execute command that tells you the date and time in Unix.
	Use execl(...).
	Note, you need to specify the full path of the file name that gives you date and time information.
	Announce the successful forking of child process by displaying its PID.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {	
	int execute;
	int pid_number = fork();   // First child create
	
	if(pid_number != 0){
		printf("\nParent PID is: %d\n", getpid());    //Parent 
	}

	else{
		printf("I am child one, my PID is: %d\n\n", getpid());   //First child

		printf("ExecuteTime:\n");
		 //other way say NUll<-> 0,0
		 //Time base on current to print
		execl("/bin/date", "date", 0, 0); 
		
		printf("\nEXECL() Failed()\n");
		
	}
	
	wait(&execute);
	return 0;
}
