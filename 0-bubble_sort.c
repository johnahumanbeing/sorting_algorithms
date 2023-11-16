#include "sort.h"

void bubble_sort(int *array, size_t size)
{
    int swapped;
    long unsigned int i, j;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) 
        {
            if (array[j] > array[j + 1]) 
<<<<<<< HEAD
                {
                    int temp = array[j];      
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                }
=======
            {
                swap(&array[j], &array[j + 1]);   
                swapped = 1;   
            }
        }
        print_array(array, size);

        if (swapped == 0)
        {
            break;
>>>>>>> 7f1fc718dcaf4968b39e8e3214cf48b2a6419c71
        }
    }
}
