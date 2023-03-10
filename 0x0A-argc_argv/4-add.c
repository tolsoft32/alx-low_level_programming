#include <stdlib.h>
#include <stdio.h>

/**
 * main -Print addition of positive numbers
 * followed by a new line
 * @argc: The number of arguement passed to the program
 * @argv: An array of pointer to the arguements
 *
 * Return: if one of the number contains symbols that are non digits -1
 * or otherwise - 0
 */
int main(int argc, char *argv[])
{
	int i_positive, x_digit;
	int sum = 0;

	for (i_positive = 1; i_positive < argc; i_positive++)
	{
		for (x_digit = 0; argv[i_positive][x_digit]; x_digit++)
		{
			if (argv[i_positive][x_digit] < '0' || argv[i_positive][x_digit] > '9')
			{
				printf("Error\n");
				return (1);
			}
		}

		sum += atoi(argv[i_positive]);
	}
	printf("%d\n", sum);
	return (0);
}
