#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "memoizationfactorials.h"


// --------------------------------------------------------
// FUNCTION allocateFactorials
// --------------------------------------------------------
bool allocateFactorials(Factorials *factorials, long max)
{
    factorials->calculated = calloc(max, sizeof(unsigned long long int));

    if (!factorials->calculated)
    {
        return false;
    }

    factorials->max = max;

    return true;
}


// --------------------------------------------------------
// FUNCTION getFactorials
// --------------------------------------------------------
unsigned long long int getFactorials(Factorials *factorials, unsigned long long int n)
{
    unsigned long long int fac = factorials->calculated[n];

    if (fac == 0)
    {
        if (n > 0)
        {
            fac = n;

            for (unsigned long long int i = n - 1; i > 1; i--)
            {
                fac *= i;
            }
        }
        else
        {
            fac = 1;
        }

        factorials->calculated[n] = fac;
    }

    return fac;
}


// --------------------------------------------------------
// FUNCTION freeFactorials
// --------------------------------------------------------
void freeFactorials(Factorials *factorials)
{
    free(factorials->calculated);
}
