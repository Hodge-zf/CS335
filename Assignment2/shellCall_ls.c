#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
/* Simple shell program that run ls command
 - Create a child process
 - Parent wait child process to terminate
 - calls the ls command */

int main() {

  char command[25];

  char *username;
  username = (char *)malloc(10*sizeof(char));
  username = getlogin();

  time_t now;
  time(&now);

  printf("<%s, %s>\n",username,ctime(&now));




  pid_t  pid;
	/* fork another process */

	pid = fork();
	if (pid < 0) { /* error occurred */
		fprintf(stderr, "Fork Failed");
		exit(-1);
	}
	else if (pid == 0) { /* child process */
    printf("\nPlease type a Unix command:\n");

    scanf("%s", command);

    if(command == "quit"){

      exit(0);
    }

    char directory[35] = "/usr/bin/";
    strcat(directory,command);

    execlp(directory, command, NULL);
	}
	else { /* parent process */
		/* parent will wait for the child to complete */
		wait(NULL);
		printf("\nChild Complete\n");
    exit(0);
       }
}
