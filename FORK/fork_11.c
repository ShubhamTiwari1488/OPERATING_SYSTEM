#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
 int p = fork();

 if(p>0)
 {
  printf("\n=======================================================================\n");
  printf("\nI am Parent Process\n");
  printf("\nThe value returned by fork is %d\n",p);
  printf("\nPID is %d and PPID is %d\n",getpid(),getppid());
  printf("\n========================================================================\n");
 }
 
 else
 {
  printf("\n=========================================================================\n");
  printf("\nI am Child Process\n");
  printf("\nThe value returned by fork is %d\n",p);
  printf("\nPID is %d and PPID is %d\n",getpid(),getppid());
  printf("\n==========================================================================\n");
 } 
 
 int q = wait(NULL);
 
 printf("\nValue of q returned by wait is = %d\n",q);
 
 return 0;
} 
