#include <stdio.h>
#include <unistd.h>

int main()
{
  int rc; 
  int i;

  printf("Forking...\n");

  rc = fork();

  if (rc == 0) {
    printf("fork returned %d, this is the child \n", rc);
    for (i=1; i<=24; ++i) {
      printf("The ants go marching *%2d* by *%2d*, hurrah, hurrah, \n", i, i);
      usleep(500000);
    }
  }
  else {
    printf("fork returned %d, this is the parent \n", rc);
    for (i=1; i<=24; ++i) {
      printf("The ants go marching  %2d  by  %2d , hurrah, hurrah, \n", i, i);
      usleep(1000000);
    }
  }
}

