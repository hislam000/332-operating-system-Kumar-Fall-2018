
/*
Csc332 - Operating System Lab
September 21, 2018
Hasibul Islam
*/

/*
The cp command copies the source file specified by the SourceFile parameter to the destination file specified
by the DestinationFile parameter.
Write a C program that mimics the cp command using open() system call to open source.txt file in read-only
mode and copy the contents of it to destination.txt using read() and write() system calls.
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
    int access_file;
    int destination;
    
    errno = 0;
    
    //openting the source file
    filedestination = open(argv[1], O_RDONLY);
    printf("SourceFile %s opened \n",argv[1]);

    access_file = access(argv[2], F_OK);
    if (access_file == 0) {
        unlink(argv[2]);
    }
    
    //Opening or creating destination file
    destination = open(argv[2], O_CREAT | O_RDWR, S_IRWXU); 
    printf("DestinationFile %s opened \n",argv[2]);
    if (filedestination == -1){
        printf("\n Error in open(): [%s]\n", strerror(errno));
    }
    else {
        char buf[BUFSIZ];
        
        while (( read_d = read(filedestination, buf, BUFSIZ)) > 0) {  
            write(destination, buf, read_d);
        }
    }
    //Contents copied
    printf("Contents copied\n");
    close(filedestination);
    close(destination);
    
    return 0;
    
}

/*
./cp source.txt dest.txt
*/