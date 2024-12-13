#include "sort.h"
#include <stdio.h>

/**
 * lomuto_partition - Lomuto partition scheme for quick sort
 * @array: The array to be sorted
 * @low: The starting index of the array or subarray
 * @high: The ending index of the array or subarray
 * @size: The size of the array (used for printing)
 * Return: The final index where the pivot is placed
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
int pivot = array[high];
int i = low - 1;
int j;
int temp;

for (j = low; j < high; j++)
{
if (array[j] <= pivot)
{
i++;
temp = array[i];
array[i] = array[j];
array[j] = temp;

print_array(array, size);
}
}


temp = array[i + 1];
array[i + 1] = array[high];
array[high] = temp;
print_array(array, size);
return (i + 1);
}

/**
 * quick_sort_recursive - Helper function to recursively sort subarrays
 * @array: The array to be sorted
 * @low: The starting index of the subarray
 * @high: The ending index of the subarray
 * @size: The size of the array (used for printing)
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
if (low < high)
{
int pivot_idx = lomuto_partition(array, low, high, size);
quick_sort_recursive(array, low, pivot_idx - 1, size);
quick_sort_recursive(array, pivot_idx + 1, high, size);
}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

quick_sort_recursive(array, 0, size - 1, size);
}
