#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 

// A normal C function that is executed as a thread 
// when its name is specified in pthread_create() 
	int i=40;

void *myThreadFun(void *vargp) 
{ 
	sleep(1); 
	printf("Printing from Thread i>1\n"); 



  while (i > 1)   
  {
 //  printf("from i>1:  %d\n",i);                 
            i= i - 1;  
        }    
	printf("final from i>1: %d\n",i); 		                                
	return NULL; 
} 

void *myThreadFun2(void *vargp) 
{ 
sleep(1); 
	printf("Printing  from Thread i>5 \n"); 

			                                
 while (i > 5)
 {
// printf("from i>5: %d\n",i);
  i= i - 1;      
}
	 printf("final from i>5: %d\n",i);
	return NULL; 
} 
int main() 
{ 
	pthread_t thread_id; 
	printf("Before Thread\n"); 
	pthread_create(&thread_id, NULL, myThreadFun, NULL); 
	//pthread_join(thread_id, NULL); 
	pthread_create(&thread_id, NULL, myThreadFun2, NULL); 
	pthread_join(thread_id, NULL); 
	
	printf("Exit Thread\n"); 
	exit(0); 
}

