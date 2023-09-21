#include "monty.h"
/**
 * _pall - prints the stack
 * @head: stack head
 * @counter: not used
 * Return: no return
 */
void _pall(stack_t **head, unsigned int counter)
{
    stack_t *new_node; 
    (void)counter;

    new_node = *head;
    if (new_node == NULL)
        return;
    while (new_node)
    {
        printf("%d\n", new_node->n); 
        new_node = new_node->next; 
    }
}
