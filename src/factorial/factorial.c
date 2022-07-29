#include "factorial.h"


/*
 *  Gets the factorial of a number using recursion.
 *
 *  @param     n      number to get the factorial of.
 *  @return           factorial of the number.
 */
long int factorial(int n)
{
    return (n >= 1) ? n * factorial(n - 1) : 1;
}