#include "shell.h"

/**
 * signal_handler - Prints a new prompt upon a signal.
 * @sig: The signal.
 */
void signal_handler(int sig)
{
	char *new_prompt = "\n$ ";

	(void)sig;
	signal(SIGINT, signal_handler);
	write(STDIN_FILENO, new_prompt, 3);
}

/**
 * main - it is a entrance simple shell.
 * Return: execute result of simple shell.
 */
int main(void)
{
	char *buffer;
	char **command;
	char *prompt = "$ ";

	signal(SIGINT, signal_handler);
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
			if (strcmp(buffer, "exit") == 0)
			{
				break;
			}
			command = cut_string(buffer);
			shell_execute(command);
			free(buffer);
			free(command);
		}
	}
	else
	{
		buffer = copy_line();
		command = cut_string(buffer);
		shell_execute(command);
		free(buffer);
		free(command);
	}

	return (0);
}
