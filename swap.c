#include "sort.h"

/**
 * swap - swap two elements of an array
 * @arr: - value 1
 * @arr2: - value 2
 *
 * Return: void
 */

void swap(int *val1, int *val2)
{
	int temp = *val1;

	*val1 = *val2;
	*val2 = temp;
}
