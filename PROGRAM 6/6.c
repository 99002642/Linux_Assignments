#include <stdio.h>
#include <pthread.h> 
#include <stdlib.h> 

#define Max_Ele 1000
#define Arr_limit 10 

int arr[Max_Ele]={};
int sum[Arr_limit] = { 0 }; 
  
void* parallel(void* arg) 
{ 
    int j = b++; 
  
    for (int ind =t* 100; ind < (t + 1) * 100; ind++) 
        {
		sum[t] += arr[ind]; 
		
	   }
} 
  
int main() 
{ 	
    int total_sum = 0; 
    pthread_t thread_1[Arr_limit]; 
  
	for(int ind=1;ind<=1000;ind++)
   		{
   			arr[ind]=1;
   		}

    // Creating 10 threads 
    for (int ind = 0; ind < Arr_limit; ind++) 
        pthread_create(&thread_1[ind],NULL, parallel,(void*)			NULL); 
  
    // joining 10 threads i.e. waiting for all 10 threads to complete 
    for (int ind = 0; ind < Arr_limit; ind++) 
        pthread_join(thread_1[ind], NULL); 
  
    // adding sum of all 10 sub threads parts
    
    for (int ind = 0; ind < Arr_limit; ind++) 
        total_sum+= sum[ind]; 
  
    printf("parallel sum of the elements is %d\n",total_sum);
  
    return 0; 
} 