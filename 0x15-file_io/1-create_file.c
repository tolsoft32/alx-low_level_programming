#include "main.h"

/**
 * create_file - function that create a file
 * @filename: file to be created
 * @text_content: content to be wrtten to the file
 * Return: 1 on success, otherwise -1 on error
 */
int create_file(const char *filename, char *text_content)
{
	int file_d;
	int i;
	int write_f;

	if (filename == NULL)
		return (-1);
	file_d = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);
	if (text_content == NULL)
		text_content = "";

	for (i = 0; text_content[i]; i++)
		;
	write_f = write(file_d, text_content, i);
	if (write_f == -1)
		return (-1);

	close(file_d);
	return (1);
}
