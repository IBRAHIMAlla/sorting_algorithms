#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * merge - sorts and merges the sub arrays in source
 * @st: starting index (inclusive) for the left sub array
 * @me: end index (exclusive) for the left sub array and
 * starting index (inclusive) for the right sub array
 * @end: end index (exclusive) for the right sub array
 * @dt: destination for data
 * @se: source of data
 *
 * Return: void
 */
void merge(size_t st, size_t me, size_t end, int *dt, int *se)
{
	size_t m, y, e;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(source + start, middle - start);
	printf("[right]: ");
	print_array(source + middle, end - middle);
	m = st;
	y = me;
	for (e = st; e < end; e++)
	{
		if (m < me && (y >= end || se[m] <= se[m]))
		{
			dt[e] = se[m];
			m++;
		}
		else
		{
			dt[e] = se[y];
			y++;
		}
	}
	printf("[Done]: ");
	print_array(dt + st, end - st);
}

/**
 * splitMerge - recursively splits the array and merges the sorted arrays
 * @st: starting index (inclusive)
 * @end: end index (exclusive)
 * @array: the array to sort
 * @cy: a copy of the array
 *
 * Return: void
 */
void splitMerge(size_t st, size_t end, int *array, int *cy)
{
	size_t me;

	if (end - st < 2)
		return;
	me = (st + end) / 2;
	splitMerge(st, me, array, cy);
	splitMerge(me, end, array, cy);
	merge(st, me, end, array, cy);
	for (me = st; me < end; me++)
		cy[me] = array[me];
}

/**
 * merge_sort - sorts an array of integers in ascending order using the
 * Merge sort algorithm
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	size_t m;
	int *cy;

	if (array == NULL || size < 2)
		return;
	cy = malloc(sizeof(int) * size);
	if (cy == NULL)
		return;
	for (m = 0; m < size; m++)
		cy[m] = array[m];
	splitMerge(0, size, array, cy);
	free(cy);
}
