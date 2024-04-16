#include "shell.h"


int main(void)
{
	char *buffer;
	char **command;
	char *prompt = "$ ";

	if(isatty(STDIN_FILENO) == 1) /*这个isatty是 判断是运行程序后输入，还是运行之前就有有输入*/
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
		}
	}
	else
	{
		buffer = copy_getchar();
		command = cut_string(buffer);
		shell_execute(command);
	}
}

