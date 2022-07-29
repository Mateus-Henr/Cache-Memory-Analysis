#include "radixsort.h"


/*
 *  Gets the largest element in an array.
 *
 *  @param     arr       pointer to the array to be sorted.
 *  @param     size      array's size.
 */
int getMax(const int arr[], int size)
{
    int max = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
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
void countingSortRadix(int arr[], int size, int place)
{
    int output[size + 1];
    int max = (arr[0] / place) % 10;

    for (int i = 1; i < size; i++)
    {
        if (((arr[i] / place) % 10) > max)
        {
            max = arr[i];
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
        count[(arr[i] / place) % 10]++;
    }

    // Calculate cumulative count.
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Place the elements in sorted order.
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }

    for (int i = 0; i < size; i++)
    {
        arr[i] = output[i];
    }
}


/*
 *  Sorts an array using the Radix Sort algorithm, and by internal sorting it uses a Counting Sort algorithm.
 *
 *  @param     arr       pointer to the array to be sorted.
 *  @param     size      array's size.
 */
void radixsort(int arr[], int size)
{
    // Get maximum element.
    int max = getMax(arr, size);

    // Apply counting sort to sort elements based on place value.
    for (int place = 1; max / place > 0; place *= 10)
    {
        countingSortRadix(arr, size, place);
    }
}