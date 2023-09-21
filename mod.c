#include "monty.h"
/**
 * _mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void _mod(stack_t **head, unsigned int counter)
{
	stack_t *new_node;
	int len = 0, tmp;

	new_node = *head;
	while (new_node)
	{
		new_node = new_node->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(monty.file);
		free(monty.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	new_node = *head;
	if (new_node->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(monty.file);
		free(monty.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = new_node->next->n % new_node->n;
	new_node->next->n = tmp;
	*head = new_node->next;
	free(new_node);
}
