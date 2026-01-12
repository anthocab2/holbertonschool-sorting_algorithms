#include "sort.h"

/**
 * swap_int - swaps two integers in an array
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
 * bitonic_merge - recursively merges bitonic sequence
 * @array: array of integers
 * @low: starting index
 * @count: number of elements
 * @dir: 1 for ascending, 0 for descending
 * @size: size of the array for print_array
 */
void bitonic_merge(int *array, int low, int count, int dir, size_t size)
{
    int k, i;

    if (count > 1)
    {
        k = count / 2;
        for (i = low; i < low + k; i++)
        {
            if ((dir && array[i] > array[i + k]) ||
                (!dir && array[i] < array[i + k]))
            {
                swap_int(&array[i], &array[i + k]);
            }
        }
        printf("Merging [%d/%lu] (%s):\n", (int)count, size, dir ? "UP" : "DOWN");
        for (i = low; i < low + count; i++)
        {
            if (i != low)
                printf(", ");
            printf("%d", array[i]);
        }
        printf("\n");
        bitonic_merge(array, low, k, dir, size);
        bitonic_merge(array, low + k, k, dir, size);
    }
}

/**
 * bitonic_rec - recursively builds a bitonic sequence
 * @array: array of integers
 * @low: starting index
 * @count: number of elements
 * @dir: 1 for ascending, 0 for descending
 * @size: size of the array for print_array
 */
void bitonic_rec(int *array, int low, int count, int dir, size_t size)
{
    int k;

    if (count > 1)
    {
        k = count / 2;
        bitonic_rec(array, low, k, 1, size);        /* ascending */
        bitonic_rec(array, low + k, k, 0, size);    /* descending */
        bitonic_merge(array, low, count, dir, size);
    }
}

/**
 * bitonic_sort - sorts an array in ascending order using Bitonic sort
 * @array: array of integers
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    bitonic_rec(array, 0, size, 1, size);
}
