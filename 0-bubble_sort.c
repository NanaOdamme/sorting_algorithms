#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Sorts an array of integers in ascending order using
 * the Bubble sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	int swapped;
	size_t i, j, k;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = 1;
				/* Print the array after each swap */
				for (k = 0; k < size; k++)
				{
					printf("%d", array[k]);
					if (k < size - 1)
						printf(", ");
				}
				printf("\n");
			}
		}
		/* If no two elements were swapped, the array is already sorted */
		if (swapped == 0)
			break;
	}
void bubble_sort(int *array, size_t size)
{
        int swapped;
        size_t i, j, k;

        if (array == NULL || size == 0)
                return;

        for (i = 0; i < size - 1; i++)
        {
                swapped = 0;
                for (j = 0; j < size - i - 1; j++)
                {
                        if (array[j] > array[j + 1])
                        {
                                swap(&array[j], &array[j + 1]);
                                swapped = 1;
                                /* Print the array after each swap */
                                for (k = 0; k < size; k++)
                                {
                                        printf("%d", array[k]);
                                        if (k < size - 1)
                                                printf(", ");
                                }
                                printf("\n");
                        }
                }
                /* If no two elements were swapped, the array is already sorted */
                if (swapped == 0)
                        break;
        }
}}
