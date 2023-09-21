#include "monty.h"
monty_t monty = {NULL, NULL, NULL, 0}; // Change 'bus_t' to 'monty_t'

int main(int argc, char *argv[])
{
    char *content;
    FILE *file;
    size_t size = 0;
    ssize_t read_line = 1;
    stack_t *stack = NULL;
    unsigned int counter = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");
    monty.file = file; // Change 'bus.file' to 'monty.file'
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while (read_line > 0)
    {
        content = NULL;
        read_line = getline(&content, &size, file);
        monty.content = content; // Change 'bus.content' to 'monty.content'
        counter++;
        if (read_line > 0)
        {
            execute(content, &stack, counter, file);
        }
        free(content);
    }
    free_stack(stack);
    fclose(file);
    return (0);
}
