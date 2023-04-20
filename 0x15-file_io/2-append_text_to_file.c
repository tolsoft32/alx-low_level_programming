#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * append_text_to_file - function that append text at the end of a file
 * @filename: name of the file
 * @text_content: text to append to the file
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, f_written, length = 0;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[length])
			length++;

		f_written = write(fd, text_content, length);
		if (f_written == -1 || f_written != length)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
