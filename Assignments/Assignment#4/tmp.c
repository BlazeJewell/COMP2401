#include <stdio.h>
#include <stdlib.h>

int randm(int max)
{
  double r = ( (double)rand() / ((double)(RAND_MAX)+(double)(1)) ); 
  return (int)(r * max);
}


int main(){
    int tmp = randm(4);
    printf("%d\n", tmp);
}

