#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_extract - Extracts the root node from a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * Return: The value stored in the root node
 */
int heap_extract(heap_t **root)
{
    int value, height, idx, path;
    heap_t *last, *parent, *current, *larger_child;
    
    if (!root || !*root)
        return (0);

    value = (*root)->n;
    last = *root;
    parent = NULL;
    current = *root;
    height = 0;

    /* Calculate height of the heap */
    while (current) {
        height++;
        current = current->left;
    }
    
    /* Find the last node */
    current = *root;
    for (idx = 1, path = 1 << (height - 2); path > 0; path >>= 1) {
        parent = current;
        if (idx & path)
            current = current->right;
        else
            current = current->left;
        idx++;
    }
    last = current;

    /* Replace root with the last node */
    (*root)->n = last->n;
    if (parent && parent->left == last)
        parent->left = NULL;
    else if (parent)
        parent->right = NULL;
    
    /* Free the last node */
    free(last);

    /* Restore the heap property by sifting down */
    current = *root;
    while (current->left) {
        larger_child = current->left;
        if (current->right && current->right->n > current->left->n)
            larger_child = current->right;

        if (current->n >= larger_child->n)
            break;

        int temp = current->n;
        current->n = larger_child->n;
        larger_child->n = temp;

        current = larger_child;
    }

    return (value);
}
