#include "rdtsc.h"
#include "queens.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    unsigned long long elapse = 0;
    printf("# X Y\n");
for(int i = 0 ; i < 10 ; i ++)
    {
        unsigned long long before = rdtsc();
        find_solution(3,calloc(3,sizeof(int)));
        unsigned long long after = rdtsc();
        elapse += after-before; 

    }       
        printf("3 %lld\n",elapse/10);  
        elapse = 0;  
for(int i = 0 ; i < 10 ; i ++)
    {
        unsigned long long before = rdtsc();
        find_solution(4,calloc(4,sizeof(int)));
        unsigned long long after = rdtsc();
        elapse += after-before; 

    }       
        printf("4 %lld\n",elapse/10);   
        elapse = 0;     
    for(int i = 0 ; i < 10 ; i ++)
    {
        unsigned long long before = rdtsc();
        find_solution(5,calloc(5,sizeof(int)));
        unsigned long long after = rdtsc();
        elapse += after-before; 

    }       
        printf("5 %lld\n",elapse/10);

    for(int i = 0 ; i < 10 ; i ++)
    {
        unsigned long long before = rdtsc();
        find_solution(10,calloc(10,sizeof(int)));
        unsigned long long after = rdtsc();
        elapse += after-before; 


    } 
        printf("10 %lld\n",elapse/10);
        elapse = 0;

    for(int i = 0 ; i < 10 ; i ++)
    {
        unsigned long long before = rdtsc();
        find_solution(15,calloc(15,sizeof(int)));
        unsigned long long after = rdtsc();
        elapse += after-before; 


    }  
        printf("15 %lld\n",elapse/10);

    elapse = 0;
    for(int i = 0 ; i < 10 ; i ++)
    {
        unsigned long long before = rdtsc();
        find_solution(20,calloc(20,sizeof(int)));
        unsigned long long after = rdtsc();
        elapse += after-before; 

    }
         printf("20 %lld\n",elapse/10);
   
    elapse = 0;
    for(int i = 0 ; i < 10 ; i ++)
    {
        unsigned long long before = rdtsc();
        find_solution(22,calloc(22,sizeof(int)));
        unsigned long long after = rdtsc();
        elapse += after-before; 

    }
         printf("22 %lld\n",elapse/10);

    elapse = 0;
    for(int i = 0 ; i < 10 ; i ++)
    {
        unsigned long long before = rdtsc();
        find_solution(25,calloc(25,sizeof(int)));
        unsigned long long after = rdtsc();
        elapse += after-before; 

    }
         printf("25 %lld\n",elapse/10);


}