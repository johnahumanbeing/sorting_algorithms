#include "sort.h"
/**
 * lomutopartition - gets the size of array
 * @array: array to check
 *@lomuto: the first index (highest)
 * @end: lowest in array (end index)
 * @size: the size of the array
 * Return: size of array
*/

size_t lomutopartition(int *array, size_t lomuto, size_t end, size_t size)
{
	int pivot = array[end], temp;
	size_t i = lomuto - 1, j;

	for (j = lomuto; j < end; j++)
	{
		if (array[j] < pivot)
		{
			i++;

			if (i != j)
			{
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;

				print_array(array, size);
			}
		}
	}

	i++;

	if (array[i] > pivot)
	{
		temp = array[i];
		array[i] = array[end];
		array[end] = temp;

		print_array(array, size);

	}

	return (i);
}

/**
 * quick_sort_alg - sorts using divide and conqoer
 * @array: array to check
 * @low: lower end
 * @high: higher end
 *@size: the size of the array
 * Return: is void
*/
void quick_sort_alg(int *array, int low, int high, size_t size)
{
	size_t pivot;

	if (low < high)
	return;

	pivot = lomutopartition(array, low, high, size);

	quick_sort_alg(array, low, pivot - 1, size);
	quick_sort_alg(array, pivot + 1, high, size);
}

/**
 * quick_sort - sort the array using uick sort algorithm
 * @array: array to sort
 * @size: size of array
 * Return: is void
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
			return;

	quick_sort_alg(array, 0, size - 1, size);
}
