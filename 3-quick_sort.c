#include "sort.h"

/**
 * quick_sort - calls the sorting algorithm
 * @array: array to sort
 * @size: sizeof array
 * Return: is void
*/
void quick_sort(int *array, size_t size)
{
	quick_sort_alog(array, 0, size, size);

}

/**
 * quick_sort_alog -function that actually sorts recursively
 * @array: array to sort
 * @s: start of array
 * @end: end of array
 * @size: sizeof array
 * Return: is void
*/
void quick_sort_alog(int *array, int s, int end, size_t size)
{
	int pivot;

	if (end <= s)
	{
		print_array(array, size);
		return;
	}
	pivot = partition(array, s, end);
	quick_sort_alog(array, s, pivot - 1, size);
	quick_sort_alog(array, pivot + 1, end, size);
}

/**
 * partition - uses divide and conquer technique to sort
 * @array: array to sort
 * @s: starting of array
 * @end: end of array
 * Return: sorted partition
 *
*/
int partition(int *array, int s, int end)
{
	int pivot = array[end];
	int temp, j, i = s - 1;

	for (j = s; j <= end; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	i++;
	temp = array[i];
	array[i] = array[end];
	array[end] = temp;
	return (i);
}
