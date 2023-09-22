#include "monty.h"

/**
 * _push - add node to the stack
 * @head: stack head
 * @counter: line_number
 *
 * Return: no return
 */
void _push(stack_t **head, unsigned int counter)
{
    int n, j = 0, not_int = 0;

    /* Check if the argument for push is provided. */
    if (monty.arg)
    {
        /* Check if the argument is a negative number. */
        if (monty.arg[0] == '-')
            j++;

        /* Check if the argument contains non-digit characters. */
        for (; monty.arg[j] != '\0'; j++)
        {
            if (monty.arg[j] > 57 || monty.arg[j] < 48)
                not_int = 1;
        }

        /* If the argument is not an integer, print an error and exit. */
        if (not_int == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", counter);
            fclose(monty.file);
            free(monty.content);
            free_stack(*head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* If no argument is provided, print an error and exit. */
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(monty.file);
        free(monty.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    /* Convert the argument to an integer. */
    n = atoi(monty.arg);

    /* Check if it's a stack (LIFO) or queue (FIFO) operation and add the node accordingly. */
    if (monty.lifi == 0)
        add_node(head, n);
    else
        add_queue(head, n);
}

