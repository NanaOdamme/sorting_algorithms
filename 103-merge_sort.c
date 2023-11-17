#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two subarrays into one sorted array.
 * @array: The original array.
 * @left: The left subarray.
 * @left_size: The size of the left subarray.
 * @right: The right subarray.
 * @right_size: The size of the right subarray.
 */
void merge(int *array, int *left, size_t left_size,
		int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array, left_size);

	printf("[right]: ");
	print_array(array, right_size);
	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
		array[k++] = left[i++];
		else
		array[k++] = right[j++];
	}

	while (i < left_size)
		array[k++] = left[i++];

	while (j < right_size)
		array[k++] = right[j++];

	printf("[Done]: ");
	print_array(array, right_size + right_size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 * using Merge sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	size_t mid, left_size, right_size;
	int *left, *right;

	if (size > 1)
	{
		/*Divide the array into two halves*/
		mid = size / 2;
		left = array;
		right = array + mid;
		left_size = mid;
		right_size = size - mid;

		/*Recursively sort each half*/
		merge_sort(left, left_size);
		merge_sort(right, right_size);

		/*Merge the sorted halves*/
		merge(array, left, left_size, right, right_size);
	}
}
