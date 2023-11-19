#include "sort.h"
/**
 * selection_sort - sorts an arrat using selection sort
 * algorithm
 * @array: array to sort
 * @size: size of array
 * return: is void
 *
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j, asc;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		asc = i;
		for (j = i + 1; j < size; j++)
			if (array[asc] > array[j])
				asc = j;
		if (asc != i)
		{
			temp = array[i];
			array[i] = array[asc];
			array[asc] = temp;
			print_array(array, size);
		}
	}
}
