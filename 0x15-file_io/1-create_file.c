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
	int filedata, i, rw_file;

	if (filename == NULL)
		return (-1);

	filedata = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (filedata == -1)
		return (-1);

	if (text_content == NULL)
		text_content = "";

	for (i = 0; text_content[i]; i++)
		;

	rw_file = write(filedata, text_content, i);
	if (rw_file == -1)
		return (-1);

	close(filedata);
	return (1);
}
