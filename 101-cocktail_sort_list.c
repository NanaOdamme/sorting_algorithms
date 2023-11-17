#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @a: First node to swap
 * @b: Second node to swap
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	else
		*list = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *		in ascending order using Cocktail shaker sort
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *temp;

	if (list == NULL || *list == NULL)
		return;

	do
	{
		swapped = 0;
		for (temp = *list; temp->next != NULL; temp = temp->next)
		{
			if (temp->n > temp->next->n)
			{
				swap_nodes(list, temp, temp->next);
				print_list(*list);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
		swapped = 0;
		for (; temp->prev != NULL; temp = temp->prev)
		{
			if (temp->n < temp->prev->n)
			{
				swap_nodes(list, temp->prev, temp);
				print_list(*list);
				swapped = 1;
			}
		}
	} while (swapped);
}
