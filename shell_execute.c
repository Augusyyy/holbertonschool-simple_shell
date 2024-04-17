#include "shell.h"

/**
 * shell_execute - Bring the parsed buffer into execution.
 * @command: command stores the value of the array.
 * Return: return the command.
 */
void shell_execute(char **command)
{
	/*用于存储进程ID*/
	pid_t pid;

	/*创建子进程*/
	pid = fork();
	if (pid < 0)
	{
		/*fork失败*/
		perror("fork failed");
	}
	else if (pid == 0)
	{
		/*子进程在子进程中执行ls命令 使用execvp执行命令*/
		execvp(command[0], command);
		/*如果execvp失败，打印错误信息*/
		perror("execvp failed");
		/*退出子进程*/
		exit(EXIT_FAILURE);
	}
	else
	{
		/*
		 * 父进程在父进程中等待子进程结束可以选
		 * 择等待子进程退出状态或其他操作...
		 */
		wait(NULL);
	}
}
