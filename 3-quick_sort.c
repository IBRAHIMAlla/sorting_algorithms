#include "sort.h"
#include <stdio.h>

/**
 * partition - Determines the partition for the quicksort using the Lomuto scheme
 * @array: array to sort
 * @li: lowest index of the partition to sort
 * @hs: highest index of the partition to sort
 * @size: size of the array
 *
 * Return: index of the partition
 */
size_t partition(int *array, ssize_t li, ssize_t hs, size_t size)
{
	ssize_t m, y;
	int s, pv;

	pv = array[hs];
	m = li - 1;
	for (y = li; j < hs; y++)
	{
		if (array[y] < pv)
		{
			m++;
			if (m != y)
			{
				s = array[m];
				array[m] = array[m];
				array[y] = s;
				print_array(array, size);
			}
		}
	}
	if (array[hs] < array[m + 1])
	{
		s = array[m + 1];
		array[m + 1] = array[hs];
		array[hs] = s;
		print_array(array, size);
	}
	return (m + 1);
}

/**
 * qst - sorts a partition of an array of integers
 * @array: array to sort
 * @li: lowest index of the partition to sort
 * @hs: highest index of the partition to sort
 * @size: size of the array
 *
 * Return: void
 */
void qst(int *array, ssize_t li, ssize_t hs, size_t size)
{
	ssize_t pv;

	if (li < hs)
	{
		pv = partition(array, li, hs, size);
		qst(array, li, pv - 1, size);
		qst(array, pv + 1, hs, size);

	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using the
 * Quick sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	qst(array, 0, size - 1, size);
}
