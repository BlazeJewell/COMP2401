#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *printMsg(void*);

int main() 
{
  pthread_t t1, t2, t3;

  pthread_create(&t1, NULL, printMsg, "t1: tic");
  pthread_create(&t2, NULL, printMsg, "t2: tac");
  pthread_create(&t3, NULL, printMsg, "t3: toe");

  pthread_join(t1, NULL);
  printf("\nt1 is back\n");
  pthread_join(t2, NULL);
  printf("t2 is back\n");
  pthread_join(t3, NULL);
  printf("t3 is back\n");

  return(0);
}


void *printMsg(void *str) 
{
  int i;

  for (i=0; i<10; ++i) {
    printf("%s\n", (char *)str);
    sleep(1);
  }
}

