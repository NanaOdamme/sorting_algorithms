#include "sort.h"
#include <stdio.h>

void swap(int *a, int *b);
void bitonic_sort(int *array, size_t size);
void bitonic_recursive(int *array, size_t size, int dir);
void bitonic_merge(int *array, size_t size, int dir);
void p_array(int *array, size_t size);
/**
 * bitonic_sort - Sorts an array using the bitonic sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 */
void bitonic_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

printf("\nMerging [%lu/%lu] (UP):\n", size, size);
p_array(array, size);

bitonic_recursive(array, size, 1);

printf("\nResult [%lu/%lu] (UP):\n", size, size);
p_array(array, size);
printf("\n");
}

/**
 * bitonic_recursive - Recursive part of the bitonic sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 * @dir: Direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_recursive(int *array, size_t size, int dir)
{
size_t half = size / 2;

if (size > 1)
{
printf("\nMerging [%lu/%lu] (UP):\n", half, size);
p_array(array, half);

bitonic_recursive(array, half, 1);
bitonic_recursive(array + half, half, 0);

bitonic_merge(array, size, dir);

printf("\nResult [%lu/%lu] (UP):\n", size, size);
p_array(array, size);
}
}

/**
 * bitonic_merge - Performs the merging step of the bitonic sort
 * @array: Array to be sorted
 * @size: Size of the array
 * @dir: Direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t size, int dir)
{
size_t half;
size_t i;

if (size > 1)
{
half = size / 2;
for (i = 0; i < half; i++)
{
if (dir == (array[i] > array[i + half]))
swap(&array[i], &array[i + half]);
}

bitonic_merge(array, half, dir);
bitonic_merge(array + half, half, dir);
}
}
/**
 * swap - Swaps two elements in an array
 * @a: First element
 * @b: Second element
 */
void swap(int *a, int *b)
{
int temp;

temp = *a;
*a = *b;
*b = temp;

/*printf("Swapping %d and %d\n", *a, *b);*/
}

/**
 * p_array - prints the elements of an array
 * @array: array to be printed
 * @size: size of the array
 */
void p_array(int *array, size_t size)
{
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
	}
}
