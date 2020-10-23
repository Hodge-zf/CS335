#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char command[] = "exec rm -r ";
  char directory[100];

  printf("What is the directory you wish to delete: \n");
  scanf("%s", directory);

  strcat(command,directory);

  system(command);

  return 0;

}
