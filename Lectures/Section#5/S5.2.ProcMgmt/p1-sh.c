#include <stdio.h>
#include <unistd.h>

int main()
{
  int i = 1;

  while (1) {
    printf("The ants go marching %d by %d, hurrah, hurrah, \n",
      i, i);
    ++i;
    sleep(1);
  }

  return 0;
}

