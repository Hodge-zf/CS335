#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int main(char *cmd)
{

	char* argv[1];
	pid_t child1;
	pid_t tpid;
	int child_status;
	
	child1 = fork();
	
	if(child1 == 0){
		execvp(argv[0], argv);

	exit(0);
	}
	
	else{
		do{
			tpid = wait(&child_status);
		} while(tpid != child1);
	}

	return child_status;
	
}
