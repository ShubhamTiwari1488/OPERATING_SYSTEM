#include "types.h"
#include "stat.h"
#include "user.h"


int main(int argc, char **argv)
{
	printf(1,"\nMy roll No. is: 20051488.\n");
	int i, a[2]={0};
    printf(1, "parent:%d %d\n", getpid(),getppid());
    	for(i=0;i<2;i++)
    	{
    	 	a[i]=fork();
    		if(a[i]==0)
    		{
    		    sleep(60);
    		    break;
    		}
    		else
    		{	
    		printf(1,"child:%d  %d\n",a[i],getpid());
    			wait();
    		}
    	}
    	
    	int c=waitpid(a[1]);
    	printf(1,"WAIT:%d %d\n",c,getpid());
 
 	exit();
} 

