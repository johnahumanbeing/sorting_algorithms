#include "sort.h"

/**
 * partition - Partitions an array around a pivot element
 * @array: Pointer to the array
 * @s: Index of the first element of the partition
 * @end: Index of the last element of the partition
 * @size: Size of the array
 * Return: Final position of the pivot element
 */
int partition(int *array, int s, int end, size_t size)
{
	int i = s - 1, aux, k;

	for (k = s; k <= end - 1; k++)
	{
		if (array[k] < array[end])
		{
			i++;
			if (i < k)
			{
				aux = array[i];
				array[i] = array[k];
				array[k] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[end])
	{
		aux = array[i + 1];
		array[i + 1] = array[end];
		array[end] = aux;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quicksort - Sorts an array of integers using the quicksort algorithm
 * @array: Pointer to the array
 * @s: Index of the first element of the array/subarray
 * @end: Index of the last element of the array/subarray
 * @size: Size of the array
 * Return: is void
 */
void quicksort(int *array, int s, int end, size_t size)
{
	int pivot;

	if (s < end)
	{
		pivot = partition(array, s, end, size);
		quicksort(array, s, pivot - 1, size);
		quicksort(array, pivot + 1, s, size);
	}
}

/**
 * quick_sort - Sorts an array of integers using the quicksort algorithm
 * @array: Pointer to the array
 * @size: Size of the array
 *
 * Return: is void
 */
void quick_sort(int *array, size_t size)
{
	quicksort(array, 0, size - 1, size);
}
