#include <stdio.h>
#include "sort.h"

/**
* main - test bubble sort
* Return: 0
*/
int main(void)
{
int array[] = {5, 2, 9, 1, 5, 6};
size_t size = sizeof(array) / sizeof(array[0]);

bubble_sort(array, size);
return (0);
}
