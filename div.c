#include "monty.h"

/**
 * _div - divides the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 *
 * Return: no return
 */
void _div(stack_t **head, unsigned int counter)
{
    /* Declare a pointer to a stack node, new_node, and an integer len. */
    stack_t *new_node;
    int len = 0, tmp;

    /* Initialize new_node with the current head of the stack. */
    new_node = *head;

    /* Start a loop to count the number of elements in the stack. */
    while (new_node)
    {
        /* Move to the next stack element. */
        new_node = new_node->next;

        /* Increment the length counter. */
        len++;
    }

    /* Check if the stack contains fewer than 2 elements. */
    if (len < 2)
    {
        /* Print an error message and exit. */
        fprintf(stderr, "L%d: can't div, stack too short\n", counter);
        fclose(monty.file);
        free(monty.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    /* Reset new_node to the current head of the stack. */
    new_node = *head;

    /* Check if the top element of the stack is 0 (division by zero). */
    if (new_node->n == 0)
    {
        /* Print an error message and exit. */
        fprintf(stderr, "L%d: division by zero\n", counter);
        fclose(monty.file);
        free(monty.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    /* Perform division and update the second element with the result. */
    tmp = new_node->next->n / new_node->n;
    new_node->next->n = tmp;

    /* Move the head to the next element and free the old top element. */
    *head = new_node->next;
    free(new_node);
}
