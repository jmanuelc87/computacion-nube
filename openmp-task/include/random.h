#ifndef __RANDOM_H__
#define __RANDOM_H__

#include <omp.h>

double drandom();
void seed(double low_in, double hi_in);

#endif // __RANDOM_H__