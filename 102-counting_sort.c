#include "sort.h"

/**
 * counting_sort - sort an array of integers using counting sort
 * @array: an array to sort
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output, max, i;

	if (array == NULL || size < 2)
		return;
	for (max = array[0], i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(output);
		return;
	}
	/* initialize count array with 0*/
	for (i = 0; i <= max ; i++)
		count[i] = 0;
	/* store the count of each element*/
	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	for (i = 0; i <= max; i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	/* find index of each element of the original array*/
	/* place the elements into output array*/
	for (i = size - 1; i >= 0 ; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	/* copy the sorted element into original array*/
	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
	free(output);
	free(count);
}
