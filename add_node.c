#include "monty.h"

/**
 * add_node - add node to the head of the stack
 * @head: pointer to the head of the stack
 * @n: new_value to be stored in the node
 *
 * Return: no return
 */
void add_node(stack_t **head, int n)
{
    /* Declare two pointers to stack nodes, tmp and new_node. */
    stack_t *tmp, *new_node;

    /* Initialize tmp with the current head of the stack. */
    tmp = *head;

    /* Allocate memory for a new stack node. */
    new_node = malloc(sizeof(stack_t));

    /* Check if memory allocation was successful. */
    if (new_node == NULL)
    {
        /* Print an error message and exit. */
        printf("Error\n");
        exit(0);
    }

    /* If tmp is not NULL, set the previous pointer of tmp to new_node. */
    if (tmp)
        tmp->prev = new_node;

    /* Set the data (n), next, and previous pointers of new_node. */
    new_node->n = n;
    new_node->next = *head;
    new_node->prev = NULL;

    /* Update the head of the stack to point to new_node. */
    *head = new_node;
}
