#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
  char buffer[80]; 
  char *args[3];
  int rc;

  strcpy(buffer, "p3");
  args[0] = "p3";
//  args[1] = "2";
  args[1] = NULL;
  args[2] = NULL;

  printf("Morphing...\n");

  rc = execvp(buffer, args);

  printf("rc = %d \n", rc);

}

