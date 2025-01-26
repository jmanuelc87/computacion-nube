#include <stdio.h>
#include <random>
#include <omp.h>

#include "random.h"

static long num_trials = 1000000000;

int main()
{
   long i;
   long Ncirc = 0;
   double pi, x, y, test;
   double r = 1.0; // radius of circle. Side of squrare is 2*r

   std::mt19937 gen;
   std::uniform_real_distribution<float> prob(-r, r);

#pragma omp parallel for private(x, y, test) reduction(+ : Ncirc)
   for (i = 0; i < num_trials; i++)
   {
      x = prob(gen);
      y = prob(gen);

      test = x * x + y * y;

      if (test <= r * r)
         Ncirc++;
   }

   pi = 4.0 * ((double)Ncirc / (double)num_trials);

   printf("\n %ld trials, pi is %lf \n", num_trials, pi);

   return 0;
}
