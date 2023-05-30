#include<stdio.h>
#include<omp.h>
#define N 100000

int main(void)
{

    int i, n;
    float a[N], b[N], c[N];
    double inicio, fim;

    inicio = omp_get_wtime();
    
    for(i = 0; i<N; i++)
    {
        a[i] = b[i] = i * 1.0;
        n = N;
    }

    #pragma omp parallel num_threads(8)
    {
        int id = omp_get_thread_num();

        if (id == 0)
        {
            int num_procs = omp_get_num_procs();
            int max_threads = omp_get_num_procs();
            printf("processadores disponiveis : %d\n", num_procs);
            printf("maximo de threads : %d\n", max_threads);
        }

        #pragma omp for
        for(i=0; i<n; i++){
            c[i] = a[i] + b[i];
        } 

        fim = omp_get_wtime();
    }

        printf("tempo(s): %3.4f\n", fim - inicio);
        printf("tempo(s): %3.9f\n", omp_get_wtick());

    return 0;
}
