/*
 *  Group members:
 *  • Mateus Henrique Vieira Figueiredo - 4707 - mateus.h.figueiredo@ufv.br
 *  • Emily Lopes - 4682 - emily.almeida@ufv.br
 *  • Vitor Ribeiro Lacerda - 4675 - vitor.lacerda@ufv.br
 *  • João Victor Graciano Belfort Andrade - joao.andrade1@ufv.br
 *
 *  Reference:
 *  • Memoized Factorial - https://www.codedrome.com/memoization-of-factorials-in-c
 *
 *  OBS: Some references have been modified for the purposes of the project, or to follow a standard design.
 */

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>


typedef struct Factorials
{
    unsigned long long int *calculated;
} Factorials;


// Function prototypes

bool allocateFactorials(Factorials *factorials, int max);

unsigned long long int getFactorials(Factorials *factorials, int n);

void freeFactorials(Factorials *factorials);
