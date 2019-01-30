
/*
Csc332 - Operating System Lab
September 21, 2018
Hasibul Islam
*/

/*
UNIX cat command has three functions with regard to text files: displaying them, combining copies of them
and creating new ones.
5
Write a C program to implement a command called displaycontent that takes a (text) file name as argument
and display its contents. Report an appropriate message if the file does not exist or can’t be opened (i.e. the
file doesn’t have read permission). You are to use open(), read(), write() and close() system calls.
*/


#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    
    int filedestination; 
    int read_d; 
    int ct;

/* // creating and checking text file
if(2 != argc)
    {
        printf("\n Usage : Enter a file name  \n");
        return -1;
    }
*/

    errno = 0;
    
    // read and writing 
    // open argument file
    filedestination = open(argv[1], O_RDWR);   
    

    /*
    Report an appropriate message if the file does not exist or can’t be opened (i.e. the
file doesn’t have read permission). You are to use open(), read(), write() and close() system calls.
    */
    if (filedestination == -1) {
        printf("\n Error: file does not exist or can’t be opened(): [%s]\n", strerror(errno));
    }

    //if no error than cheking read and write error
    else {
        char buffer[BUFSIZ];
        
    while ( (read_d = read(filedestination, buffer, BUFSIZ)) > 0) 
    {         
            write(1, buffer, read_d);                                
        }
    }

// close file 
    close(filedestination);
    
    return 0;
    
}

