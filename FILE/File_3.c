#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
 int fd=open("input1.txt",O_CREAT|O_WRONLY);	//Creating file in write only mode
 
 printf("%d\n",fd);	//Index of fd in the File Descriptor Table
 
 write(fd,"ABC",3);	//Writing in the file
 
 close(fd);	//Closing the file
 
 return 0;
}
 
