#include "monty.h"

/**
 * _pstr - prints the string starting at the top of the stack
 * @head: stack head
 * @counter: not used
 *
 * Return: no return
 */
void _pstr(stack_t **head, unsigned int counter)
{
    stack_t *new_node;

    /* Suppress unused parameter warning for counter. */
    (void)counter;

    /* Initialize new_node with the current head of the stack. */
    new_node = *head;

    /* Iterate through the stack and print characters until a non-printable character is encountered. */
    while (new_node)
    {
        if (new_node->n > 127 || new_node->n <= 0)
        {
            break;
        }
        printf("%c", new_node->n);
        new_node = new_node->next;
    }

    /* Print a newline character to terminate the string. */
    printf("\n");
}

