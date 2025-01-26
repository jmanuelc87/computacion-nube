#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <omp.h>

#include <random>

#define N 1000000000

/**
 * Prints the first N items of the array
 */
void print(_Float16 *arr, int length)
{
    printf("[");
    for (int i = 0; i < length; i++)
    {
        printf("%.02f", arr[i]);
        if (i != length - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

int main()
{
    _Float16 *a = new _Float16[N];
    _Float16 *b = new _Float16[N];
    float *c = new float[N];
    int i;

    std::mt19937 gen;
    std::uniform_real_distribution<float> prob(-13, 101);

#pragma omp parallel for shared(a, b) schedule(static)
    for (size_t i = 0; i < N; i++)
    {
        a[i] = prob(gen);
        b[i] = prob(gen);
    }

    double start = omp_get_wtime();

#pragma omp parallel for shared(a, b, c) schedule(static)
    for (i = 0; i < N; i++)
    {
        c[i] = a[i] + b[i];
    }

    double end = omp_get_wtime();

    print(a, 10);
    print(b, 10);
    print(c, 10);

    printf("Processing array size %d and the total runtime is %f\n", N, end - start);

    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}
