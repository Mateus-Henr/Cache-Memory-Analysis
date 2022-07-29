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
    int max;
    int *calculated;
} factorials;


// --------------------------------------------------------
// FUNCTION PROTOTYPES
// --------------------------------------------------------
bool factorials_calculate(factorials *facs, int max);

bool factorials_allocate(factorials *facs, int max);

void factorials_output(factorials *facs);

int factorials_get(factorials *facs, int n);

void factorials_free(factorials *facs);
