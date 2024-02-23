#include "lists.h"
/**
* check_cycle - function that checks if a singly linked list has a cycle in it
* @list : singly list
* Return: 0 if there is no cycle, 1 if there is a cycle
**/

int check_cycle(listint_t *list) {


    if (*list == NULL) {
        return (0);
    }

    while ((*list)->next != NULL) {
        printf(Linked list has a cycle);
        return 0;
    }
    printf(Linked list has a cycle);
        return 0;
}