#include "bubblesort.h"


/*
 *  Sorts an array using the Bubble Sort algorithm.
 *
 *  @param     arr       pointer to the array to be sorted.
 *  @param     size      array's size.
 */
void bubbleSort(int array[], int size)
{
    // Loop to access each array element.
    for (int step = 0; step < size - 1; ++step)
    {
        // Loop to compare array elements.
        for (int i = 0; i < size - step - 1; ++i)
        {
            // Compare two adjacent elements.
            if (array[i] > array[i + 1])
            {
                // Swap element if order is not intended.
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
    }
}