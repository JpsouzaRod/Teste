#include<stdio.h>
#include<omp.h>
#define N 20

int main(void)
{

    int i, n;

    printf("static SEM o parametro tam : %d\n");

    #pragma omp parallel for schedule (static) num_threads(4)    
    for(i = 0; i<N; i++)
    {
        printf("ID = %d iteracao = %d\n", omp_get_thread_num(), i);
    }
    
    printf("static SEM o parametro tam : %d\n");
    #pragma omp parallel for schedule (static,3) num_threads(4)    
    for(i = 0; i<N; i++)
    {
        printf("ID = %d iteracao = %d\n", omp_get_thread_num(), i);
    }

    return 0;
}
