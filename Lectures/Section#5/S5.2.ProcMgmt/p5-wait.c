#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
  int status;
  int fave1, fave2;

  printf("Parent:  %d\n", getpid());

  fave1 = fork();

  if (fave1 == 0) {
    fave2 = fork();
    if (fave2 == 0)
      sleep(1);
    else {
      printf("%d spawned %d, waiting...\n", getpid(), fave2);
      waitpid(fave2, &status, 0);
    }
  }
  else {
    printf("%d spawned %d, waiting...\n", getpid(), fave1);
    wait(&status);
  }

  printf("%d terminating \n", getpid());

  sleep(1);

}

