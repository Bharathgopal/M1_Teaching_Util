#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int maxlen = 20;

typedef struct {
  int empid;
  char ename[20];
  double esalary;
  int eage;    
}employee;

employee* create(int id, char* name, double sal, int age) {
  int namelen = strlen(name);
  int len = namelen > maxlen ? maxlen : namelen;
  employee *ptr = malloc(sizeof(employee));
  ptr->empid=id;
  strncpy(ptr->ename, name, 20);     //what if namelen > 20
  ptr->esalary=200;
  ptr->eage=age;
}
void display(const employee *pc) {
  //print pc->empid, pc->ename, pc->esalary, pc->eage
}
void release(employee *ptr) {
  free(ptr);
}
int main(int argc, char* argv[]) {
  employee *ps;
  ps = create(1001, "Richard", 5000, 20);
  display(ps);
  release(ps);  
  return 0;
}
