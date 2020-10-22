/*  Write a program to copy one file contents to other using open,read,write,close system 
   calls (like cp command, which takes source, destination files as cmd line args). */

#include<unistd.h>
#include<fcntl.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int f__d1,n1bytes;
    int fd2,n2bytes;
	f__d1=open("rw.txt",O_RDONLY);
	if(f__d1<0)
	{
		perror("open");
		exit(1);
	}
	int maxlen=200;
	char buf[maxlen];

    //reading from the text file
	n1bytes=read(f__d1,buf,maxlen);
	if(n1bytes<0)
	{
		perror("read");
		exit(2);
	}
    buf[n1bytes]='\0';

    //writing to a different file 
    fd2=open("wr.txt",O_WRONLY|O_CREAT|O_TRUNC, 0666); //system call of fopen
	if(fd2<0)
	{
		perror("open");
		exit(1);
	}

	n2bytes=write(fd2, buf, n1bytes);//system call of fwrite
    if(n2bytes<0)
	{
		perror("write");
		exit(2);
	}

	printf("file written into another file success,n2bytes=%d\n",n2bytes);
	
    close(fd2);
    close(f__d1); //system call of fclose
	return 0;
}	
