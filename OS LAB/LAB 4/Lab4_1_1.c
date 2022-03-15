#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
 int i;
 int t,d;
 
 for(i=0;i<3;i++)
 {
  t=fork();
  
  if(t==0)
    break;
    
 }
 
 printf("PID : %d and PPID : %d\n",getpid(),getppid());
 
 while((d=wait(NULL))!=-1);
 
 return 0;
} 
