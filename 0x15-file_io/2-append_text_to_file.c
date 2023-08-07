#include "main.h"

/**
 * append_text_to_file - function that append text to file
 * @filename: the file name to append
 * @text_content: content or text to add
 * Return: 1 if file exist, -1 if fails.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_d;

	if (!filename)
		return (-1);

	file_d = open(filename, O_WRONLY, O_APPEND);
	if (file_d == -1)
		return (-1);

	if (text_content)
	{
		if (write(file_d, _strlens(text_content)) == -1)
			return (-1);
	}

	close(file_d);
	return (1);
}

/**
 * _strlens - function to return length of strings
 * @s: counting strings
 * Return: string length
 */
int _strlens(char *s)
{
	int count;

	while (s[count])
		count++;

	return (count);
}
