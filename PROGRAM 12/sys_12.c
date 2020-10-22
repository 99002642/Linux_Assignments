/*  Write a program to print various resource limits using getrlimit system call (like ulimit command)  */

#include <stdio.h> 
#include <sys/resource.h> 
#include <string.h> 
#include <errno.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
  
int main() 
{ 
  
    struct rlimit resrc; 
  

    if( getrlimit(RLIMIT_NOFILE, &resrc) == 0) 
        printf("various resource limits using getrlimit system call are -> soft limit= %ld  hard limit= %ld \n", resrc.rlim_cur, resrc.rlim_max); 
    else
        printf("Error"); 

    return 0; 

} 
