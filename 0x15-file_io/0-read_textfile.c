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
	int read_f;
	char *buffs = malloc(sizeof(char *) * letters);

	if (!buffs)
		return (0);

	if (!filename)
		return (0);

	file_d = open(filename, O_RDONLY, 0600);
	if (file_d == -1)
		return (0);

	read_f = read(file_d, buffs, letters);
	write(STDOUT_FILENO, buffs, read_f);

	free(buffs);
	close(file_d);
	return (read_f);
}
