#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
 int i;
 int t;
 
 for(i=0;i<4;i++)
 {
  t=fork();
  
  if(t>0)
    break;
    
 }   
 
 printf("\nPID : %d and PPID : %d\n",getpid(),getppid());
 
 wait(NULL);
 
 return 0;
}  
