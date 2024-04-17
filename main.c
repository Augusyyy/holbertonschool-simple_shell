#include "shell.h"

/**
 * main - it is a entrance simple shell.
 * Return: execute result of simple shell.
 */
int main(void)
{
	char *buffer;
	char **command;
	char *prompt = "$ ";

	/*
	 * 这个isatty是 判断是运行程序后输入，
	 * 还是运行之前就有有输入
	 */
	if (isatty(STDIN_FILENO) == 1)
	{
		while (2)
		{
			write(STDOUT_FILENO, prompt, 2);
			buffer = copy_line();
			if (strcmp(buffer, "exit") == 0 || strcmp(buffer, "^D") == 0)
			{
				break;
			}
			command = cut_string(buffer);

			shell_execute(command);
		}
	}
	else
	{
		buffer = copy_getchar();
		command = cut_string(buffer);
		shell_execute(command);
	}
}

