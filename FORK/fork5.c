#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
 int a=2,p;
 
 int t=getpid();
 
 fork();
 
 if(t==getpid())	//Parent Process will execute this
 	a++;
 	
 printf("PID %d , PPID %d and a = %d\n",getpid(),getppid(),a);
 
 wait(&p);
 
 return 0;
}
 
