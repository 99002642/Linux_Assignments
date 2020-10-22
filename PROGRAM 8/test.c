
#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 

#define Max_limit 1000
#define num 10 

int arr[Max_limit] = {};
int min_arr[num] = {0}; 
int part=0;

void* minima(void* arg) 
{ 
    int ind;
    int t=part++; 
    int min=0; 
  
    for (ind = t * 100; ind < (t + 1) * 100; ind++) 
	{ 
        if (arr[ind] < min) 
            min= arr[ind]; 	
    	} 
    min_arr[t] = min; 
} 
  
int main() 
{
	int min_n = 0,ind;     
     for(ind=0;ind <Max_limit;ind++)
    		{
	    		arr[ind]=ind;
    		} 
    
    pthread_t thread_1[num]; 
  
    for (ind = 0; ind < num; ind++) 
        pthread_create(&thread_1[i], NULL, minima,(void*)NULL); 
  
    for (ind= 0; ind < num; ind++) 
        pthread_join(thread_1[ind], NULL); 

    for (ind = 0; ind < num; ind++) { 
        if (min_arr[ind] < min_n) 
            min_n = min_arr[ind]; 
    } 
  
    printf("element is:%d\n", min_n); 
  
    return 0; 
} 