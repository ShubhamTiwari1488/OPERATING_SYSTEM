#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc , char *argv[])
{
 int p1=fork();
 
 printf(1,"Hello People\n");
 
 int p2=fork();
 
 printf(1,"Good Bye \n");
 
 wait(p1);
 
 exit();
}
 
