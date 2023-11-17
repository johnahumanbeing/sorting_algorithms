#include "sort.h"
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
			(*list)->n = value;
		else
			temp->next->n = value;

		print_list(*list);
		curr = curr->next;
	}
}
