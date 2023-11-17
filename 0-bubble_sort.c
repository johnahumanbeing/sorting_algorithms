#include "sort.h"
/**
 * bubble_sort - sorts an array of data
 * in ascending order
 * @array: array to sort
 * @size: size of array
 * Return: is void
*/
void bubble_sort(int *array, size_t size)
{
	unsigned long i, j;
	int temp;

	print_array(array, size);

	if (array == NULL || size < 2)
	{
		return;
	}

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;

				print_array(array, size);
			}
		}
	}
}
