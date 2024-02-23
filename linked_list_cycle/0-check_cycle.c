#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
* check_cycle - function that checks if a singly linked list has a cycle in it
* @list: singly list
* @listint_t: singly list
* Return: 0 if there is no cycle, 1 if there is a cycle
**/


int check_cycle(listint_t *list) {

    if (list == NULL || list->next == NULL) {
        return 0;
    }

    listint_t slow = list;
    listint_t fast = list->next;

    while (fast != NULL && fast->next != NULL) {
        if (slow == fast) {
            return 1;
        }

        slow = slow->next;
        fast = fast->next->next;
    }
    return 0;
}