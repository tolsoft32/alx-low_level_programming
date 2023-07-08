#include <unistd.h>>

/**
 * _putchar - write characters c to standard output
 * @c: character to print.
 * Return: on success 1
 * On err, -1 is returned and errno apporiately set
 *
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
