#include "sort.h"

void bubble_sort(int *array, size_t size)
{
    unsigned long i, j;

    print_array(array, size);

    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                print_array(array, size);
            }
        }
    }
}