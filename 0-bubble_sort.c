#include "sort.h"
#include "swap.c"

/**
 * bubble_sort - sorts an array of integers in ascending
 * order using the Bubble sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i = 0, j = 0;
	int flag = 0;

	if (!array || size == 0)
		return;

	for (; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			flag = 0;
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				flag = 1;
				print_array(array, size);
			}
		}
		if (flag == 0)
			break;
	}
}
