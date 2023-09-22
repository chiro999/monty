/* Define the POSIX feature macro. */
#define _POSIX_C_SOURCE 200809L

/* Include the Monty header file. */
#include "monty.h"

/* Define and initialize a global Monty structure. */
monty_t monty = {NULL, NULL, NULL, 0};

/* Main function. */
int main(int argc, char *argv[])
{
    /* Pointer to store line content. */
    char *content;

    /* Pointer to the Monty file. */
    FILE *file;

    /* Initialize the size for getline. */
    size_t size = 0;

    /* Initialize the result of getline. */
    ssize_t read_line = 1;

    /* Initialize the stack pointer. */
    stack_t *stack = NULL;

    /* Initialize a line counter. */
    unsigned int counter = 0;

    /* Check if the correct number of command-line arguments is provided. */
    if (argc != 2)
    {
        /* Print usage message to stderr. */
        fprintf(stderr, "USAGE: monty file\n");

        /* Exit the program with a failure status. */
        exit(EXIT_FAILURE);
    }

    /* Open the Monty file for reading. */
    file = fopen(argv[1], "r");

    /* Store the file pointer in the global Monty structure. */
    monty.file = file;

    /* Check if file opening failed. */
    if (!file)
    {
        /* Print an error message. */
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);

        /* Exit the program with a failure status. */
        exit(EXIT_FAILURE);
    }

    /* Loop to read lines from the file. */
    while (read_line > 0)
    {
        /* Initialize content pointer to NULL. */
        content = NULL;

        /* Read a line from the file. */
        read_line = getline(&content, &size, file);

        /* Store the content in the global Monty structure. */
        monty.content = content;

        /* Increment the line counter. */
        counter++;

        /* Check if a line was successfully read. */
        if (read_line > 0)
        {
            /* Execute the instruction from the line. */
            execute(content, &stack, counter, file);
        }

        /* Free the dynamically allocated line content. */
        free(content);
    }

    /* Free the memory used by the stack. */
    free_stack(stack);

    /* Close the Monty file. */
    fclose(file);

    /* Exit the program with a success status. */
    return (0);
}
