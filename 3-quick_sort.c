#include "sort.h"
#include <stdio.h>

size_t partition(int **arr, size_t low, size_t high, size_t size)
{
    size_t i, j;
    int temp, pivot;

    pivot = (*arr)[high];
    i = low - 1;

    for (j = low; j < high; j++)
    {
        if ((*arr)[j] <= pivot)
        {
            i++;
            temp = (*arr)[i];
            (*arr)[i] = (*arr)[j];
            (*arr)[j] = temp;
            if ((*arr)[i] != (*arr)[j])
                print_array(*arr, size);
        }
    }

    temp = (*arr)[i + 1];
    (*arr)[i + 1] = (*arr)[high];
    (*arr)[high] = temp;
    if ((*arr)[i + 1] != (*arr)[high])
        print_array(*arr, size);

    return (i + 1);
}

void quick_sort_recursive(int **arr, size_t low, size_t high, size_t size)
{
    size_t pi;

    if (low < high)
    {
        pi = partition(arr, low, high, size);

        if (pi != 0)
            quick_sort_recursive(arr, low, pi - 1, size);
        if (pi < size - 1)
            quick_sort_recursive(arr, pi + 1, high, size);
    }
}

void quick_sort(int *array, size_t size)
{
    if (size > 1)
        quick_sort_recursive(&array, 0, size - 1, size);
}
