/*
Csc332 - Operating System Lab
DUE: September 29, 2018
Hasibul Islam

TASK 2 DUE: September 29, 2018, 11:59 PM – 15 Points

Part 1:Write a program children.c, and let the parent process produce two child processes. One prints out "I am child
    one, my pid is: " PID, and the other prints out "I am child two, my pid is: " PID. Guarantee that the parent
    terminates after the children terminate (Note, you need to wait for two child processes here). Use the getpid()
    function to retrieve the PID.
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {	
	int produce;
    int pid_child1;
    int pid_child2;


	pid_child1 = fork();   // first child

	//2 child processes from the parent

	if(pid_child1 != 0){
		printf("Parent PID is: %d\n", getpid()); 
	}

	else{
		printf("I am child one, my PID is: %d\n", getpid());  
		pid_child2 = fork(); // second child
		

		if (pid_child2 == 0){	
		printf("I am child two, my PID is: %d\n", getpid());
		}
        wait(&produce);
	}
    wait(&produce);

	return 0;
}


