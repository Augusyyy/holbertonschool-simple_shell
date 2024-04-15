#include "shell.h"


char *copy_line(void)
{
	char arr[2] = {0};
	char *buffer = malloc(sizeof(char) * 1204);
	int buffer_len = 0;

	while (1)
	{
		/**
	 	* * how long is the arr[]
		*/
		read(STDIN_FILENO, arr, 1);
		/**
		* 'return' -> off while
		*/
		if (arr[0] == '\n')
			break;
		//using 'write' output also can using printf
		buffer[buffer_len] = arr[0];
		buffer_len++;
	}

	buffer[buffer_len] = '\0';

	return(buffer);

}
