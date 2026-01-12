#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/* Doubly linked list node */
typedef struct listint_s
{
    int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/* Function prototypes */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sorting algorithms prototypes */
void bubble_sort(int *array, size_t size);
void insertion_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);

#endif /* SORT_H */
