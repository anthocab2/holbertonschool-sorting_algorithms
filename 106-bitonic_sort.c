#include <stdio.h>
#include "sort.h"

/**
 * swap_int - Swap two integers in an array
 * @a: first integer
 * @b: second integer
 */
void swap_int(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/**
 * bitonic_merge - Merge bitonic sequence in ascending or descending order
 * @array: array to sort
 * @low: starting index
 * @cnt: number of elements
 * @dir: 1 for UP, 0 for DOWN
 * @size: total size of original array (for printing)
 */
void bitonic_merge(int *array, size_t low, size_t cnt, int dir, size_t size)
{
    size_t k, i;
    if (cnt > 1)
    {
        k = cnt / 2;

        /* Compare and swap elements in first and second halves */
        for (i = low; i < low + k; i++)
        {
            if ((dir && array[i] > array[i + k]) ||
                (!dir && array[i] < array[i + k]))
                swap_int(&array[i], &array[i + k]);
        }

        /* Recursive merge */
        bitonic_merge(array, low, k, dir, size);
        bitonic_merge(array, low + k, k, dir, size);

        /* Print after merge */
        printf("Result [%lu/%lu] (%s):\n", cnt, size, dir ? "UP" : "DOWN");
        print_array(array + low, cnt);
    }
}

/**
 * bitonic_sort_rec - recursive bitonic sort
 * @array: array to sort
 * @low: starting index
 * @cnt: number of elements
 * @dir: 1 for UP, 0 for DOWN
 * @size: total size of original array
 */
void bitonic_sort_rec(int *array, size_t low, size_t cnt, int dir, size_t size)
{
    size_t k;
    if (cnt > 1)
    {
        k = cnt / 2;

        /* Print the current merge operation */
        printf("Merging [%lu/%lu] (%s):\n", cnt, size, dir ? "UP" : "DOWN");
        print_array(array + low, cnt);

        /* Sort first half in UP order, second half in DOWN order */
        bitonic_sort_rec(array, low, k, 1, size);
        bitonic_sort_rec(array, low + k, k, 0, size);

        /* Merge the bitonic sequence in given direction */
        bitonic_merge(array, low, cnt, dir, size);
    }
}

/**
 * bitonic_sort - Entry point for bitonic sort
 * @array: array to sort
 * @size: size of array
 */
void bitonic_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    bitonic_sort_rec(array, 0, size, 1, size);
}
