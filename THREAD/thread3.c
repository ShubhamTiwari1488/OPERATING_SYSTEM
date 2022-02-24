#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS	5
int p=0;
void *PrintHello(void *threadid)
{
   for(int i=0;i<10;i++){
   printf("A\nB\n");
   p++;
	}
   pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
   pthread_t t1,t2;
   int rc;
   int t;
   char data[]="good";
  
   rc = pthread_create(&t1, NULL, PrintHello,NULL);
   rc = pthread_create(&t2, NULL, PrintHello,NULL);
   
   printf("Value of p is %d\n",p);
   
   printf("main Terminates\n");

   pthread_join(t1,NULL);
   
   printf("Value of p is %d\n",p);
   
   return 0;
}
