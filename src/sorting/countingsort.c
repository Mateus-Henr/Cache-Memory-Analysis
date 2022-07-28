#include "countingsort.h"


/*
 *  Sorts an array using the Couting Sort algorithm.
 *
 *  @param     arr       pointer to the array to be sorted.
 *  @param     size      array's size.
 */
void countingSort(int array[], int size)
{
    int output[10];

    // Find the largest element of the array.
    int max = array[0];

    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    // The size of count must be at least (max+1).
    int count[10];

    // Initialize count array with all zeros.
    for (int i = 0; i <= max; ++i)
    {
        count[i] = 0;
    }

    // Store the count of each element
    for (int i = 0; i < size; i++)
    {
        count[array[i]]++;
    }

    // Store the cummulative count of each array.
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    // Find the index of each element of the original array in count array, and
    // place the elements in output array.
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    // Copy the sorted elements into original array.
    for (int i = 0; i < size; i++)
    {
        array[i] = output[i];
    }
}