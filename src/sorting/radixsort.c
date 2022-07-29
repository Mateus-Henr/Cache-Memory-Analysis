#include "radixsort.h"


/*
 *  Gets the largest element in an array.
 *
 *  @param     array     pointer to the array to be sorted.
 *  @param     size      array's size.
 */
int getMax(const int array[], int size)
{
    int max = array[0];

    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }

    return max;
}


/*
 *  Sorts an array using the Counting Sort algorithm, notice that this method is used by the "radixSort" method.
 *
 *  @param     array       pointer to the array to be sorted.
 *  @param     size        array's size.
 *  @param     place       place where the array is being modified.
 */
void countingSortRadix(int array[], int size, int place)
{
    int output[size + 1];
    int max = (array[0] / place) % 10;

    for (int i = 1; i < size; i++)
    {
        if (((array[i] / place) % 10) > max)
        {
            max = array[i];
        }
    }

    int count[max + 1];

    for (int i = 0; i < max; ++i)
    {
        count[i] = 0;
    }

    // Calculate count of elements.
    for (int i = 0; i < size; i++)
    {
        count[(array[i] / place) % 10]++;
    }

    // Calculate cumulative count.
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Place the elements in sorted order.
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++)
    {
        array[i] = output[i];
    }
}


/*
 *  Sorts an array using the Radix Sort algorithm, and by internal sorting it uses a Counting Sort algorithm.
 *
 *  @param     array     pointer to the array to be sorted.
 *  @param     size      array's size.
 */
void radixSort(int array[], int size)
{
    // Get maximum element.
    int max = getMax(array, size);

    // Apply counting sort to sort elements based on place value.
    for (int place = 1; max / place > 0; place *= 10)
    {
        countingSortRadix(array, size, place);
    }
}