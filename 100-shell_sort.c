#include "sort.h"

/**
* shell_sort - sorts an array by using the shell sort method
*@array: the array to sort
*@size: size of the array
*Return: nothing to return
*/

void shell_sort(int *array, size_t size)
{
	/* interval is the distance between the compared elements*/
	size_t interval = 1, i, j;
	int temp;

	while (interval < size)
	{
		interval = (interval * 3) + 1;
	}
	while ((interval = (interval - 1) / 3) > 0)
	{
		for (i = 0; i + interval < size; i++)
		{
			for (j = i + interval; (int)(j - interval) >= 0; j = j - interval)
			{
				if (array[j] < array[j - interval])
				{
					temp = array[j];
					array[j] = array[j - interval];
					array[j - interval] = temp;
				}
			}
		}

		print_array(array, size);
	}
}
