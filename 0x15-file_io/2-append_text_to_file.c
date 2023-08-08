#include "main.h"

/**
 * append_text_to_file - function that append text to file
 * @filename: the file name to append
 * @text_content: content or text to add
 * Return: 1 if file exist, -1 if fails.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_d, i, read_w;

	if (filename == NULL)
		return (-1);
	file_d = open(filename, O_WRONLY | O_APPEND);

	if (file_d == -1)
		return (-1);
	if (text_content)
	{
		for (i = 0; text_content[i]; i++)
			;
		read_w = write(file_d, text_content, i);
		if (read_w == -1)
			return (-1);
	}
	close(file_d);
	return (1);
}
