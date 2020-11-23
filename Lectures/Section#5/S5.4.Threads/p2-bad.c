#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *threadFunc(void*);

volatile int count = 0;


int main(int argc, char *argv[]) 
{
  int numInc;
  pthread_t t1, t2;

  if (argc < 2) 
    numInc = 100000000;
  else
    numInc = atoi(argv[1]);

  pthread_create(&t1, NULL, threadFunc, &numInc);
  pthread_create(&t2, NULL, threadFunc, &numInc);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);

  if (count != (2 * numInc)) {
    printf("Bad news!  count is %d\n", count);
  }
  else
    printf("Good news!  count is %d\n", count);

  return(0);
}


void *threadFunc(void *arg) 
{
  int i, inc= *((int *)arg);

  for (i = 0; i < inc; ++i)
    ++count;

  return(0);
}

