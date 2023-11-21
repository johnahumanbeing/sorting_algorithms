#include "sort.h"

/**
 * quick_sort - calls the sorting algorithm
 * @array: array to sort
 * @size: sizeof array
 * Return: is void
*/
void quick_sort(int *array, size_t size)
{
	quick_sort_alog(array, 0, size);
}

/**
 * quick_sort_alog -function that actually sorts recursively
 * @array: array to sort
 * @size: sizeof array
 * Return: is void
*/
void quick_sort_alog(int *array, int s, int end)
{
	if (end <= s)
	{
		return;
	}
	int pivot = partition(array, s, end);
	quick_sort_alog(array, s, pivot - 1);
	quick_sort_alog(array, pivot + 1, end);
}

/**
 * partition - uses divide and conquer technique to sort
 * @array: array to sort
 * 
*/
int partition(int *array, int s, int end)
{
	int pivot = array[end];
	int i = s - 1;

	for (int j = s; j <= end; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	i++;
	int temp = array[i];
	array[i] = array[end];
	array[end] = temp;
	return (i);
}
