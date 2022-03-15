#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
 int i,j,t1,t2=0,w;
 
 for(i=0;i<3;i++)
 {
  t1=fork();
  
  if(i==1)
  {
   if(t1==0)
   {
    for(j=0;j<2;j++)
    {
     t2=fork();
     
     if(t2==0)
       break;
    }
   }
  }
  
  else if(t1==0)
  {
   break;
  } 
 }
 
 while((w=wait(NULL))!=-1);
 
 printf("PID is %d and PPID is %d\n",getpid(),getppid());
 
 return 0;
}
     
