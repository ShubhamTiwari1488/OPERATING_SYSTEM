
#include<stdio.h>
//#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
 int t=fork();	//Creating a process
 
 //wait(&t);
 
 printf("\nHello World pid is %d and ppid is %d\n",getpid(),getppid());
 
 wait(&t);
 
 return 0;
}
 
