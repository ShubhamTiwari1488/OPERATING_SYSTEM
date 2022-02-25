#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
 int i;
 int t;
 
 for(i=0;i<3;i++)
 {
  t=fork();
  
  if(t!=0)
   break;
      
 }
 
 int k=wait(NULL);
  
 printf("\nPID = %d and PPID = %d , and k = %d\n",getpid(),getppid(),k);
 
 return 0;
}
  
