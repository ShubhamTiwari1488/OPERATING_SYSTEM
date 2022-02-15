
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
 
 printf("\nThe PID of the parent is :\t%d\n",getpid());
 printf("\nThe PPID of the parent is :\t%d\n",getppid());
 
 int t=fork();
 
 if(t==0)
 {
  printf("\nThe PID of the child is :\t%d\n",getpid());
  printf("\nThe PPID of the child is :\t%d\n",getppid());
 }
 
 else
 {
  wait(&t);
 } 
 
 return 0;
}
  
