#include <stdlib.h>
#include <stdbool.h>

#include "memoizationfactorials.h"


/*
 *  Allocates Factorials struct on memory.
 *
 *  @param     factorials     pointer to Factorials struct.
 *  @param     max            array's max size.
 *  @return                   whether the operation was successful or not.
 */
bool allocateFactorials(Factorials *factorials, int max)
{
    factorials->calculated = calloc(max, sizeof(unsigned long long int));

    return factorials->calculated;
}


/*
 *  Gets the factorial of a number if stored, otherwise it calculates the factorial of the number and stores it.
 *
 *  @param     factorials     pointer to Factorials struct.
 *  @param     max            array's max size.
 *  @return                   factorial of the number.
 */
unsigned long long int getFactorials(Factorials *factorials, int n)
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


/*
 *  Frees Factorial struct from memory.
 *
 *  @param     factorials     pointer to Factorials struct.
 */
void freeFactorials(Factorials *factorials)
{
    free(factorials->calculated);
}