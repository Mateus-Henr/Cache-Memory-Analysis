#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>


// --------------------------------------------------------
// STRUCT Factorials
// --------------------------------------------------------
typedef struct Factorials
{
    long long int max;
    long long int *calculated;
} Factorials;


// --------------------------------------------------------
// FUNCTION PROTOTYPES
// --------------------------------------------------------

bool allocateFactorials(Factorials *factorials, long long int max);

long long int getFactorials(Factorials *factorials, long long int n);

void freeFactorials(Factorials *factorials);
