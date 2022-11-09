#include "rdtsc.h"
#include "queens.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    unsigned long long elapse = 0;
 
    unsigned long long elapse2 = 0;
    unsigned long long elapse1 = 0;
    unsigned long long elapse3 = 0;
    unsigned long long elapse4 = 0;
           

    for(int i = 0 ; i < 10 ; i ++)
    {
        unsigned long long before = rdtsc();
        find_solution(5,calloc(5,sizeof(int)));
        unsigned long long after = rdtsc();
        elapse2 += after - before;
        printf("5:\tEssai n*%d cycles : %lld\n",i+1,after-before);
         before = rdtsc();
        find_solution(10,calloc(10,sizeof(int)));
         after = rdtsc();
        elapse1 += after - before;
       printf("10:\tEssai n*%d cycles : %lld\n",i+1,after-before);

        before = rdtsc();
        find_solution(15,calloc(15,sizeof(int)));
         after = rdtsc();
        elapse3 += after - before;
       printf("15:\tEssai n*%d cycles : %lld\n",i+1,after-before);
        before = rdtsc();
        find_solution(15,calloc(15,sizeof(int)));
         after = rdtsc();
        elapse4 += after - before;
       printf("20:\tEssai n*%d cycles : %lld\n",i+1,after-before);   
        before = rdtsc();
        find_solution(15,calloc(15,sizeof(int)));
         after = rdtsc();
        elapse += after - before;
       printf("30:\tEssai n*%d cycles : %lld\n",i+1,after-before);            
    }       

    printf(" Moyenne sur 10 executions plateau de 30 = %lld\n",elapse/10);
    printf(" Moyenne sur 10 executions plateau de 20 = %lld\n",elapse4/10);
    printf(" Moyenne sur 10 executions plateau de 15 = %lld\n",elapse3/10);
    printf(" Moyenne sur 10 executions plateau de 10 = %lld\n",elapse1/10);
    printf(" Moyenne sur 10 executions plateau de 5 = %lld\n",elapse2/10);
}