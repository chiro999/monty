#include "monty.h"

/**
 * _pchar - prints the character at the top of the stack
 * @head: stack head
 * @counter: line_number
 *
 * Return: no return
 */
void _pchar(stack_t **head, unsigned int counter)
{
    stack_t *new_node;

    /* Initialize new_node with the current head of the stack. */
    new_node = *head;

    /* Check if the stack is empty. */
    if (!new_node)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
        fclose(monty.file);
        free(monty.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    /* Check if the value at the top of the stack is out of the ASCII range. */
    if (new_node->n > 127 || new_node->n < 0)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
        fclose(monty.file);
        free(monty.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    /* Print the character at the top of the stack. */
    printf("%c\n", new_node->n);
}
