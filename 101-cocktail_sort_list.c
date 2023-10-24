#include "sort.h"
#include <stdio.h>
/**
 *swp_n - swap a node for his previous one
 *@nd: node
 *@list: node list
 *Return: return a pointer to a node which was enter it
 */
listint_t *swp_n(listint_t *nd, listint_t **list)
{
	listint_t *b = nd->prev, *cur = nd;

	b->next = cur->next;
	if (cur->next)
		cur->next->prev = b;
	cur->next = b;
	cur->prev = b->prev;
	b->prev = cur;
	if (cur->prev)
		cur->prev->next = cur;
	else
		*list = cur;
	return (cur);
}
/**
 *cocktail_sort_list - cocktail sort implementation
 *working on a double linked lists
 *@list: list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *nd;
	int swap_d = 1;

	if (list == '\0' || (*list) == '\0' || (*list)->next == '\0')
		return;
	nd = *list;
	while (swap_d == 1)
	{
		swap_d = 0;
		while (nd->next)
		{
			if (nd->n > nd->next->n)
			{
				nd = swp_n(nd->next, list);
				swap_d = 1;
				print_list(*list);
			}
			nd = nd->next;
		}
		if (swap_d == 0)
			break;
		swap_d = 0;
		while (nd->prev)
		{
			if (nd->n < nd->prev->n)
			{
				nd = swp_n(nd, list);
				swap_d = 1;
				print_list(*list);
			}
			else
				nd = nd->prev;
		}
	}
}
