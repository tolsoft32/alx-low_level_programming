#include "main.h"

/**
 * read_textfile - function that read a text file
 * @filename: source of the file
 * @letters: number of letters to read and to print
 * Return: 0 if file name is NULL, can't be read
 * or when can't write into file
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_d;
	ssize_t read_f, write_f;
	char *buffs;

	if (filename == NULL)
	{
		return (0);
	}

	file_d = open(filename, O_RDONLY);
	if (file_d == -1)
	{
		return (0);
	}
	buffs = malloc(sizeof(char) * letters + 1);

	read_f = read(file_d, buffs, letters);
	write_f = write(STDOUT_FILENO, buffs, read_f);

	if (read_f == -1 || write_f == -1)
	{
		return (0);
	}

	close(file_d);
	free(buffs);
	return (write_f);
}
