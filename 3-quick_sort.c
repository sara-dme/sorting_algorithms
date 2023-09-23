#include "sort.h"

int lomuto(int *array, int first, int last, size_t size);
void quick_sort_part(int *array, int first, int last, size_t size);

/**
 * quick_sort - sorrts an array using quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	int first = 0, last = size - 1;

	if (array == NULL || size < 2)
		return;

	quick_sort_part(array, first, last, size);
}

/**
 * quick_sort_part - sort the array
 * @array: array to be sorted
 * @first: first elemnet in the array
 * @last: last element in the array
 * @size: size of the array
 */
void quick_sort_part(int *array, int first, int last, size_t size)
{
	int piv;

	if (last <= first)
		return;

	piv = lomuto(array, first, last, size);
	quick_sort_part(array, first, piv - 1, size);
	quick_sort_part(array, piv + 1, last, size);
}

/**
 * lomuto - patitioning the array using the lomuto scheme
 * @array: array to be partitioned
 * @first: first elemnet in the array
 * @last: last element in the array
 * @size: size of the array
 * Return: index of the pivot
 */
int lomuto(int *array, int first, int last, size_t size)
{
	int piv = array[last];
	int i = first - 1, j, tmp;

	for (j = first; j <= last - 1; j++)
	{
		if (array[j] <= piv)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			if (array[i] != array[j])
				print_array(array, size);
		}
	}
	i++;
	tmp = array[i];
	array[i] = array[last];
	array[last] = tmp;
	if (array[i] != array[last])
		print_array(array, size);
	return (i);
}
