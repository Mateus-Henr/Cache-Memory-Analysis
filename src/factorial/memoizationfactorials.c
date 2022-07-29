#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "memoizationfactorials.h"


// --------------------------------------------------------
// FUNCTION allocateFactorials
// --------------------------------------------------------
bool allocateFactorials(Factorials *factorials, long long int max)
{
    factorials->calculated = calloc(max, sizeof(long long int));

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
long long int getFactorials(Factorials *factorials, long long int n)
{
    long long int fac = factorials->calculated[n];

    if (fac == 0)
    {
        if (n > 0)
        {
            fac = n;

            for (long long int i = n - 1; i > 1; i--)
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
