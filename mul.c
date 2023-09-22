#include "monty.h"

/**
 * _mul - multiplies the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 *
 * Return: no return
 */
void _mul(stack_t **head, unsigned int counter)
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

    /* Check if the stack contains fewer than 2 elements. */
    if (len < 2)
    {
        fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
        fclose(monty.file);
        free(monty.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    /* Reset new_node to the current head of the stack. */
    new_node = *head;

    /* Perform multiplication and update the second element with the result. */
    tmp = new_node->next->n * new_node->n;
    new_node->next->n = tmp;

    /* Move the head to the next element and free the old top element. */
    *head = new_node->next;
    free(new_node);
}
