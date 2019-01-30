/*
Csc332 - Operating System Lab
DUE: Octobar 12, 2018
Hasibul Islam

Part3: TASK 3
        DUE: Oct. 05, 2018, 11:59 PM – 25 Points
        Oct. 12, 2018, 11:59 PM – 15 Points

[Step 2] Prcs_P2.c: Copy the contents of source.txt1 into destination1.txt and destination2.txt as per the following
            procedure.
        1. Read the next 100 characters from source.txt, and among characters read, replace each character ’1’
            with character ’A’ and all characters are then written in destination1.txt
        2. Then the next 50 characters are read from source.txt, and among characters read, replace each character
            ’2’ with character ’B’ and all characters are then written in destination2.txt.
        3. The previous steps are repeated until the end of file source.txt. The last read may not have 100 or 50
            characters.
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
    int copy_source;
    int read_character;

	copy_source = open("source.txt", O_RDONLY); //source file

	file_destination1 = open("destination1.txt", O_CREAT | O_RDWR, S_IRWXU);								
	file_destination2 = open("destination2.txt", O_CREAT | O_RDWR, S_IRWXU); 

	if (copy_source == -1 && file_destination1 == -1 && file_destination2 == -1){
        
		printf("\nOpen() Failed() with error [%s]\n", strerror(errno));
	}
	else{
		char array[101];	
		int number=101;

		while ( (read_character = read(copy_source, array, number)) > 0){

			if (number == 101) {

				for (int j= 0; j < sizeof(array); j++){
					if (array[j] == '1')	array[j] = 'A';
				}
				write(file_destination1, array, read_character);
				number = 51;		               
			}
			else{
				for (int j = 0; j < sizeof(array); j++){
					if (array[j] == '2')    array[j] = 'B';
                 }
				write(file_destination2, array, read_character);
				number = 101;
			}
		}
	}	
    printf("\nCreated files: destination1.txt and destination2.txt: Open() Successful\n");
	close((copy_source)||(file_destination2)||(file_destination1));

	return 0;
}
