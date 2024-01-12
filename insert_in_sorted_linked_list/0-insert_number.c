#include "lists.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
/**
 * Write a function that inserts a number into a sorted singly linked list.
 * Prototype: listint_t *insert_node(listint_t **head, int number);
 * Return: the address of the new node, or NULL if it failed.
 */


listint_t *insert_node(listint_t **head, int number)
{
    listint_t *new_node, *current;

    if (head == NULL)
        return (NULL);

    new_node = malloc(sizeof(listint_t));
    if (!new_node)
        return (NULL);

    new_node->n = number;
    new_node->next = NULL;

    if (*head == NULL || number < (*head)->n)
    {
        new_node->next = *head;
        *head = new_node;
        return (new_node);
    }

    current = *head;

    while (current->next != NULL && current->next->n < number)
    {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;

    return (new_node);
}