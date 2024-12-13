#include "sort.h"
/**
 * bubble_sort - Sorts an array of integers in ascending order using Bubble sort
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int temp;
    int swapped;

    if (array == NULL || size < 2)
        return;

    /* Outer loop for multiple passes */
    for (i = 0; i < size - 1; i++)
    {
        swapped = 0;

        /* Inner loop to perform pairwise comparison */
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1]) /* Compare adjacent elements */
            {
                /* Swap the elements */
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;

                swapped = 1;

                /* Print the array after each swap */
                print_array(array, size);
            }
        }
if (swapped == 0)
break;
}
}
