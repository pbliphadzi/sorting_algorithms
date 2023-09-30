#include "sort.h"

void insertion_sort_list(listint_t **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    listint_t *current = (*list)->next;
    listint_t *head = *list;

    while (current != NULL)
    {
        listint_t *inner_current = current;

        while (inner_current->prev != NULL && inner_current->n < inner_current->prev->n)
        {
            listint_t *prev_node = inner_current->prev;
            inner_current->prev = prev_node->prev;
            prev_node->next = inner_current->next;

            if (inner_current->next != NULL)
                inner_current->next->prev = prev_node;

            inner_current->next = prev_node;
            prev_node->prev = inner_current;

            if (inner_current->prev != NULL)
                inner_current->prev->next = inner_current;
            else
                head = inner_current;
        }

        current = current->next;
    }

    *list = head;
}
