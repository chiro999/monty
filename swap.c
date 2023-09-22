#include "monty.h"

/**
 * _swap - swaps the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 *
 * Return: no return
 */
void _swap(stack_t **head, unsigned int counter)
{
    stack_t *new_node;
    int len = 0, tmp;

    /* Initialize new_node with the current head of the stack. */
    new_node = *head;

    /* Count the number of elements in the stack. */
    while (new_node)
    {
        new_node = new_node->next;
        len++;
    }

    /* Check if there are at least two elements in the stack. */
    if (len < 2)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
        fclose(monty.file);
        free(monty.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    /* Swap the values of the top two elements. */
    new_node = *head;
    tmp = new_node->n;
    new_node->n = new_node->next->n;
    new_node->next->n = tmp;
}
