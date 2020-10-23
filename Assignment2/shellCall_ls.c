#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
/* Simple shell program that run ls command
 - Create a child process
 - Parent wait child process to terminate
 - calls the ls command */
int main() {

  char *username;
  username = (char *)malloc(10*sizeof(char));
  username = getlogin();

  time_t now;
  time(&now);

  printf("<%s, %s >",username,ctime(&now));

      pid_t  pid;
	/* fork another process */
	pid = fork();
	if (pid < 0) { /* error occurred */
		fprintf(stderr, "Fork Failed");
		exit(-1);
	}
	else if (pid == 0) { /* child process */
		execlp("/bin/ls", "ls", NULL);
	}
	else { /* parent process */
		/* parent will wait for the child to complete */
		wait (NULL);
		printf ("Child Complete");
		exit(0); 	       }
   }
