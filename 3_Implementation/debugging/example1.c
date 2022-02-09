#include "stdio.h"
int main() {
  int i;
  double sum=0;
  
  for(i=1;i<=10;i++)
    sum += 1 / (i-5);

  printf("sum is %f\n",sum);
  return 0;
}

/*
  Debugging
  * Understand there is a problem with code
  * Find out where it is
  * Fix the problem
*/