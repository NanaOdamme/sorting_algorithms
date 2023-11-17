#include <stdlib.h>
#include "sort.h"

/**
 * MAX - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int MAX(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}
/**
 * counting_sort - Sorts an array of integers in ascending
 * order using Counting sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int max, i;
	int *counting_array, *sorted_array;

	if (array == NULL || size < 2)
		return;

	sorted_array = malloc(sizeof(int) * size);
	if (sorted_array == NULL)
		return;

	max = MAX(array, size);
	counting_array = malloc(sizeof(int) * (max + 1));
	if (counting_array == NULL)
	{
		free(sorted_array);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		counting_array[i] = 0;
	for (i = 0; i < (int)size; i++)
		counting_array[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		counting_array[i] += counting_array[i - 1];
	print_array(counting_array, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sorted_array[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sorted_array[i];

	free(sorted_array);
	free(counting_array);
}
