#include "monty.h"
/**
 * _sub - subtraction
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void _sub(stack_t **head, unsigned int counter)
{
    stack_t *tmp;
    int difference, node_no;

    tmp = *head;
    for (node_no = 0; tmp != NULL; node_no++)
        tmp = tmp->next;
    if (node_no < 2)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
        fclose(monty.file);
        free(monty.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    tmp = *head;
    difference = tmp->next->n - tmp->n;
    tmp->next->n = difference;
    *head = tmp->next;
    free(tmp);
}
