#include "sort.h"
#include <stdlib.h>

/**
 * counting_sort - sorts an array of integers using Counting sort
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
int *count, *output;
size_t i;
int max, j;

if (!array || size < 2)
return;

/* find max value */
max = array[0];
for (i = 1; i < size; i++)
{
if (array[i] > max)
max = array[i];
}

/* allocate counting array */
count = malloc(sizeof(int) * (max + 1));
if (!count)
return;

/* initialize counting array */
for (i = 0; i <= (size_t)max; i++)
count[i] = 0;

/* count occurrences */
for (i = 0; i < size; i++)
count[array[i]]++;

/* cumulative count */
for (i = 1; i <= (size_t)max; i++)
count[i] += count[i - 1];

/* print counting array */
print_array(count, max + 1);

/* allocate output array */
output = malloc(sizeof(int) * size);
if (!output)
{
free(count);
return;
}

/* build output array */
for (j = size - 1; j >= 0; j--)
{
output[count[array[j]] - 1] = array[j];
count[array[j]]--;
if (j == 0)
break;
}

/* copy back to original array */
for (i = 0; i < size; i++)
array[i] = output[i];

free(count);
free(output);
}
