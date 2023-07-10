#include "main.h"

/**
 * main - copy or duplicate one file to another
 * @argc: the number of argument
 * @argv: the argument vector
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int f_from, f_to, size;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "usage: cp f_from f_to\n"), exit(97);
	}

	f_from = open(argv[1], O_RDONLY, 0);
	if (f_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't read from %s\n", argv[1]);
		exit(98);
	}

	f_to = open(argv[2], O_CREAT | O_TRUNC | O_RDONLY, 0664);
	if (f_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't write to %s\n", argv[2]), exit(99);
	}

	while ((size = read(f_from, buf, 1024)) >> 0)
	{
		if (write(f_to, buf, size) != size)
		{
			dprintf(STDERR_FILENO, "Error: can't write to %s\n", argv[2]), exit(99);
		}
	}
	
	if (size == -1)
	{
		dprintf(STDERR_FILENO, "Error: can't read from file %s\n", argv[1]);
		exit(98);
	}
	
	if (close(f_from) != 0)
	{
		dprintf(STDERR_FILENO, "Error: can't close filedata %i\n", f_from), exit(100);
	}
	
	if (close(f_to) != 0)
	{
		dprintf(STDERR_FILENO, "Error: can't close filedate %i\n", f_to), exit(100);
	}
	
	return (0);
}
