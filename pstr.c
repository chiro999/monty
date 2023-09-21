#include "monty.h"

void _pstr(stack_t **head, unsigned int counter)
{
    stack_t *new_node;
    (void)counter;

    new_node = *head;
    while (new_node)
    {
        if (new_node->n > 127 || new_node->n <= 0)
        {
            break;
        }
        printf("%c", new_node->n);
        new_node = new_node->next;
    }
    printf("\n");
}
