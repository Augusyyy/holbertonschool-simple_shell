#include "shell.h"


int main(void)
{
	char *buffer;
	char **command;
	char *prompt = "$ ";

	while(2)
	{
		write(STDOUT_FILENO,prompt,2);
		buffer = copy_line();
		if (strcmp(buffer, "exit") == 0)
		{
			break;
		}
		command = cut_string(buffer);

		shell_execute(command);
	}
}

