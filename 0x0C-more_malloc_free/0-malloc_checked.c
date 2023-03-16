#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - Allocate memory using malloc.
 * @b: memory block numbers in byte for allocation.
 * Return: alloc_mem pointer after program execution.
 */
void *malloc_checked(unsigned int b)
{
	void *alloc_mem = malloc(b);

	if (alloc_mem == NULL)
		exit(98);

	return (alloc_mem);
}
