#include "deck.h"
#include <stdlib.h>
#include <string.h>

/**
 * compare_cards - Compare function for qsort to compare two card_t objects
 * @a: Pointer to the first card_t
 * @b: Pointer to the second card_t
 *
 * Return: Negative value if a < b, 0 if a == b, positive value if a > b
 */
int compare_cards(const void *a, const void *b)
{
	const card_t *card_a = (*(const deck_node_t **)a)->card;
	const card_t *card_b = (*(const deck_node_t **)b)->card;

	if (card_a->kind != card_b->kind)
	return (card_a->kind - card_b->kind);
	return (strcmp(card_a->value, card_b->value));
}

/**
 * sort_deck - Sorts a deck of cards in ascending order by kind and value
 * @deck: Pointer to a pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	size_t count = 0;
	deck_node_t *current = *deck;
	deck_node_t **deck_array;
	size_t i;

	while (current)
	{
		count++;
		current = current->next;
	}
	deck_array = malloc(count * sizeof(deck_node_t *));
	if (!deck_array)
	exit(EXIT_FAILURE);

	current = *deck;
	for (i = 0; i < count; i++)
	{
		deck_array[i] = current;
		current = current->next;
	}

	qsort(deck_array, count, sizeof(deck_node_t *), compare_cards);

	for (i = 0; i < count; i++)
	{
		deck_array[i]->prev = (i > 0) ? deck_array[i - 1] : NULL;
		deck_array[i]->next = (i < count - 1) ? deck_array[i + 1] : NULL;
	}
	*deck = deck_array[0];
	free(deck_array);
}
