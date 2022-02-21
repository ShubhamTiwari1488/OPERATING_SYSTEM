#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
 int a=2,p;
 
 fork();
 fork();
 fork();
 
 a++;
 
 int k=wait(&p);
 
 printf("\nValue = %d , Address = %p , PID = %d and PPID = %d\tand value of k is %d\n",a,&a,getpid(),getppid(),k);
 
 return 0;
}
 
