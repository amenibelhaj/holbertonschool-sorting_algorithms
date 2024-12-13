#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: Pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *key, *tmp;

if (list == NULL || *list == NULL || (*list)->next == NULL)
return;

current = (*list)->next;

while (current != NULL)
{
key = current;
while (key->prev != NULL && key->n < key->prev->n)
{
tmp = key->prev;
key->prev = tmp->prev;
tmp->next = key->next;

if (key->next != NULL)
key->next->prev = tmp;

if (tmp->prev != NULL)
tmp->prev->next = key;
else
*list = key;

key->next = tmp;
tmp->prev = key;

print_list(*list);
}
current = current->next;
}
}
