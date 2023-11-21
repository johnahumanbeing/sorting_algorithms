#include "sort.h"
/**
*swap_nodes - swaps two nodes in a given doubly linked list
*@na: the first node
*@nb: the second node
*@list: the linked list
*@t: tail
*Return: nothing to return
*/
void swap_nodes(listint_t *na, listint_t *nb, listint_t **list, listint_t **t)
{
	listint_t *temp, *curr, *next;

	temp = na->prev;
	curr = na;
	next = nb;

	curr->next = next->next;
	next->prev = temp;

	if (temp)
		temp->next = next;

	if (next->next)
		next->next->prev = curr;
	curr->prev = next;
	next->next = curr;

	if (!(next->prev))
		*list = next;

	if (!(curr->next))
		*t = curr;

	print_list(*list);
}


/**
*cocktail_sort_list - sorts a doubly linked list of integers in ascending
*	order using the Cocktail shaker sort algorithm
*@list: the doubly linked list to be sorted
*Return: nothing to return
*/
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *ptr, *term;

	if (!list || !*list || !(*list)->next)
		return;

	term = *list;
	while (term->next)
		term = term->next;

	do {
		swapped = 0;
		ptr = *list;
		while (ptr)
		{
			while (ptr->next && ptr->n > ptr->next->n)
			{
				swap_nodes(ptr, ptr->next, list, &term);
				swapped = 1;
				ptr = ptr->prev;
			}
			ptr = ptr->next;
		}
		if (!swapped)
			break;

		swapped = 0;
		ptr = term;
		while (ptr)
		{
			while (ptr->prev && ptr->n < ptr->prev->n)
			{
				swap_nodes(ptr->prev, ptr, list, &term);
				swapped = 1;
				ptr = ptr->next;
			}
			ptr = ptr->prev;
		}
	} while (swapped);
}
