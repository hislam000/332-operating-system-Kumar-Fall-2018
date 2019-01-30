/*
Csc332 - Operating System Lab
DUE: November 30, 2018
Hasibul Islam
Task 6: Cigarette Smokers Problem
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sem.h"		

#define PERMS 0666 //0666 - To grant read and write permissions

// Five semaphores to be used 
//Consider a system with 3 smoker processes and 1 agent process
int system_pro;
int agent_pro;

//The smoker needs three ingredients: tobacco, paper, and matches
int tobacco;
int paper;
int match;


void main() {
	if((system_pro=semget(IPC_PRIVATE, 1 ,PERMS | IPC_CREAT)) == -1){ 
		printf("Can't: Create Semaphore:\n");
  	exit(1);
	  }
	if((agent_pro=semget(IPC_PRIVATE, 1 ,PERMS | IPC_CREAT)) == -1){ 
		printf("Can't: Create Semaphore:\n");
  	exit(1);
	  }
	if((paper=semget(IPC_PRIVATE, 1 ,PERMS | IPC_CREAT)) == -1){ 
		printf("Can't: Create Semaphore:\n");
  	exit(1);
	  }
	if((tobacco=semget(IPC_PRIVATE, 1 ,PERMS | IPC_CREAT)) == -1){ 
		printf("Can't: Create Semaphore:\n");
  	exit(1);
	  }
	if((match=semget(IPC_PRIVATE, 1 ,PERMS | IPC_CREAT)) == -1){ 
		printf("Can't: Create Semaphore:\n");
  	exit(1);
	  }
	
	//Semaphore
	sem_create(system_pro,1);
	sem_create(agent_pro,0);
	sem_create(paper,0);
	sem_create(tobacco,0);
	sem_create(match,0);

	int pid;						// Process ID after fork call
	int i;							// Loop index
	int N;							// Number of times dad does update
	int status;						// Exit status of child process

	// Other integers to used
	int rand_number;					// rand_number storage
	
	//Parent Process. Fork off another child process.
		if ((pid = fork()) == -1) {
			//Fork failed!
			perror("fork");
			exit(1);
		}
	
	if (pid == 0){
	//Agent process
	
		N = 10;
		for(i = 1;i <= N;i++){	
			P(system_pro);
			rand_number = rand() % 3;
		// The smoker needs three ingredients: tobacco, paper, and matches
		if(rand_number == 0){
			printf("Tobacco and paper on the table\n");
			sleep(1);
			V(match); 
			}
		else if(rand_number == 1){
			printf("Paper and match on the table\n");
			sleep(1);
			V(paper); 
			}
		else if(rand_number == 2){
			printf("Match and paper on the table\n");
			sleep(1);
			V(tobacco); 
			}
		V(system_pro);
		P(agent_pro); 
		}
	}
	else {
		//Parent Process. Fork off one more child process.
			if ((pid = fork()) == -1) {
				//fork failed!
				perror("fork");
				exit(1);
			}
		if (pid == 0){

		while(1){
			P(tobacco); 
			P(system_pro);
		//Each smoker continuously rolls a cigarette and then smokes it
		printf("Smoker1: Tobacco picks up Match and Paper\n"); 
			sleep(1);
			V(agent_pro);
			V(system_pro);
			printf("Smoker1: Smokes!\n");
			}
		}
		else
		{
		//Parent Process. Fork off one more child process.
			if ((pid = fork()) == -1) {
				//fork failed!
				perror("fork");
				exit(1);
			}
			if (pid == 0){
			while(1) {
					P(paper);
					P(system_pro);
			//Each smoker continuously rolls a cigarette and then smokes it
				printf("Smoker2: Paper picks up Match and Tobacco\n"); 
					sleep(1);
					V(agent_pro);
					V(system_pro);
					printf("Smoker2: Smokes!\n");	}
			}
		else{ 
		if ((pid = fork()) == -1) {
				//fork failed!
				perror("fork");
				exit(1);
			}
		if (pid == 0){
		while(1){
					P(match); // Sleep right away
					P(system_pro);
			//Each smoker continuously rolls a cigarette and then smokes it
			printf("Smoker:3 Matches picks up Paper and Tobacco\n"); 
					sleep(1);
					V(agent_pro);
					V(system_pro);
					printf("Smoker3: Smokes!\n");
					}
				}
			else{
                //Now parent process waits for the child processes to finish
                    pid = wait(&status);
                    printf("Process(pid = %d), Exited with the status: %d. \n", pid, status);
				}
			}
		}
	}
	exit(0); 
}