#include <stdio.h>
#include <unistd.h> // usleep
#include <ctype.h>  // tolower関数
#include <string.h>
#define MAX_INPUT_LENGTH 5

int main(int argc, char **argv)
{
  char response[MAX_INPUT_LENGTH + 2]; // +2 for newline and null terminator

  
    printf("Do you want to proceed? (y[yes]/n): ");

    if (fgets(response, sizeof(response), stdin) == NULL){
      printf("\nError reading input. Exiting.\n");
      return 1;
    }

    size_t len = strlen(response);
    if (len > 0 && response[len - 1] == '\n'){
      response[len - 1] = '\0';
    }

  if (strcmp(response, "yes") == 0 || strcmp(response, "y") == 0){
    int i, j;
    fprintf(stderr, "\n");
    fprintf(stderr, "0%%       50%%       100%%\n");
    fprintf(stderr, "+---------+---------+\n");

    for (i = 0; i <= 100; i++)
    {
      for (j = 0; j < i / 5 + 1; j++)
      { // make a string composed of 21 consecutive # in the end
        fprintf(stderr, "#");
      }
      fprintf(stderr, "\n");
      fprintf(stderr, "%3d%%\n", i);
      usleep(80000);
      fprintf(stderr, "\x1b[2A");  // this will move up the position of a cursor
      fprintf(stderr, "\x1b[33m"); // changes the color to Yellow
    }
    fprintf(stderr, "\x1b[32m");  // to Green
    fprintf(stderr, "\n\n\nnothing was correctly installed\n");
    fprintf(stderr, "\x1b[0m");
    fprintf(stderr, "(it's a joke program)\n\n");

  }else{
    fprintf(stderr, "\n");
    fprintf(stderr, "operation cancelled\n");
    fprintf(stderr, "I'm sad (;;)\n\n");

  }

  return 0;
}
