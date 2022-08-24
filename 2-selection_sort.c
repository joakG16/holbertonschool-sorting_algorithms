#include "sort.h"
#include "swap.c"

/**
 * selection_sort - that sorts an array of integers in
 * ascending order using the Selection sort algorithm
 * @array: array given
 * @size: array size
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int indmin = 0, minval = 0;

	for (i = 0; i < size; i++)
	{
		minval = array[i]; /* setting minimumn value to the
				    * actual position
				    */
		for (j = i + 1; j < size; j++) /* array starts a postion + 1
						* so it checks with the
						* previous one for min val
						*/
		{
			if (array[j] < minval)
			{
				minval = array[j]; /* setting new minimumn */
				indmin = j; /* saving the index for swapping */
			}
		}
		if (minval != array[i]) /* if the minimumn value differs from the
					 * one at the beginning of the iteratio
					 */
		{
			swap(&array[i], &array[indmin]);
			print_array(array, size);
		}
	}
}
