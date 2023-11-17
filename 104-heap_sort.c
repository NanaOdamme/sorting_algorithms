#include "sort.h"

#include <stdlib.h>

/**
 * swap - Swaps two elements in an array.
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - Creates a max heap from an array.
 * @array: The array to be transformed into a max heap.
 * @size: The size of the array.
 * @index: The index to start heapifying from.
 * @node: riit node of the binary tree
 */
void heapify(int *array, size_t size, size_t index, size_t node)
{
	size_t largest = node;
	size_t left = 2 * node + 1;
	size_t right = 2 * node + 2;

	if (left < index && array[left] > array[largest])
		largest = left;

	if (right < index && array[right] > array[largest])
		largest = right;

	if (largest != node)
	{
		swap(array + node, array + largest);
		print_array(array, size);
		heapify(array, size, index, largest);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}
