#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * create_file - function that create file
 * @filename: file name to be created
 * @text_content: pointer address
 *
 * Return: -1
 */
int create_file(const char *filename, char *text_content)
{
	int i = 0;
	int file;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		text_content = "";

	while (text_content[i] != '\0')
	{
		i++;
	}
	file = open(filename, O_CREATE | O_WRONLY | O_TRUNC, 0600);

	if (file == -1)
		return (-1);

	while (file, text_content, i)
		return (i);
}
