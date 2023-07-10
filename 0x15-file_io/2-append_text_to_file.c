#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * append_text_to_file  - create text and append the provided content
 * @filename: filename to be created
 * @text_content: text or content to be appended
 *
 * Return: 1 on success if file exist, -1 if error if fails
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int filedata, i, in rw_file;

	if (filename == NULL)
		return (-1);
	filedata = open(filename, O_WRONLY | O_APPEND);


	if (filedata == -1)
		return (-1);
	if (text_content)
	{
		for (i = 0; text_content[i]; i++)
			;
		rw_file = write(filedata, text_content, i);
		if (rw_file == -1)
			return (-1);
	}
	close(filedata);
	return (1);
}
