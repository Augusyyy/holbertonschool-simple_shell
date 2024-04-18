#include "shell.h"

/**
 * copy_line - Save the information to buffer from READ.
 * @ret: return the read result
 * Return: return buffer.
 */
char *copy_line(int *ret)
{
	char arr[2] = {0};
	int buffer_size = 1024;
	char *buffer = malloc(sizeof(char) * buffer_size);
	int buffer_len = 0;
	ssize_t r_size = 0;

	fflush(STDIN_FILENO);
	while (1)
	{
		r_size = read(STDIN_FILENO, arr, 1);
		if (r_size == 0)
			*ret = -1;
		if (arr[0] == '\n')
		{
			buffer[buffer_len] = '\0';
			return (buffer);
		}
		if (arr[0] == EOF)
			break;

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
