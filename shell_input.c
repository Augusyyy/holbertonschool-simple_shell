#include "shell.h"

/**
 * copy_line - Save the information to buffer from READ.
 * Return: return buffer.
 */
char *copy_line(void)
{
	char arr[2] = {0};
	int buffer_size = 1024;
	char *buffer = malloc(sizeof(char) * buffer_size);
	int buffer_len = 0;

	while (1)
	{
		/*
		 * how long is the arr[]
		 * read (fd , buffer,  size);
		 */
		read(STDIN_FILENO, arr, 1);
		/*
		 * 'return' -> off while
		 */
		if (arr[0] == '\n')
		{
			buffer[buffer_len] = '\0';;
			return (buffer);
		}
		if (arr[0] == EOF)
			break;
		/*
		 * using 'write' output also can using printf
		 */
		if (arr[0] == '\0')
			exit(EXIT_SUCCESS);
		buffer[buffer_len] = arr[0];
		buffer_len++;

		if (buffer_len > buffer_size)
		{
			buffer_size = buffer_size * 2;
			buffer = realloc(buffer, sizeof(char *) * buffer_size);
		}
	}

	buffer[buffer_len] = '\0';

	return (buffer);
}
