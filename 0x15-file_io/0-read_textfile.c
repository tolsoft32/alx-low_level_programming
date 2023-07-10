#include "main.h"

/**
 * read_textfile - function that read a text file
 * print POSIX to the stdout
 * @filename: pointer
 * @letters: size of letters
 * Return: number of letters it can print or write 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t o_file, r_file, w_file;
	char *buf;

	o_file = open(filename, O_RDONLY);
	if (o_file == -1)
		return (0);

	buf = malloc(sizeof(char) * letters);
	r_file = read(o_file, buf, letters);
	w_file = write(STDOUT_FILENO, buf, r_file);

	free(buf);
	close(o_file);
	return (w_file);
}
