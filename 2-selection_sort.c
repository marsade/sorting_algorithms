#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection Sort algorithm
 * @array: the array of integers
 * @size: size of the array
 * Return: nothing
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *min_idx, *add, temp;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = array + i;

		for (j = i + 1; j < size; j++)
		{
			min_idx = (array[j] < *min_idx) ? (array + j) : min_idx;
			if ((array + i) != min_idx)
			{
				add = array + i;
				temp = *add;
				*add = *min_idx;
				*min_idx = temp;
				print_array(array, size);
			}
		}
	}
}
