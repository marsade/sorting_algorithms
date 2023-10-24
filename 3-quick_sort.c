#include "sort.h"
/**
 * swap_int - swap integer values
 * @a: int a
 * @b: int b
*/
void swap_int(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
/**
 * lomuto_partition - the lomuto partition function
 * @arr: the array
 * @low: index of leftmost element in array
 * @high: index of rightmost element in array
 * @size: size of the array
 * Return: the index of the pivot element
*/
int lomuto_partition(int *arr, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = arr[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap_int(&arr[i], &arr[j]);
		}
	}
	swap_int(&arr[i + 1], &arr[high]);
	print_array(arr, size);
	return (i + 1);
}
/**
 * quicksort - quicksort algorithm using lomuto partition
 * @arr: array of integers
 * @low: low
 * @high: high
 * @size: size of array
*/
void quicksort(int *arr, int low, int high, size_t size)
{
	int pivot_idx;

	if (low < high)
	{
		pivot_idx = lomuto_partition(arr, low, high, size);
		quicksort(arr, low, pivot_idx - 1, size);
		quicksort(arr, pivot_idx + 1, high, size);
	}
}
/**
 * quick_sort - sort an array of integers using the quick sort algorithm
 * @array: an array of integers
 * @size: size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
