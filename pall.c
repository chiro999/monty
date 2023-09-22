#include "monty.h"

/**
 * _pall - prints the stack
 * @head: stack head
 * @counter: not used
 *
 * Return: no return
 */
void _pall(stack_t **head, unsigned int counter)
{
    stack_t *new_node;
    
    /* Suppress unused parameter warning for counter. */
    (void)counter;

    /* Initialize new_node with the current head of the stack. */
    new_node = *head;

    /* Check if the stack is empty. */
    if (new_node == NULL)
        return;

    /* Iterate through the stack and print each element. */
    while (new_node)
    {
        printf("%d\n", new_node->n);
        new_node = new_node->next;
    }
}
