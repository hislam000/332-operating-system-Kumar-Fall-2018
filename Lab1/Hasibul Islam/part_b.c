
/*
Csc332 - Operating System Lab
September 21, 2018
Hasibul Islam
*/

/*
b) Write a C program where open system call creates a new file (say, destination.txt) and then opens it. (Hint:
use the bitwise OR flag)
*/
//An example to open an existing file

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h> 
#include <errno.h>


int main(int argc, char *argv[]) { 

    int filedestination; 
    
    argv[2]="destination.txt";
   
    /*
if(2 != argc) { 

        printf("\n Usage : \n"); 

    return 1;

} 
*/
    errno = 0; 


    //filedestination = open(argv[1],O_RDONLY);   
    filedestination = open(argv[2],O_CREAT | O_RDWR, S_IRWXU); 
    printf("Destination.txt file created\n");

if(-1 == filedestination)   { 
        printf("\n open() failed with error [%s]\n",strerror(errno)); 
    return 1;
} 
else { 
    
    printf("\n Open() Successful\n");
/* open() succeeded, now one can do read operations on the file opened
since we opened it in read-only mode. Also once done with processing, the file needs to be closed.*/
    }

    close(filedestination);


        return 0;
    }