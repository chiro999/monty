#include "monty.h"
/**
 * _add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void _add(stack_t **head, unsigned int counter)
{
	stack_t *new_node;
	int len = 0, temp;

	new_node = *head;
	while (new_node != NULL)
	{
		new_node = new_node->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(monty.file);
		free(monty.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	new_node = *head;
	temp = new_node->n + new_node->next->n;
	new_node->next->n = temp;
	*head = new_node->next;
	free(new_node);
}
