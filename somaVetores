#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

#define TamVetor 20

int main(void)
{
    
    int a[TamVetor];
    int b[TamVetor];
    int c[TamVetor];

    for(int i = 0; i<TamVetor; i++)
    {
        a[i] = i;
        b[i] = i;
    }

    #pragma omp parallel num_threads(4)
    {
        int id = omp_get_thread_num();

        #pragma omp for    
        
        for (int i = 0; i<TamVetor; i++)
        {
            c[i] = a[i]+b[i];
            printf("thread %d executa a iteração %d do loop\n", omp_get_thread_num(),i);
        } 
        
    }
    
    return 0;
}
