#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int pid, ppid, i, count;

  if (argc < 2)
    count = 1;
  else
    count = atoi(argv[1]);

  pid = getpid();
  printf("Parent:  %d\n", pid);

  for (i=0; i<count; ++i) {
    fork();
    fork();
  }

  pid  = getpid();
  ppid = getppid();
  printf("Child %d with parent %d \n", pid, ppid);

  sleep(1);

}

