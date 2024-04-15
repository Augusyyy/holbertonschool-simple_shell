#include "shell.h"


void shell_execute(char **command)
{
	pid_t pid; // 用于存储进程ID

	// 创建子进程
	pid = fork();
	if (pid < 0)
	{ // fork失败
		perror("fork failed");
	}
	else if (pid == 0)
	{ // 子进程
		// 在子进程中执行ls命令
		execvp(command[0], command); // 使用execvp执行命令
		perror("execvp failed"); // 如果execvp失败，打印错误信息
		exit(EXIT_FAILURE); // 退出子进程
	}
	else
	{ // 父进程
		// 在父进程中等待子进程结束
		wait(NULL); // 可以选择等待子进程退出状态或其他操作...
	}
}
