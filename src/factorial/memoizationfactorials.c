#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

#include"memoizationfactorials.h"


// --------------------------------------------------------
// FUNCTION factorials_calculate
// --------------------------------------------------------
bool factorials_calculate(factorials *facs, int max)
{
    facs->calculated = malloc(max * sizeof(int));

    if (facs->calculated != NULL)
    {
        facs->max = max;

        int prev = 1;

        facs->calculated[0] = 1;

        for (int i = 1; i <= max; i++)
        {
            facs->calculated[i] = i * prev;

            prev = facs->calculated[i];
        }

        return true;
    }
    else
    {
        return false;
    }
}


// --------------------------------------------------------
// FUNCTION factorials_output
// --------------------------------------------------------
void factorials_output(factorials *facs)
{
    puts("  n          n!\n---------------");

    for (int i = 0; i <= facs->max; i++)
    {
        printf("%3d%12d\n", i, facs->calculated[i]);
    }
}


// --------------------------------------------------------
// FUNCTION factorials_allocate
// --------------------------------------------------------
bool factorials_allocate(factorials *facs, int max)
{
    facs->calculated = calloc(max, sizeof(int));

    if (facs->calculated != NULL)
    {
        facs->max = max;

        return true;
    }
    else
    {
        return false;
    }
}

// --------------------------------------------------------
// FUNCTION factorials_get
// --------------------------------------------------------
int factorials_get(factorials *facs, int n)
{
    int fac = facs->calculated[n];

    if (fac == 0)
    {
        if (n > 0)
        {
            fac = n;

            for (int i = n - 1; i > 1; i--)
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
