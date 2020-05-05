#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 

// A normal C function that is executed as a thread 
// when its name is specified in pthread_create() 
	int i=1,x=1;

void *myThreadFun(void *vargp) 
{ 
	sleep(1); 
	printf("Printing from Thread1 i<4\n"); 

   while (i<4)
  { x=x*2;
  i=i+1; 
printf(" from thread 1: i=%d x=%d\n",i,x);      
                    } 
					    
	printf("final from thread 1: i=%d x=%d\n",i,x); 		                                
	return NULL; 
} 

void *myThreadFun2(void *vargp) 
{ 
sleep(1); 
	printf("Printing  from Thread2 i<4 \n"); 

			                                

 while (i<4)
  { x=x*2;
  i=i+1; 
  	printf(" from thread 2: i=%d x=%d\n",i,x);   
                    } 
					    
	printf("final from thread 2: i=%d x=%d\n",i,x); 		                                
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

