#include "sort.h"
#include "stdlib.h"

/**
 * counting_sort - sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: array to sort
 * @size: size of the array to sort
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int m, mx;
	int *digit = NULL, *cp = NULL;
	size_t y, mpt, tl = 0;


	if (array == NULL || size < 2)
		return;
	cp = malloc(sizeof(int) * size);
	if (cp == NULL)
		return;
	for (y = 0, mx = 0; y < size; y++)
	{
		cp[y] = array[y];
		if (array[y] > mx)
			mx = array[y];
	}
	digit = malloc(sizeof(int) * (mx + 1));
	if (digit == NULL)
	{
		free(cp);
		return;
	}
	for (m = 0; m <= mx; m++)
		count[m] = 0;
	for (y = 0; y < size; y++)
		digit[array[y]] += 1;
	for (m = 0; m <= mx; m++)
	{
		mpt = digit[m];
		digit[m] = tl;
		tl += mpt;
	}
	for (y = 0; y < size; y++)
	{
		array[digit[cp[y]]] = cp[y];
		digit[cp[y]] += 1;
	}
	print_array(digit, mx + 1);
	free(digit);
	free(cp);
}
