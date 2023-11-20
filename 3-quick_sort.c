#include "sort.h"
/**
 * lomutopartition - gets the size of array
 * @array: array to check
 * @low: lowest in array
 * @high: highest in array
 * Return: size of array
*/

size_t lomutopartition(int *array, int low, int high)
{
	int pivot = array[low];
	int temp;
	size_t i = low;

	for (size_t j = low + 1; <= (size_t)high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];

			array[i] = array[j];
			array[j] = temp;
		}
	}

	temp = array[i];
	array[i] = array[low];
	array[j] = temp;

	return (i);
}

/**
 * quick_sort_alg - sorts using divide and conqoer
 * @array: array to check
 * @low: lower end
 * @high: higher end
 * Return: is void
*/
void quick_sort_alg(int *array, int low, int high)
{
	if (low < high)
	{
		int pivot = lomutopartition(array, low, high);

		quick_sort_alg(array, low, pivot - 1);
		quick_sort_alg(array, pivot + 1, high);
	}
}

/**
 * quick_sort - sort the array using
 * quick sort algorithm
 * @array: array to sort
 * @size: sizeof array
 * Return: is void
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_alg(array, 0, size - 1);
}
