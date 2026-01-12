#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

void merge_sort_recursive(int *array, int *buffer, size_t left, size_t right);
void merge_arrays(int *array, int *buffer, size_t left, size_t mid, size_t right);

/**
 * merge_sort - sorts an array using merge sort
 * @array: array to sort
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
int *buffer;

if (!array || size < 2)
return;

buffer = malloc(sizeof(int) * size);
if (!buffer)
return;

merge_sort_recursive(array, buffer, 0, size);

free(buffer);
}

/**
 * merge_sort_recursive - recursive merge sort
 */
void merge_sort_recursive(int *array, int *buffer, size_t left, size_t right)
{
size_t mid;

if (right - left < 2)
return;

mid = left + (right - left) / 2;

merge_sort_recursive(array, buffer, left, mid);
merge_sort_recursive(array, buffer, mid, right);

merge_arrays(array, buffer, left, mid, right);
}

/**
 * merge_arrays - merge two subarrays
 */
void merge_arrays(int *array, int *buffer, size_t left, size_t mid, size_t right)
{
size_t i = left, j = mid, k = 0;

printf("Merging...\n");
printf("[left]: ");
print_array(array + left, mid - left);
printf("[right]: ");
print_array(array + mid, right - mid);

while (i < mid && j < right)
{
if (array[i] <= array[j])
buffer[k++] = array[i++];
else
buffer[k++] = array[j++];
}

while (i < mid)
buffer[k++] = array[i++];

while (j < right)
buffer[k++] = array[j++];

for (i = left, k = 0; i < right; i++)
array[i] = buffer[k++];

printf("[Done]: ");
print_array(array + left, right - left);
}
