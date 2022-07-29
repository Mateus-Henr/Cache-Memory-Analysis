#include "selectionsort.h"


/*
 *  Swaps two elements in an array.
 *
 *  @param     a     pointer to element to swap.
 *  @param     b     pointer to element to swapQuickSort.
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


/*
 *  Sorts an array using the Selection Sort algorithm.
 *
 *  @param     array       pointer to the array to be sorted.
 *  @param     size        array's size.
 */
void selectionSort(int array[], int size)
{
    for (int step = 0; step < size - 1; step++)
    {
        int min_idx = step;

        for (int i = step + 1; i < size; i++)
        {
            // Select the minimum element in each loop.
            if (array[i] < array[min_idx])
            {
                min_idx = i;
            }
        }

        // Put min at the correct position.
        swap(&array[min_idx], &array[step]);
    }
}
