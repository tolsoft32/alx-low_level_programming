#include <unistd.h>

/**
 * _putchar - write the char c to stdout
 * @c: the character to print
 * Return: On success 1
 * On error, -1 and errno is set appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
