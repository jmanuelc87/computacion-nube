#include <stdio.h>
#include <omp.h>

int main()
{
#pragma omp parallel
    {
        int tid = omp_get_thread_num();
        printf("thread #%d\n", tid);

        if (tid == 0)
        {
            int threads = omp_get_num_threads();
            printf("total threads %d\n", threads);
        }
    }

    return 0;
}
