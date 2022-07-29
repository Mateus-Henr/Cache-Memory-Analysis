#include "quicksort.h"


/*
 *  Swaps two elements in an array.
 *
 *  @param     a     pointer to element to swap.
 *  @param     b     pointer to element to swapQuickSort.
 */
void swapQuickSort(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


/*
 *  Finds the partition position for the "quickSort" method.
 */
int partition(int array[], int low, int high)
{

    // Select the rightmost element as pivot.
    int pivot = array[high];

    // Pointer for greater element.
    int i = (low - 1);

    // Traverse each element of the array compare them with the pivot.
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {

            // If element smaller than pivot is found  swapQuickSort it with the greater element pointed by i.
            i++;

            // Swap element at i with element at j.
            swapQuickSort(&array[i], &array[j]);
        }
    }

    // Swap the pivot element with the greater element at i.
    swapQuickSort(&array[i + 1], &array[high]);

    // Returns the partition point.
    return (i + 1);
}


/*
 *  Sorts an array using the Quick Sort algorithm.
 *
 *  @param     array     pointer to the array to be sorted.
 *  @param     low       initial position in the array.
 *  @param     high      end position in the array.
 */
void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        // Find the pivot element such that elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot.
        int pi = partition(array, low, high);

        // Recursive call on the left of pivot.
        quickSort(array, low, pi - 1);

        // Recursive call on the right of pivot.
        quickSort(array, pi + 1, high);
    }
}