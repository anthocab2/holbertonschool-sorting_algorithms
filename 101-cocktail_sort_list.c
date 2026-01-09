#include "sort.h"

/* swap_nodes - swaps two adjacent nodes in a doubly linked list */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
if (left->prev)
left->prev->next = right;
else
*list = right;

if (right->next)
right->next->prev = left;

left->next = right->next;
right->prev = left->prev;
left->prev = right;
right->next = left;
}

/* cocktail_sort_list - sorts a doubly linked list using Cocktail Shaker sort */
void cocktail_sort_list(listint_t **list)
{
int swapped;
listint_t *start, *end, *current;

if (!list || !*list || !(*list)->next)
return;

start = *list;
end = NULL;
swapped = 1;

while (swapped)
{
swapped = 0;
current = start;

while (current->next != end)
{
if (current->n > current->next->n)
{
swap_nodes(list, current, current->next);
print_list(*list);
swapped = 1;
}
else
current = current->next;
}
end = current;

if (!swapped)
break;

swapped = 0;
while (current->prev != start->prev)
{
if (current->prev->n > current->n)
{
swap_nodes(list, current->prev, current);
print_list(*list);
swapped = 1;
}
else
current = current->prev;
}
start = current;
}
}
