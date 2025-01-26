#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <omp.h>

#define N 1000000
#define C 1000

/**
 * Prints the first N items of the array
 */
void print(_Float16 *arr, int length)
{
    printf("[");
    for (int i = 0; i < length; i++)
    {
        printf("%f", arr[i]);
        if (i != length - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}

int main()
{
    _Float16 a[N], b[N], c[N];
    int i, chunk = C;

    for (size_t i = 0; i < N; i++)
    {
        a[i] = rand() % 13;
        b[i] = rand() % 101;
    }

    double start = omp_get_wtime();

#pragma omp parallel for shared(a, b, c) schedule(static, C)
    for (i = 0; i < N; i++)
    {
        c[i] = a[i] + b[i];
    }

    double end = omp_get_wtime();


    print(a, 10);
    print(b, 10);
    print(c, 10);

    printf("Processing array size %d and the total runtime is %f\n", N, end - start);

    return 0;
}
