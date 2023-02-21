#include <stdio.h>
/**
 * main - Entry point
 * success - return (0) if program runs well
 */
int main(void)
{
	char *ch = "_putchar";

	while (*ch)
	{
		putchar(*ch);
		ch++;
	}
	putchar('\n');

	return (0);
}
