#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers,
 * in ascending order using the Insertion sort algorithm
 * @list: the list
**/

void insertion_sort_list(listint_t **list)
{
	listint_t *nd, *tpm, *next, *tpm_n, *tpm_p;
	int m = 0;

	if (list == NULL || (*list)->next == NULL)
		return;
	nd = *list;
	nd = nd->next;
	while (nd != NULL)
	{
		tpm = nd;
		next = nd->next;
		tpm_n = tpm->next;
		tpm_p = tpm->prev;

		while (tpm->prev != NULL && tpm_p->n > tpm->n)
		{
			if (tpm_n != NULL)
				tpm_n->prev = tpm_p;
			tpm_p->next = tpm_n;
			if (tpm_p->prev == NULL)
			{
				tpm_p->prev = tpm;
				*list = tpm;
				tpm->prev = NULL;
			}
			else
			{
				tpm->prev = tpm_p->prev;
				tpm_p->prev->next = tpm;
				tpm_p->prev = tpm;
			}
			tpm->next = tpm_p;
			tpm_p = tpm->prev;
			tpm_n = tpm->next;
			print_list(*list);
		}
		nd = next;
		m++;
	}
}
