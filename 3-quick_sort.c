#include "sort.h"
#include "swap.c"
#include <stdio.h>

/**
 * partition - function swaps and sort according to pivot
 * @array: array of integers
 * @left: lowest index of the array
 * @right: highest index of the array
 * @size: size of the array;
 *
 * Return: index for future recursive partitions
 */

int partition(int **array, int left, int right, size_t size)
{
	int *arr = *array;
	int pivot = arr[right], i = left - 1, j;

	for (j = left; j < right; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			if (arr[i] != arr[j])
			{
				swap(&arr[i], &arr[j]);
				print_array(arr, size);
			}
		}
	}
	if (arr[i + 1] != arr[right])
	{
		swap(&arr[i + 1], &arr[right]);
		print_array(arr, size);
	}
	return (i + 1);
}

/**
 * quick_sort_recu - recursive function of quick_sort
 * @array: array of integers to be sort
 * @left: lowest index of the array
 * @right: high index of the array
 * @size: size of the array
 *
 * Return: void
 */

void quick_sort_recu(int **array, int left, int right, size_t size)
{
	int *arr = *array;
	int swp_mark = 0;

	if (left < right)
	{
		swp_mark = partition(&arr, left, right, size);
		quick_sort_recu(&arr, left, swp_mark - 1, size);
		quick_sort_recu(&arr, swp_mark + 1, right, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array of integers
 * @size: int (size of the array)
 *
 * Return: void;
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_recu(&array, 0, size - 1, size);
}
