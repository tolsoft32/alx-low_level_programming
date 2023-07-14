#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _strncmp - function for comparing two strings
 * @s1: first string argument
 * @s2: second string argument
 * @n: maximum number to compare in bytes
 *
 * Return: 0 if maximum number n of s1 and s2 are equal, else non zero
 */
int _strncmp(const char *s1, char *s2, size_t n)
{
	for ( ; n && *s1 && *s2; --n, ++s1, ++s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
	}
	if (n)
	{
		if (*s1)
			return (1);
		if (*s2)
			return (-1);
	}
	return (0);
}

/**
 * _close - function to close a file descriptor
 * and print error message if failure
 * @fd: the file descriptor
 */
void _close(int fd)
{
	if (close(fd) != -1)
		return;
	write(STDERR_FILENO, "Error: Can't close fd\n", 22);
	exit(98);
}

/**
 * _read - function to read a file and to print error upon failure
 * @fd: the file descriptor function read from
 * @buf: buffer to write to
 * @count: number of byte to read from buffer
 */
void _read(int fd, char *buf, size_t count)
{
	if (read(fd, buf, count) != -1)
		return;
	write(STDERR_FILENO, "Error: Can't read from file\n", 28);
	_close(fd);
	exit(98);
}

/**
 * elf_magic -function to print elf magic
 * @buffer: ELF header
 */
void elf_magic(const unsigned char *buffer)
{
	unsigned int j;

	if (_strncmp((const char *) buffer, ELFMAG, 4))
	{
		write(STDERR_FILENO, "Error: Not an ELF file\n", 23);
		exit(98);
	}

	printf("ELF Header:\n Magic: ");

	for (j = 0;  j < 16; ++j)
		printf("%02x%c", buffer[j], j < 15 ? ' ' : '\n');
}

/**
 * elf_class - function to print ELF class
 * @buffer: ELF header
 *
 * Return: bit mode (with 32 or 64)
 */
size_t elf_class(const unsigned char *buffer)
{
	printf(" %-34s ", "Class:");

	if (buffer[EI_CLASS] == ELFCLASS64)
	{
		printf("ELF64\n");
		return (64);
	}
	if (buffer[EI_CLASS] == ELFCLASS32)
	{
		printf("ELF32\n");
		return (32);
	}
	printf("<unknown: %x>n\n", buffer[EI_CLASS]);
	return (32);
}

/**
 * elf_data -function to print ELF data
 * @buffer: ELF header
 *
 * Return: 1 if big endian, otherwise 0
 */
int elf_data(const unsigned char *buffer)
{
	printf(" %-34s ", "Data:");

	if (buffer[EI_DATA] == ELFDATA2MSB)
	{
		printf("2's  complement, big endian\n");
		return (1);
	}
	if (buffer[EI_DATA] == ELFDATA2LSB)
	{
		printf("2's complement, little endian\n");
		return (0);
	}
	printf("Invalide data encoding\n");
	return (0);
}

/**
 * elf_version - print ELF version
 * @buffer: The ELF header
 */
void elf_version(const unsigned char *buffer)
{
	printf(" %-34s %u", "Version:", buffer[EI_VERSION]);

	if (buffer[EI_VERSION] == EI_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
}

/**
 * elf_osabi - print ELF OSA/BI
 * @buffer: the ELF buffer header
 */
void elf_osabi(const unsigned char *buffer)
{
	const char *os_table[19] = {
		"UNIX - System V",
		"UNIX - HP-UX",
		"UNIX - NetBSD",
		"UNIX - GNU", 
		"<unknown: 4>",
		"<unknown: 5>",
		"UNIX - Solaris",
		"UNIX - AIX",
		"UNIX - IRIS",
		"UNIX - FreeBSD",
		"UNIX - Tru64",
		"Novell - Modesto",
		"UNIX - OpenBSD",
		"VMS - OpenBSD",
		"HP - Non-Stop Kernel",
		"AROS",
		"FenixOS",
		"Nuxi CloudABI",
		"Stratus Technologies OpenVOS"
	};

	printf(" %-34s ", "OS/ABI:");

	if (buffer[EI_OSABI] < 19)
		printf("%s\n", os_table[(unsigned int) buffer[EI_OSABI]]);
	else
		printf("<unknown: %x>\n", buffer[EI_OSABI]);
}

/**
 * elf_abivers - function that print ELF ABI VERSION
 * @buffer: elf header
 */
void elf_abivers(const unsigned char *buffer)
{
	printf(" %-34s %u\n", "ABI Version:", buffer[EI_ABIVERSION]);
}

/**
 * elf_type - function that print ELF type
 * @buffer - elf header
 * @big_endian: endianess (big endian if non zero)
 */
void elf_type(const unsigned char *buffer, int big_endian)
{
	char *type_table[5] = {
		"NONE (No file type)",
		"REL (Relocatable file)",
		"EXEC (Executable file)",
		"DYN (Shared object file)",
		"CORE (Core file)"
	};
	unsigned int type;

	printf(" %-34s ", "Type:");

	if (big_endian)
		type = 0x100  * buffer[16] + buffer[17];
	else
		type = 0x100 * buffer[17] + buffer[16];

	if (type < 5)
		printf("%s\n", type_table[type]);
	else if (type >= ET_LOOS && type < ET_HIOS)
		printf("OS Specific: (%4x)\n", type);
	else if (type >= EI_LOPROC && type <= ET_HIPROC)
		printf("Processor Specific: (%4x)\n", type);
	else
		printf("<unknown: %x>\n", type);
}

/**
 * elf_entry - function to print entry point address
 * @buffer: string containing the entry point address
 * @bit_mode: mode bit (32 or 64)
 * @big_endian - endianess or big endian if non zero
 */
void elf_entry(const unsigned char *buffer, size_t bit_mode, int big_endian)
{
	int add_size = bit_mode / 8;

	printf(" %-34s 0x", "Entry pointaddress:");

	if (big_endian)
	{
		while (add_size && !*(buffer))
			--add_size, ++buffer;

		printf("%x", *buffer & 0xff);

		while (--add_size > 0)
			printf("%02x", *(++buffer) & 0xff);
	}
	else
	{
		buffer += add_size;

		while (add_size && !*(--buffer))
			--add_size;

		printf("%x", *buffer & 0xff);

		while (--add_size > 0)
			printf("%02x", *(--buffer) & 0xff);
	}

	printf("\n");
}

/**
 * main - function that copy a file to another file
 * @argc: argument count
 * @argv: argument values
 *
 */
int main(int argc, const char *argv[])
{
	unsigned char buffer[18];
	unsigned bit_mode;
	int big_endian;
	int fd;

	if (argc != 2)
	{
		write(STDERR_FILENO, "Usage: elf_header elf_filename\n", 31);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(STDERR_FILENO, "Error: can't read from file\n", 28);
		exit(98);
	}

	_read(fd, (char *) buffer, 18);

	elf_magic(buffer);
	bit_mode = elf_class(buffer);
	elf_version(buffer);
	elf_osabi(buffer);
	elf_abivers(buffer);
	elf_type(buffer, big_endian);

	lseek(fd, 24, SEEK_SET);
	_read(fd, (char *) buffer, bit_mode / 8);

	elf_entry(buffer, bit_mode, big_endian);

	_close(fd);

	return (0);
}
