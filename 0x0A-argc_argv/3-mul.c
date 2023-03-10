#include <stdlib.h>
#include <stdio.h>

/**
 * main - Prints the multiplication of two numbers, followed by a new line.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: If the program receives two arguments - 0.
 *         If the program does not receive two arguments - 1.
 */
int main(int argc, char *argv[])
{
	int num_x, num_y, num_prod;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	num_x = atoi(argv[1]);
	num_y = atoi(argv[2]);
	num_prod = num_x * num_y;

	printf("%d\n", num_prod);

	return (0);
}
