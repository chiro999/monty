#include "monty.h"

/**
 * _pop - removes the top element of the stack
 * @head: stack head
 * @counter: line_number
 *
 * Return: no return
 */
void _pop(stack_t **head, unsigned int counter)
{
    stack_t *new_node;

    /* Check if the stack is empty. */
    if (*head == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
        fclose(monty.file);
        free(monty.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    /* Remove the top element of the stack. */
    new_node = *head;
    *head = new_node->next;
    free(new_node);
}
