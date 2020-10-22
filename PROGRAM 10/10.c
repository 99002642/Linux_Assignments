/*  Write a program to send specific signal to a target process (with given id, like kill command)  */

#include<unistd.h>
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include<signal.h> 

int main(int argc ,char *argv[])
{
	int pid =atoi( argv[2] );   // string argument str to an integer process id
	
    switch(*argv[1])
	{
	case 'K':printf("Killing the process\n");
		 kill(pid, 9);
		 break;
	case 'I':printf("Interupting the process");
		 Int(pid, 2);
		 break;
	case 'Q':printf("Quiting the process");
		 Quit(pid, 3);
		 break;
    case 'A':printf("Aborting the process");
		 Abrt(pid, 6);
		 break;
	default: printf("Do nothing");
        break;
	}
    return 0;
}