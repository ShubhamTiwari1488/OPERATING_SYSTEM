#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
 int i;
 
 int t;
 
 for(i=0;i<4;i++)
 {
  t=fork();
  
  if(t==0)
    break;
    
 }
 
 printf("%d %d\n",getpid(),getppid());
 
 wait(NULL);
 
 return 0;
}
 
