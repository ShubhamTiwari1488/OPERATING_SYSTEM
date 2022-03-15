#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
 int t,i;
 
 for(i=0;i<3;i++)
 {
  t=fork();
  
  if(t>0) break;
  
  printf("PID is %d and PPID is %d and Level is %d\n",getpid(),getppid(),i);
  
 }
 
 wait(NULL);
 
 return 0;
}  
