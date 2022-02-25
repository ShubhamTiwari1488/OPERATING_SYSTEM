#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
 int a=2;
 
 int t=getpid();
 
 fork();
 
 if(t==getppid())   //Child Process will only execute this
     a++;
     
 printf("\nValue = %d , addr = %p , PID = %d , PPID = %d\n",a,&a,getpid(),getppid());
 
 wait(NULL);
 
 return 0;
}
  
