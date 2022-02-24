
#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>

void *print(void *threadid)
{
 printf("A\n");
 printf("B\n");
 
 //pthread_exit(NULL);
 return NULL;
}

int main()
{ 
 pthread_t t1,t2;
 
 int rc;
 
 rc=pthread_create(&t1,NULL,print,NULL);
 rc=pthread_create(&t2,NULL,print,NULL);
 
 printf("Main terminated\n");
 
 pthread_join(t2,NULL);
 
 return 0;
}
 
