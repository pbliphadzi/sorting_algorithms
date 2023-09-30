#include "sort.h"

void selection_sort(int *array, size_t size)
{
	size_t i, j, tmp, ABC;

	for (i = 0; i < size - 1; i++)
	{
		ABC = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[ABC])
				ABC = j;

		if (ABC != i)
		{
			tmp = array[i];
			array[i] = array[ABC];
			array[ABC] = tmp;

			print_array(array, size);
		}
	}
}