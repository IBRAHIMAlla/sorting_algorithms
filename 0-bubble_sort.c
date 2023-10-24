#include "sort.h"
/**
 * bubble_sort - sort array lements from min to max value
 * @array: array
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{

	size_t m, nd, pmt = 0;

	if (size < 2)
		return;
	for (m = 0; m < size; m++)
		for (nd = 0; nd < size; nd++)
		{
			if (array[nd] > array[nd + 1] && array[nd + 1])
			{
			pmt = array[nd];
			array[nd] = array[nd + 1];
			array[nd + 1] = pmt;
			print_array(array, size);
			}
		}
}
