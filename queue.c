#include "monty.h"

/**
 * _queue - sets the data structure to a queue (FIFO)
 * @head: stack head
 * @counter: line_number
 *
 * Return: no return
 */
void _queue(stack_t **head, unsigned int counter)
{
    /* Suppress unused parameter warnings. */
    (void)head;
    (void)counter;

    /* Set the data structure to a queue (FIFO). */
    monty.ds = 1;
}

/**
 * add_queue - add node to the tail of the stack (queue)
 * @n: new_value
 * @head: head of the stack
 *
 * Return: no return
 */
void add_queue(stack_t **head, int n)
{
    stack_t *new_node, *tmp;

    /* Initialize tmp with the current head of the stack. */
    tmp = *head;

    /* Allocate memory for a new node. */
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        printf("Error\n"); /* Print an error message if memory allocation fails. */
    }

    /* Set the value and next pointer for the new node. */
    new_node->n = n;
    new_node->next = NULL;

    /* Check if the stack is empty. */
    if (tmp)
    {
        /* If not empty, traverse the stack to find the last node (tail). */
        while (tmp->next)
            tmp = tmp->next;
    }

    /* Update the pointers to add the new node to the tail of the stack. */
    if (!tmp)
    {
        *head = new_node;
        new_node->prev = NULL;
    }
    else
    {
        tmp->next = new_node;
        new_node->prev = tmp;
    }
}

