
/*
Csc332 - Operating System Lab
DUE: November 2, 2018
Hasibul Islam

Task 4 - System Calls Summary
*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main (int argc, char* argv[]) {
	int i, j, commands, pid_number;
	char user_input[64], *symbol, *argument_array[20] = {NULL};
	
	printf ("\nEnter Command (date OR ls): ");
	scanf(" %[^\n]s", user_input);

	// program will get terminated when the user enters quit.
	while ((strcmp(user_input,"quit"))) { 
		symbol = strtok(user_input," ");
        
		i = 0;
	while(symbol != NULL) {		argument_array[i]= symbol; 
	    symbol = strtok(NULL," ");  i++;} 
		pid_number = fork(); 
        wait(&commands);

	if (pid_number == 0) {		
		execvp (argument_array[0],argument_array);
	  	printf ("You Enter Wrong Key, Try Again!!\n");
		scanf(" %[^\n]s", user_input);
		}

	for (j=0; j < i; ++j)		argument_array[j] = NULL; 
		printf ("\nREnter command (date OR ls): ");
		scanf(" %[^\n]s", user_input);
	}
	
	return 0;
}
