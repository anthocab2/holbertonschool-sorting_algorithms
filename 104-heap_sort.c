#include "sort.h"

/**
 * swap_int - swaps two integers
 */
void swap_int(int *a, int *b)
{
int tmp;

tmp = *a;
*a = *b;
*b = tmp;
}

/**
 * sift_down - restores heap property
 */
void sift_down(int *array, size_t size, size_t start, size_t end)
{
size_t root, child, swap;

root = start;

while ((root * 2 + 1) <= end)
{
child = root * 2 + 1;
swap = root;

if (array[swap] < array[child])
swap = child;

if (child + 1 <= end && array[swap] < array[child + 1])
swap = child + 1;

if (swap == root)
return;
else
{
swap_int(&array[root], &array[swap]);
print_array(array, size);
root = swap;
}
}
}

/**
 * heap_sort - sorts an array using heap sort
 * @array: array to sort
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
ssize_t start, end;

if (!array || size < 2)
return;

/* Build max heap */
for (start = (size - 2) / 2; start >= 0; start--)
sift_down(array, size, start, size - 1);

/* Heap sort */
for (end = size - 1; end > 0; end--)
{
swap_int(&array[0], &array[end]);
print_array(array, size);
sift_down(array, size, 0, end - 1);
}
}
