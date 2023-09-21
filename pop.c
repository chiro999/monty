#include "monty.h"

void _pop(stack_t **head, unsigned int counter)
{
    stack_t *new_node;

    if (*head == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
        fclose(monty.file);
        free(monty.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    new_node = *head;
    *head = new_node->next;
    free(new_node);
}
