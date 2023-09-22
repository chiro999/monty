#include "monty.h"

/**
 * free_stack - frees a doubly linked list
 * @head: pointer to the head of the stack
 */
void free_stack(stack_t *head)
{
    /* Declare a temporary pointer to a stack node. */
    stack_t *tmp;

    /* Initialize tmp with the head of the stack. */
    tmp = head;

    /* Start a loop to free each node in the doubly linked list. */
    while (head)
    {
        /* Update tmp to the next node in the list. */
        tmp = head->next;

        /* Free the current node. */
        free(head);

        /* Move head to the next node. */
        head = tmp;
    }
}
