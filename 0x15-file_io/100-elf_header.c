#include <stdio.h>

/**
 * main - entry point to program elf file
 * @argc: number of arguments
 * @argv: pointer to array of argument
 *
 * Return: 1 on success, error on failure
 */
int main(int argc, char *argv[])
{
	printf("Number of argument: %d\n", argc);

	for (int i = 0; i < argc; i++)
		printf("Argument %d\n: %s\n", i, argv[i]);

	return 1;
}
