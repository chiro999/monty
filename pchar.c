#include "monty.h"

void _pchar(stack_t **head, unsigned int counter)
{
    stack_t *new_node;

    new_node = *head;
    if (!new_node)
    {
        fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
        fclose(monty.file);
        free(monty.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    if (new_node->n > 127 || new_node->n < 0)
    {
        fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
        fclose(monty.file);
        free(monty.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    printf("%c\n", new_node->n);
}
