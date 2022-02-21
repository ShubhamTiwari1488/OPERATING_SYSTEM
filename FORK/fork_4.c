
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
 int p;
 int a=2;
 int t=getpid();
 a++;
 fork();
 
 printf("\nValue is %d , address is %p , PID is %d and PPID is %d\n",a,&a,getpid(),getppid());
 
 wait(&p);
 
 return 0;
}
 
