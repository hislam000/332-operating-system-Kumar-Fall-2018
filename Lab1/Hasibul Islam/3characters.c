
/*
Csc332 - Operating System Lab
September 21, 2018
Hasibul Islam
*/

/*
Repeat part 2 (by writing a new C program) as per the following procedure:
(a) Read the next 100 characters from source.txt, and among characters read, replace each character ’1’
with character ’A’ and all characters are then written in destination.txt
(b) Write characters "XYZ" into file destination.txt
(c) Repeat the previous steps until the end of file source.txt. The last read step may not have 100 characters.
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int filedestination; 
    int read_d; 
    int access_file; 
    int destination;
    
    filedestination = open(argv[1], O_RDONLY);
    printf("Source file Opened\n");
    
    access_file = access(argv[2], F_OK);
    if (access_file == 0) {
        unlink(argv[2]);
    }
    
    destination = open(argv[2], O_CREAT | O_RDWR, S_IRWXU);
    printf("Destination File opened/created \n");
    if (filedestination == -1) {
        printf("\n Error in open() [%s]\n", strerror(errno));
    }
    else {
        char buffer[104];
        int read_d;
        
        // 100 chars
        //scanned '1' 
        //replace 'A'

    /*Read the next 100 characters from source.txt, and among characters read, replace each character ’1’
with character ’A’ and all characters are then written in destination.txt
    */
        while (( read_d = read(filedestination, buffer, 101)) > 0) {

            for (int j = 0; j < read_d; j++) {
                if (buffer[j] == '1')
                    buffer[j] = 'A';
            }
        //write XYZ
        //Write characters "XYZ" into file destination.txt
            buffer[read_d] = 'X';
            buffer[read_d+1] = 'Y';
            buffer[read_d+2] = 'Z';
            
            write(destination, buffer, read_d+3);
            
        }
        
        
    }
    printf("Required Operations are done\n");
    //close
    close(filedestination);
    close(destination);
    
    return 0;
    
}

