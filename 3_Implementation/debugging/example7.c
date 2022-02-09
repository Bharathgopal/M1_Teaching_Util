#include<stdio.h>

typedef struct {
  int x;
  float y;
  double z;
  char ch;
}sample;

int main(int argc, char* argv[]) {
  struct sample *ps;
  //ps=malloc(sizeof(sample));
  ps->x=10;
  ps->y=2.3f;
  ps->z=5.6;
  ps->ch='A';
  return 0;
}
