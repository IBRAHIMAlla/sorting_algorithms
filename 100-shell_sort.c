#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the
 * Shell sort algorithm
 * @array: array to sort
 * @size: size of the array to sort
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t m, y, g = 1;
	int in;

	if (array == NULL || size < 2)
		return;

	while (g < size / 3)
		g = g * 3 + 1;

	while (g > 0)
	{
		for (m = g; m < size; m++)
		{
			in = array[m];
			for (y = m; y >= g && array[y - g] > in; y = y - g)
				array[y] = array[y - g];
			array[y] = in;
		}
		g = (g - 1) / 3;
		print_array(array, size);
	}
}
