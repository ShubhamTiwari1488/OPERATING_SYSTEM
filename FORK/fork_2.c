
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
 fork();
 fork();
 fork();
 
 printf("\nHello World\n");
 
 return 0;
}
 
