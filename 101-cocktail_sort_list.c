#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Pointer to the head of the doubly linked list.
 * @a: Pointer to the first node.
 * @b: Pointer to the second node.
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	listint_t *prev_a = a->prev;
	listint_t *next_b = b->next;

	/* If a is not the head, update the next of its previous node */
	if (prev_a != NULL)
		prev_a->next = b;
	else
		*list = b;

	/* Update the previous and next pointers of a and b */
	a->prev = b;
	b->next = a;
	b->prev = prev_a;
	a->next = next_b;

	/* If b is not the last node, update the previous of its next node */
	if (next_b != NULL)
		next_b->prev = a;

	/* Print the list after each swap */
	print_list(*list);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail Shaker sort algorithm.
 * @list: Pointer to the head of the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start = *list, *end = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;

		/* Traverse the list from left to right */
		while (start->next != end)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				swapped = 1;
			}
			else
				start = start->next;
		}

		/* If no swaps occurred, the list is sorted */
		if (swapped == 0)
			break;

		/* Update the end to the last swapped element */
		end = start;

		/* Traverse the list from right to left */
		while (start->prev != NULL)
		{
			if (start->prev->n > start->n)
			{
				swap_nodes(list, start->prev, start);
				swapped = 1;
			}
			else
				start = start->prev;
		}
	} while (swapped);
}
