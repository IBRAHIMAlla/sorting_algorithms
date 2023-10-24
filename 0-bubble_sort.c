#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order,
 * using the Bubble sort algorithm
 * @array: the array
 * @size: size of the array
**/

void bubble_sort(int *array, size_t size)
{
	unsigned int m, n = size;
	int mpt;
	int w;

	do {
		w = 0;

		for (m = 1; m < n; m++)
		{
			if (array[m - 1] > array[m])
			{
				mpt = array[m - 1];
				array[m - 1] = array[m];
				array[m] = mpt;
				w = m;
				print_array(array, size);
			}
		}
		n = w;
	} while (n >= 1);
}
