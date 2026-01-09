#include "sort.h"

/* swap_nodes - Swaps two nodes in a doubly linked list */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
listint_t *prev1, *next2;

prev1 = node1->prev;
next2 = node2->next;

if (prev1)
prev1->next = node2;
node2->prev = prev1;

node2->next = node1;
node1->prev = node2;

if (next2)
next2->prev = node1;
node1->next = next2;

if (!node2->prev)
*list = node2;
}

/* insertion_sort_list - Sorts a doubly linked list of integers
 in ascending order using the Insertion sort algorithm
 Prints the list after each swap */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *tmp;

if (!list || !*list || !(*list)->next)
return;

current = (*list)->next;
while (current)
{
tmp = current;
while (tmp->prev && tmp->n < tmp->prev->n)
{
swap_nodes(list, tmp->prev, tmp);
print_list(*list);
}
current = current->next;
}
}
