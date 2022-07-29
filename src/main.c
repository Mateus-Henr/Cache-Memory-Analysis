#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include "sorting/bubblesort.h"
#include "sorting/radixsort.h"
#include "sorting/quicksort.h"
#include "factorial/factorial.h"

#define ARRAYSIZE 100

/*
 *  References
 *
 *  OBS: Some references have been modified for the purposes of the project, or to follow a standard design.
 *
 *  • Bubble Sort - https://www.geeksforgeeks.org/bubble-sort/
 *  • Radix Sort - https://www.programiz.com/dsa/radix-sort
 *  • Quick Sort - https://www.programiz.com/dsa/quick-sort
 *  • Selection Sort - https://www.programiz.com/dsa/selection-sort
 *  • Factorial - https://www.programiz.com/c-programming/examples/factorial-recursion
 */


// Function prototype
void printArray(int arr[], int size);

void fillArrayWithRandomNumbers(int array[], int size);


/*
 *  Code's entry point.
 *
 *  @return             whether the operation was successful or not.
 */
int main()
{
    printf("Algorithms being used:"
           "\n- Bubble Sort"
           "\n- Radix Sort"
           "\n- Quick Sort"
           "\n- Counting Sort\n");

    int array[ARRAYSIZE];

    printf("\nPerforming Bubble Sort algorithm\n");
    bubbleSort(array, ARRAYSIZE);
    printArray(array, ARRAYSIZE);
    fillArrayWithRandomNumbers(array, ARRAYSIZE);
    printf("\n");

    printf("\nPerforming Radix Sort algorithm\n");
    radixsort(array, ARRAYSIZE);
    printArray(array, ARRAYSIZE);
    fillArrayWithRandomNumbers(array, ARRAYSIZE);
    printf("\n");

    printf("\nPerforming Quick Sort algorithm\n");
    quickSort(array, 0, ARRAYSIZE);
    printArray(array, ARRAYSIZE);
    fillArrayWithRandomNumbers(array, ARRAYSIZE);
    printf("\n");

    printf("\nPerforming Factorial algorithm\n");
    factorial(array, ARRAYSIZE);
    printArray(array, ARRAYSIZE);
    fillArrayWithRandomNumbers(array, ARRAYSIZE);
    printf("\n");

    return 0;
}


/*
 *  Fills array with random numbers.
 *
 *  @param     arr      pointer to the array to be sorted.
 *  @param     size     array's size.
 */
void fillArrayWithRandomNumbers(int array[], int size)
{
    srand(time(NULL));

    for (int i = 0; i < ARRAYSIZE; i++)
    {
        array[i] = rand();
    }
}


/*
 *  Prints out array.
 *
 *  @param     arr      pointer to the array to be sorted.
 *  @param     size     array's size.
 */
void printArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("[%d] ", array[i]);
    }

    printf("\n");
}