#include "sort.h"
/**
*swap_nodes - swaps two nodes in a given doubly linked list
*@na: the first node
*@nb: the second node
*@list: the linked list
*@t: tail
*Return: nothing to return
*/
void swap_nodes(listint_t *na, listint_t *nb, listint_t **list,  listint_t **t) 
{
    listint_t *temp, *curr, *next;

    temp = na->temp;
    curr = na;
    next = nb;

    curr->next = next->next;
    next->temp = temp;

    if (temp)
            temp->next = next;

    if (next->next)
            next->next->temp = curr;

    curr->temp = next;
    next->next = curr;

    if (!(next->temp))
            *list = next;

    if (!(curr->next))
            *t = curr;

    print_list(*list);
}

/**
*cocktail_sort_list - sorts a doubly linked list of integers in ascending order using 
*                   the Cocktail shaker sort algorithm
*@list: the doubly linked list to be sorted
*Return: nothing to return
*/    
/*
yet to fix this part
void cocktail_sort_list(listint_t **list) 
{
    int swapped;
    listint_t *ptr;
    listint_t *head = *list;

    if (head == NULL)
        return;

    do {
        swapped = 0;
        ptr = head;

        while (ptr->next != NULL) 
        {
            if (ptr->n > ptr->next->n) 
            {
                swap_nodes(ptr, &(ptr->next), list);
                swapped = 1;
                print_list(*list);
            }
            else
                ptr = ptr->next;
        }

        if (!swapped)
            break;

        swapped = 0;
        ptr = ptr->prev;

        while (ptr->prev != NULL) 
        {
            if (ptr->n < ptr->prev->n) 
            {
                swap_nodes(&(ptr->prev), &ptr, list);
                swapped = 1;
                print_list(*list);
            }
            else
                ptr = ptr->prev;
        }
    } while (swapped);
}
*/