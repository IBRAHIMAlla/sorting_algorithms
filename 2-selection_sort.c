#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order,
 * using the Selection sort algorithm
 * @size: size of the array
 * @array: list with numbers
 */
void selection_sort(int *array, size_t size)
{
	size_t m, nd;
	int mpt, s, fl = 0;

	if (array == NULL)
		return;
	for (m = 0; m < size; m++)
	{
		mpt = m;
		fl = 0;
		for (nd = m + 1; nd < size; nd++)
		{
			if (array[mpt] > array[nd])
			{
				mpt = nd;
				fl += 1;
			}
		}
		s = array[m];
		array[m] = array[mpt];
		array[mpt] = s;
		if (fl != 0)
			print_array(array, size);
	}
}
