
#include "types.h"
#include "user.h"
#include "stat.h"

int main()
{
 
 printf(1,"Current pid is : %d \n",getpid());
 printf(1,"Parent pid is : %d \n",getppid());
 
 /*__printf(1,"Parent pid is : %d\n",getpid());
 printf(1,"Parent ppid is : %d\n",getppid());
 
 int t=fork();
 
 if(t==0)
 {
  printf(1,"Child pid is : %d\n",getpid());
  printf(1,"Child ppid is : %d\n",getppid());
 }
 
 else
 {
  wait();
 }
 ___*/ 
    
 exit();
}
 
