/*  Write a program to display file contents on console (like cat command)  */

#include<unistd.h>
#include<fcntl.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int fd1,n1bytes;
	fd1=open("rw.txt",O_RDONLY);
	if(fd1<0)
	{
		perror("open");
		exit(1);
	}
	int maxlen=200;
	char buf[maxlen];
	n1bytes=read(fd1,buf,maxlen);
	if(n1bytes<0)
	{
		perror("read");
		exit(2);
	}
    buf[n1bytes]='\0';

    write(1,buf,n1bytes);
    
    printf("Writing successful \n");
	close(fd1);
	return 0;
}