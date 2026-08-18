#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/**
 * close_fd - closes a file descriptor and handles exit error
 * @fd: file descriptor to be closed
 */
void close_fd(int fd)
{
	int res;

	res = close(fd);
	if (res == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * copy_content - copies data from one file descriptor to another
 * @from_fd: source file descriptor
 * @to_fd: destination file descriptor
 * @from_file: name of the source file
 * @to_file: name of the destination file
 */
void copy_content(int from_fd, int to_fd, char *from_file, char *to_file)
{
	ssize_t bytes_read, bytes_written;
	char buffer[1024];

	while ((bytes_read = read(from_fd, buffer, 1024)) > 0)
	{
		bytes_written = write(to_fd, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", to_file);
			close_fd(from_fd);
			close_fd(to_fd);
			exit(99);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", from_file);
		close_fd(from_fd);
		close_fd(to_fd);
		exit(98);
	}
}

/**
 * main - copies the content of a file to another file
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int from_fd, to_fd;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	from_fd = open(argv[1], O_RDONLY);
	if (from_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	to_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (to_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close_fd(from_fd);
		exit(99);
	}

	copy_content(from_fd, to_fd, argv[1], argv[2]);

	close_fd(from_fd);
	close_fd(to_fd);

	return (0);
}
