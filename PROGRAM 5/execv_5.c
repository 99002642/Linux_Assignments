/*  Write a program to compile & link any c/c++ program within child process by launching 
gcc using execl/execlp. */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main() 
{
    pid_t ret,return1;
    char s[] = {"rw1.out"};
	printf("welcome...pid=%d\n",getpid());

	// creating child process
    ret=fork();
	if(ret< 0)
	{
		perror("fork");
		exit(1);
	}
    printf("ret = %d", ret);
    // compiling
    if (ret==0)
    {
        execl("/usr/bin/gcc","gcc","-c","rw.c",NULL);
        printf("Hello World..");
    }   
    
    //waitpid(ret,&return1,0);
    execl("/usr/bin/gcc","gcc","rw.o","-o", s,NULL);
    printf("Hello World12..");
    

    exit(0);
}