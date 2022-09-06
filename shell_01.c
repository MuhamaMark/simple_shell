#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	char *lineptr = NULL;
	ssize_t n =0;
	char *token;
	pid_t pid;
	struct stat st;
	int status;
	
	do
	{
		printf("$ ");
		if (getline(&lineptr, &n, stdin) == -1)
		{
			if (feof(stdin))
			{
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("readline_Error");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(lineptr, " \t\n\r");
		printf("%s\n", token);

		if (stat(token, &st) ==0)
		{
			printf("FOUND\n");
			pid = fork();
			if (pid == -1)
			{
				perror("fork failed");
				return 1;
			}
			else if (pid == 0)
			{
				if (execve(token, argv, NULL))
				{
					perror("execve:");
					exit(EXIT_FAILURE);
				}
			}
			else
				wait(&status);
		}
		else
			printf("NOT FOUND\n");
	}
	while (1);
	putchar('\n');
	free(lineptr);
	return 0;
}
