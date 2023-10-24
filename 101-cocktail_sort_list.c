#include "sort.h"
#include <stdio.h>

/**
 * sw - swaps a node with the next node in the list
 * @list: double pointer to the beginning of the list
 * @nd: node to swap
 *
 * Return: void
 */
void sw(listint_t **list, listint_t *nd)
{
	nd->next->prev = nd->prev;
	if (nd->prev)
		nd->prev->next = nd->next;
	else
		*list = nd->next;
	nd->prev = nd->next;
	nd->next = nd->next->next;
	nd->prev->next = nd;
	if (nd->next)
		nd->next->prev = nd;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	char swp = 1;
	listint_t *mpt;

	if (list == NULL || *list == NULL)
		return;
	mpt = *list;
	while (swp != 0)
	{
		swp = 0;
		while (mpt->next != NULL)
		{
			if (mpt->next->n < mpt->n)
			{
				sw(list, temp);
				swp = 1;
				print_list(*list);
			}
			else
				mpt = mpt->next;
		}
		if (swp == 0)
			break;
		swp = 0;
		while (mpt->prev != NULL)
		{
			if (mpt->prev->n > mpt->n)
			{
				sw(list, mpt->prev);
				swp = 1;
				print_list(*list);
			}
			else
				mpt = mpt->prev;
		}
	}
}
