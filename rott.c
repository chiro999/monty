#include "monty.h"

/**
 * _rott - rotates the stack to the top
 * @head: stack head
 * @counter: line_number (unused)
 *
 * Return: no return
 */
void _rott(stack_t **head, __attribute__((unused)) unsigned int counter)
{
    stack_t *tmp = *head, *aux;

    /* Check if the stack is empty or has only one element. */
    if (*head == NULL || (*head)->next == NULL)
    {
        return; /* Nothing to rotate. */
    }

    /* Get the second element as aux. */
    aux = (*head)->next;
    aux->prev = NULL;

    /* Traverse the stack to find the last element. */
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    /* Update the pointers to rotate the stack. */
    tmp->next = *head;
    (*head)->next = NULL;
    (*head)->prev = tmp;
    (*head) = aux;
}

