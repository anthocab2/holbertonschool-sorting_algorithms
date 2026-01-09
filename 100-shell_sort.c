#include "sort.h"

/* shell_sort - sorts an array of integers in ascending order
   using Shell sort with Knuth sequence */
void shell_sort(int *array, size_t size)
{
size_t gap, i, j;
int temp;

if (!array || size < 2)
return;

/* compute initial gap using Knuth sequence: gap = 1, 4, 13, ... < size */
for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
;

/* start Shell sort */
while (gap > 0)
{
for (i = gap; i < size; i++)
{
temp = array[i];
j = i;
while (j >= gap && array[j - gap] > temp)
{
array[j] = array[j - gap];
j -= gap;
}
array[j] = temp;
}
print_array(array, size);
gap /= 3;
}
}
