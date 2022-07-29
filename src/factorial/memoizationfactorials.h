#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include<math.h>

// ------------------
// --------------------------------------------------------
// STRUCT factorials
// --------------------------------------------------------
typedef struct factorials
{
    long long max;
    long long *calculated;
} factorials;


// --------------------------------------------------------
// FUNCTION PROTOTYPES
// --------------------------------------------------------
bool factorials_calculate(factorials *facs, long long max);

bool factorials_allocate(factorials *facs, long long max);

void factorials_output(factorials *facs);

long long factorials_get(factorials *facs, long long n);

void factorials_free(factorials *facs);
