#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include "sorting/bubblesort.h"
#include "sorting/radixsort.h"
#include "sorting/quicksort.h"
#include "sorting/selectionsort.h"
#include "factorial/factorial.h"
#include "factorial/memoizationfactorials.h"

#define ARRAY_SIZE 1000
#define QUANTITY_NUMBERS 1000
#define MAX_FACTORIAL 20

/*
 *  References
 *
 *  OBS: Some references have been modified for the purposes of the project, or to follow a standard design.
 *
 *  • Bubble Sort - https://www.geeksforgeeks.org/bubble-sort
 *  • Radix Sort - https://www.programiz.com/dsa/radix-sort
 *  • Quick Sort - https://www.programiz.com/dsa/quick-sort
 *  • Selection Sort - https://www.programiz.com/dsa/selection-sort
 *  • Factorial - https://www.programiz.com/c-programming/examples/factorial-recursion
 *  • Memoized Factorial - https://www.codedrome.com/memoization-of-factorials-in-c
 */


// Function prototypes

void printArray(int arr[], int size);

void fillArrayWithRandomNumbers(int array[], int size);


/*
 *  Code's entry point.
 *
 *  @return             whether the operation was successful or not.
 */
int main()
{
    /// ------------------------------------------- SORTING ALGORITHMS PART --------------------------------------------

    printf("Algorithms being used:"
           "\n- Bubble Sort"
           "\n- Radix Sort"
           "\n- Quick Sort"
           "\n- Counting Sort\n");

    int array[ARRAY_SIZE];

    printf("\nPerforming Bubble Sort algorithm\n");
    bubbleSort(array, ARRAY_SIZE);
    printArray(array, ARRAY_SIZE);
    fillArrayWithRandomNumbers(array, ARRAY_SIZE);
    printf("\n");

    printf("\nPerforming Radix Sort algorithm\n");
    radixSort(array, ARRAY_SIZE);
    printArray(array, ARRAY_SIZE);
    fillArrayWithRandomNumbers(array, ARRAY_SIZE);
    printf("\n");

    printf("\nPerforming Quick Sort algorithm\n");
    quickSort(array, 0, ARRAY_SIZE);
    printArray(array, ARRAY_SIZE);
    fillArrayWithRandomNumbers(array, ARRAY_SIZE);
    printf("\n");

    printf("\nPerforming Selection Sort algorithm\n");
    selectionSort(array, ARRAY_SIZE);
    printArray(array, ARRAY_SIZE);
    printf("\n");

    /// ----------------------------------------- END SORTING ALGORITHMS PART ------------------------------------------



    /// ------------------------------------------------ FACTORIAL PART ------------------------------------------------

    printf("\n\nFACTORIAL\n\n");

    srand(time(NULL));

    int numberArray[QUANTITY_NUMBERS];

    for (int i = 0; i < QUANTITY_NUMBERS; i++)
    {
        numberArray[i] = rand() % MAX_FACTORIAL + 1;
    }


    printf("Standard Recursive Factorial Algorithm\n");

    // Standard recursive factorial algorithm.
    for (int i = 0; i < QUANTITY_NUMBERS; i++)
    {
        printf("%llu ", factorial(numberArray[i]));
    }


    // Allocate and get: calculate and store values as requested.
    Factorials factorials;

    if (!allocateFactorials(&factorials, MAX_FACTORIAL))
    {
        return -1;
    }

    printf("\n\nMemorized Factorial Algorithm\n");

    for (int i = 0; i < QUANTITY_NUMBERS; i++)
    {
        printf("%llu ", getFactorials(&factorials, numberArray[i]));
    }

    freeFactorials(&factorials);

    /// ---------------------------------------------- END FACTORIAL PART ----------------------------------------------


    return 0;
}


/*
 *  Fills array with random numbers.
 *
 *  @param     array     pointer to the array to be sorted.
 *  @param     size      array's size.
 */
void fillArrayWithRandomNumbers(int array[], int size)
{
    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        array[i] = rand();
    }
}


/*
 *  Prints out array.
 *
 *  @param     array     pointer to the array to be sorted.
 *  @param     size      array's size.
 */
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("[%d] ", array[i]);
    }

    printf("\n");
}