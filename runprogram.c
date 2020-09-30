#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main()
{
	char path[100];
	char *args[0];

	printf("Enter the file path:\n");
	scanf("%s", &path);

	char *child[] = {"PATH=path", (char*)0};
	execve(args[0], args, child);

	return 0;
}
