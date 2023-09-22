#include "monty.h"

/**
 * _sub - subtracts the top element of the stack from the second top element
 * @head: stack head
 * @counter: line_number
 *
 * Return: no return
 */
void _sub(stack_t **head, unsigned int counter)
{
    stack_t *tmp;
    int difference, node_no;

    /* Initialize tmp with the current head of the stack. */
    tmp = *head;

    /* Count the number of nodes in the stack. */
    for (node_no = 0; tmp != NULL; node_no++)
        tmp = tmp->next;

    /* Check if there are at least two elements in the stack. */
    if (node_no < 2)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
        fclose(monty.file);
        free(monty.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    /* Update the top element with the result of subtraction. */
    tmp = *head;
    difference = tmp->next->n - tmp->n;
    tmp->next->n = difference;
    *head = tmp->next;
    free(tmp);
}
