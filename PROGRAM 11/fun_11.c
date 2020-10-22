/*  Write a program to compute time taken for execution of a function/code snippet (Hint:- gettimeofday or clock_gettime)   */

#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main()
{
    double time__spent=0;
    clock_t time_1=clock();
    clock_t time_2=clock();
    int var1=5,var2=10;
    int var3;
    
    var3=var1*var2;
    printf("\n %d",var3);
    
    time__spent=(double)(time_2 - time_1)/CLOCKS_PER_SEC;
    printf("\n the time for execution for the function is: %f \n",time__spent);
    
    return 0;

}