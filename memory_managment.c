#include "shell.h"

/**
 * allocate_memory - Allocate memory with error checking
 * @size: The size of memory to allocate
 *
 * Return: A pointer to the allocated memory
 */
void *allocate_memory(size_t size)
{
    void *ptr = malloc(size);

    if (ptr == NULL)
    {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    return ptr;
}

