#include "monty.h"

/**
 * _pint - prints the value at the top of the stack
 * @head: stack head
 * @counter: line_number
 *
 * Return: no return
 */
void _pint(stack_t **head, unsigned int counter)
{
    /* Check if the stack is empty. */
    if (*head == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
        fclose(monty.file);
        free(monty.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    /* Print the value at the top of the stack. */
    printf("%d\n", (*head)->n);
}
