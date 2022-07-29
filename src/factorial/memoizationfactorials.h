#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>


// --------------------------------------------------------
// STRUCT Factorials
// --------------------------------------------------------
typedef struct Factorials
{
    long max;
    unsigned long long int *calculated;
} Factorials;


// --------------------------------------------------------
// FUNCTION PROTOTYPES
// --------------------------------------------------------

bool allocateFactorials(Factorials *factorials, long max);

unsigned long long int getFactorials(Factorials *factorials, unsigned long long int n);

void freeFactorials(Factorials *factorials);
