#include<pthread.h>
#include<stdio.h>
//#include<unistd.h>

#define NUM_THREADS 5

void *PrintHello(void *threadid)
{
 printf("A\n");
 printf("B\n");
 
 pthread_exit(NULL);
}

int main()
{
 pthread_t t1,t2;
 
 pthread_create(&t1,NULL,PrintHello,NULL);
 pthread_create(&t2,NULL,PrintHello,NULL);
 
 printf("main Terminated\n");
 
 //sleep(1);
 
 //Waiting for completion of thread2
 
 //printf("Waiting for thread 2\n");
 
 pthread_join(t2,NULL);
 
 return 0;
}   
