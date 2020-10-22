/*Write a program to count no.of lines, words, characters in given file (like wc command)
*/
#include<unistd.h>
#include<fcntl.h>

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int fd1,n1bytes;
	int ind; // for indexing reference
    int word_count=0;
    int line_count=0;	
	int inword=0;

	fd1=open("rw.txt",O_RDONLY);
	if(fd1<0)
	{
		perror("open");
		exit(1);
	}
	int maxlen=200;
	char buf[maxlen];

    //Reading the file
	n1bytes=read(fd1,buf,maxlen);
	
	if(n1bytes<0)
	{
		perror("read");
		exit(2);
	}
	else
	{
	ind=0;
	while(ind!=n1bytes)
	{ 
	    if(buf[ind]==' '|| buf[ind]=='\t'|| buf[ind]=='\n' || buf[ind]=='\0')
	        {

	            if(inword)
	            {
	                inword=0;
	                word_count++;
	            }
	 
	            if(buf[ind]=='\n' || buf[ind]=='\0')
	            line_count++;
	        }
	    else
	        {
	            inword=1;
	        }
	    ind++;
	}
	}
    printf("word :%d line :%d char:%d",word_count,line_count,n1bytes);
	
	close(fd1);
	return 0;	
}
		
