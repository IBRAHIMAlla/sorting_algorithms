#include "sort.h"
/**
*sw - the positions of two elements into an array
*@array: array
*@item2: array element
*@item3: array element
*/
void sw(int *array, ssize_t item2, ssize_t item3)
{
	int mpt;

	mpt = array[item2];
	array[item2] = array[item3];
	array[item3] = mpt;
}
/**
 *partition - partition sorting scheme implementation
 *@array: array
 *@ft: first array element
 *@lt: last array element
 *@size: size array
 *Return: return the position of the last element sorted
 */
int partition(int *array, ssize_t ft, ssize_t lt, size_t size)
{
	int pv = array[lt];
	ssize_t cur = ft, fd;

	for (fd = ft; fd < lt; fd++)
	{
		if (array[fd] < pv)
		{
			if (array[cur] != array[fd])
			{
				sw(array, cur, fd);
				print_array(array, size);
			}
			cur++;
		}
	}
	if (array[cur] != array[lt])
	{
		sw(array, cur, lt);
		print_array(array, size);
	}
	return (cur);
}
/**
 *qst - qucksort algorithm implementation
 *@array: array
 *@ft: first array element
 *@lt: last array element
 *@size: array size
 */
void qst(int *array, ssize_t ft, ssize_t lt, int size)
{
	ssize_t ps = 0;


	if (ft < lt)
	{
		ps = partition(array, ft, lt, size);

		qst(array, ft, ps - 1, size);
		qst(array, ps + 1, lt, size);
	}
}
/**
 *quick_sort - prepare the terrain to quicksort
 *@array: array
 *@size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qst(array, 0, size - 1, size);
}
