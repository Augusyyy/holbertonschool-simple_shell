#include "shell.h"



char **cut_string(char *buffer)
{
	int token_buffer_size = 64;
	char **command = malloc(token_buffer_size * sizeof(char *));
	char *token;
	int index = 0;

	/* get the son's srting */
	token = strtok(buffer, " ");
	command[index++] = token;

	/* 继续获取其他的子字符串 */
	while (token != NULL)
	{
		/*继续获取token*/
		token = strtok(NULL, " ");
		command[index++] = token;
		if(index > token_buffer_size)
		{
			token_buffer_size = token_buffer_size * 2;
			command = realloc(command,sizeof (char *) * token_buffer_size);
		}
	}

	return (command);
}
