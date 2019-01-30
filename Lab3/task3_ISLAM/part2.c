/*
Csc332 - Operating System Lab
DUE: Octobar 12, 2018
Hasibul Islam

DUE: Oct. 05, 2018, 11:59 PM – 25 Points
Oct. 12, 2018, 11:59 PM – 15 Points
    Part 2 Write a program where a child is created to execute a command that shows all files (including hidden files) in
    a directory with information such as permissions, owner, size, and when last modified. Use execvp(...).
    For the command to list directory contents with various options, refer the handout on Unix file system sent to
    you in the first class.
    Announce the successful forking of child process by displaying its PID.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){	
	int execute;
	int pid_number = fork();   // First child create
	
	if(pid_number != 0){
        
		printf("\nParent PID is: %d\n", getpid());    //Parent    
       
	}

	else{
		printf("I am child one, my PID is: %d\n\n", getpid());   //First child
        printf("Execute Files:\n");
        printf("------------------------------------------------------\n");
        char *listing[] = {"ls", "-la", 0}; 
        execvp(listing[0], listing);

		printf ("EXECVP Failed\n");
    /* The above line will be printed only on error and not otherwise */
    }
	wait(&execute);
	return 0;
}
