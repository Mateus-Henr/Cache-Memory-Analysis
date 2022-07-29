#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

#include"memoizationfactorials.h"


// --------------------------------------------------------
// FUNCTION factorials_calculate
// --------------------------------------------------------
bool factorials_calculate(factorials *facs, long long max)
{
    facs->calculated = malloc(max * sizeof(long long));

    if (facs->calculated != NULL)
    {
        facs->max = max;

        long long prev = 1;

        facs->calculated[0] = 1;

        for (long long i = 1; i <= max; i++)
        {
            facs->calculated[i] = i * prev;
            prev = facs->calculated[i];
        }

        return true;
    }

    return false;
}


// --------------------------------------------------------
// FUNCTION factorials_output
// --------------------------------------------------------
void factorials_output(factorials *facs)
{
    puts("  n          n!\n---------------");

    for (long long i = 0; i <= facs->max; i++)
    {
        printf("%3lld%22lld\n", i, facs->calculated[i]);
    }
}


// --------------------------------------------------------
// FUNCTION factorials_allocate
// --------------------------------------------------------
bool factorials_allocate(factorials *facs, long long max)
{
    facs->calculated = calloc(max, sizeof(long long));

    if (facs->calculated != NULL)
    {
        facs->max = max;

        return true;
    }

    return false;
}


// --------------------------------------------------------
// FUNCTION factorials_get
// --------------------------------------------------------
long long factorials_get(factorials *facs, long long n)
{
    long long fac = facs->calculated[n];

    if (fac == 0)
    {
        if (n > 0)
        {
            fac = n;

            for (long long i = n - 1; i > 1; i--)
            {
                fac *= i;
            }
        }
        else
        {
            fac = 1;
        }

        facs->calculated[n] = fac;
    }

    return fac;
}


// --------------------------------------------------------
// FUNCTION factorials_free
// --------------------------------------------------------
void factorials_free(factorials *facs)
{
    free(facs->calculated);
}
