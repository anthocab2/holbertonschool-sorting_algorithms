#include "sort.h"

/* swap - Swaps two elements in an array */
void swap(int *a, int *b)
{
int temp;
temp = *a;
*a = *b;
*b = temp;
}

/* lomuto_partition - Partitions the array using Lomuto scheme */
size_t lomuto_partition(int *array, size_t low, size_t high, size_t size)
{
size_t i, j;

i = low;
for (j = low; j < high; j++)
{
if (array[j] < array[high])
{
if (i != j)
{
swap(&array[i], &array[j]);
print_array(array, size);
}
i++;
}
}
if (i != high)
{
swap(&array[i], &array[high]);
print_array(array, size);
}
return (i);
}

/* quick_sort_recursive - Recursively sorts the array */
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size)
{
size_t pivot;

if (low < high)
{
pivot = lomuto_partition(array, low, high, size);
if (pivot > 0)
quick_sort_recursive(array, low, pivot - 1, size);
quick_sort_recursive(array, pivot + 1, high, size);
}
}

/* quick_sort - Sorts an array of integers in ascending order */
void quick_sort(int *array, size_t size)
{
if (!array || size < 2)
return;

quick_sort_recursive(array, 0, size - 1, size);
}
