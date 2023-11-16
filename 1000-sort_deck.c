#include "deck.h"
#include <stdlib.h>
#include <string.h>

/**
 * compare_cards - Compare function for qsort.
 * @a: Pointer to the first card.
 * @b: Pointer to the second card.
 *
 * Return: Integer less than, equal to, or greater than zero if a is found,
 * respectively, to be less than, to match, or be greater than b.
 */
int compare_cards(const void *a, const void *b)
{
	const card_t *card_a = (*(deck_node_t **)a)->card;
	const card_t *card_b = (*(deck_node_t **)b)->card;
	int value_cmp = strcmp(card_a->value, card_b->value);

	if (value_cmp != 0)
		return (value_cmp);

	return (card_a->kind - card_b->kind);
}

/**
 * sort_deck - Sorts a deck of cards.
 * @deck: Pointer to the head of the deck.
 */
void sort_deck(deck_node_t **deck)
{
	size_t i, len = 0;
	deck_node_t *current = *deck;
	deck_node_t **array;

	if (deck == NULL || *deck == NULL)
		return;

	while (current != NULL)
	{
		len++;
		current = current->next;
	}
	array = malloc(len * sizeof(deck_node_t *));
	if (array == NULL)
		return;

	current = *deck;
	for (i = 0; i < len; i++)
	{
		array[i] = current;
		current = current->next;
	}
	qsort(array, len, sizeof(deck_node_t *), compare_cards);
	*deck = array[0];
	for (i = 0; i < len - 1; i++)
	{
		array[i]->next = array[i + 1];
		array[i + 1]->prev = array[i];
	}
	array[len - 1]->next = NULL;
	free(array);
}
