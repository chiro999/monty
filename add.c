#include "monty.h"

/** 
 * _add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 *
 * Return: no return
 */
void _add(stack_t **head, unsigned int counter)
{
    /* Declare a pointer to a stack node. */
    stack_t *new_node;
    
    /* Declare integer variables len and temp. Initialize len to 0. */
    int len = 0, temp;

    /* Initialize new_node with the current stack head. */
    new_node = *head;

    /* Start a loop to count the number of elements in the stack. */
    while (new_node != NULL)
    {
        /* Move to the next stack element. */
        new_node = new_node->next;

        /* Increment the length counter. */
        len++;
    }

    /* Check if the stack contains fewer than 2 elements. */
    if (len < 2)
    {
        /* Print an error message. */
        fprintf(stderr, "L%d: can't add, stack too short\n", counter);

        /* Close the Monty file. */
        fclose(monty.file);

        /* Free dynamically allocated content. */
        free(monty.content);

        /* Free the stack memory. */
        free_stack(*head);

        /* Exit the program with a failure status. */
        exit(EXIT_FAILURE);
    }

    /* Reset new_node to the current stack head. */
    new_node = *head;

    /* Calculate the sum of the top two elements. */
    temp = new_node->n + new_node->next->n;

    /* Update the second element with the sum. */
    new_node->next->n = temp;

    /* Move the head to the next element. */
    *head = new_node->next;

    /* Free the old top element of the stack. */
    free(new_node);
}
