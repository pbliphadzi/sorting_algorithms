
#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using
 * the Bubble sort algorithm.
 * @arr: Pointer to the array of integers.
 * @size: Size of the array.
 */
void bubble_sort(int *arr, size_t size)
{
    int has_swapped = 1;
    size_t A, temp, end = size;

    while (has_swapped)
    {
        has_swapped = 0;
        for (A = 1; A < end; A++)
        {
            if (arr[A - 1] > arr[A])
            {
                temp = arr[A - 1];
                arr[A - 1] = arr[A];
                arr[A] = temp;

                has_swapped = 1;
                print_array(arr, size);
            }
        }
        end--;
    }
}