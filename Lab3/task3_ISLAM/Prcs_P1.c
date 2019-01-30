/*
Csc332 - Operating System Lab
DUE: Octobar 12, 2018
Hasibul Islam

Part3: TASK 3
DUE: Oct. 12, 2018, 11:59 PM – 25 Points
Oct. 12, 2018, 11:59 PM – 15 Points

Part 3:
    [Step 1] Prcs_P1.c: Create two files namely, destination1.txt and destination2.txt with read, write, and execute
    permissions.

*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(){
	int file_destination1;
    int file_destination2;

	errno = 0;
	file_destination1 = open("destination1.txt", O_CREAT | O_RDWR, S_IRWXU);								
	file_destination2 = open("destination2.txt", O_CREAT | O_RDWR, S_IRWXU); 

    if((file_destination1 != -1 )||(file_destination2 != -1)) {
		printf("\nCreated files: destination1.txt and destination2.txt: Open() Successful\n");
		
	}
    else  {
		printf("\nOpen() Failed() with error [%s]\n", strerror(errno));
	}

	close((file_destination2)||(file_destination1));


    return 0;
}
