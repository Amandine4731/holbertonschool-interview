#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
* check_cycle - function that checks if a singly linked list has a cycle in it
* @list : pointer to the head oh the singly list
* listint_t : 
* Return: 0 if there is no cycle, 1 if there is a cycle
**/


int check_cycle(listint_t *list) {

    listint_t *slow, *fast;

    if (list == NULL || list->next == NULL) {
        return (0);
    }

    slow = list;
    fast = slow->next;

    while (slow != NULL && fast->next != NULL && fast->next->next != NULL) {
        if (slow == fast) {
            return 1;
        }

        slow = slow->next;
        fast = fast->next->next;
    }
    return (0);
}