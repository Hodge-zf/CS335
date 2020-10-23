#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>


int main(int argc, char *argv[]){

  char *filename = argv[1];
  printf("%s", filename);
  pid_t  pid;
	/* fork another process */

	pid = fork();
	if (pid < 0) { /* error occurred */
		fprintf(stderr, "Fork Failed");
		exit(-1);
	}
	else if (pid == 0) { /* child process */

    execlp("/bin/cat", "cat", filename, NULL);
	}
	else { /* parent process */
		/* parent will wait for the child to complete */
		wait(NULL);
		printf("\nChild Complete\n");
    pid = fork();
    if (pid < 0) { /* error occurred */
      fprintf(stderr, "Fork Failed");
      exit(-1);
    }
    else if (pid == 0) { /* child process */

      execlp("/usr/bin/wc", "wc", filename, NULL);
    }
    else { /* parent process */
      /* parent will wait for the child to complete */
      wait(NULL);
      exit(0);
    }
    exit(0);
       }








}
