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
	int o_file, w_file, i = 0;

	if (filename == NULL)
	{
		return (-1);
	}
	if (text_content != NULL)
	{
		for  (i = 0; text_content[i])
			i++;
	}
	o_file = open(filename, O_CREATE | O_RDWR | O_TRUNC, 0600);
	w_file = write(o_file, text_content, i);

	if (o_file == -1 || w_file == -1)
		return (-1);

	close(o_file);
	return (1);
}
