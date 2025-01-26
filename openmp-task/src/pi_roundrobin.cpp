#include <stdio.h>
#include <omp.h>

static long num_steps = 10000000;

#define NUM_THREADS 16

int main()
{
    int i, nthreads;
    double pi, sum[NUM_THREADS], step = 1.0 / (double)num_steps;

    omp_set_num_threads(NUM_THREADS);

#pragma omp parallel
    {
        int tid = omp_get_thread_num();
        int nthrds = omp_get_num_threads();
        double x;

        if (tid == 0)
            nthreads = nthrds;

        for (i = tid, sum[tid] = 0.0; i < num_steps; i = i + nthrds)
        {
            x = (i + 0.5) * step;
            sum[tid] += 4.0 / (1.0 + x * x);
        }
    }

    for (i = 0; i < nthreads; i++)
    {
        pi += sum[i] * step;
    }

    printf("The value of pi %f\n", pi);
    return 0;
}
