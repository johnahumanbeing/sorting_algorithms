#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - sorts a list using insertion algorithm
 * @list: A doubly linked list
 * Return: nothing to return
*/
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

		listint_t *curr = (*list)->next;

	while (curr != NULL)
	{
		listint_t *temp = curr->prev;
		int value = curr->n;

		while (temp != NULL && temp->n > value)
		{
			temp->next->n = temp->n;
			temp = temp->prev;
		}

		if (temp == NULL)
		{
			curr->prev->next = curr->next;
			if (curr->next != NULL)
				curr->next->prev = curr->prev;
			curr->next = *list;
			curr->prev = NULL;
			(*list)->prev = curr;
			*list = curr;
		} else
		{
			temp->next->prev = curr;
			curr->prev = temp;
			curr->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = curr;
			temp->next = curr;
		}

		print_list(*list);
		curr = curr->next;
	}
}
