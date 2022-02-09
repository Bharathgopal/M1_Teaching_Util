#include<stdio.h>

const int maxlen = 20;

typedef struct {
  int empid;
  char ename[20];
  double esalary;
  int eage;    
}employee;

int main(int argc, char* argv[]) {
  employee_t *ps;
  ps = create(1001, "Richard", 5000, 20);
  display(ps);
  release(ps);  
  return 0;
}
employee* create(int id, char* name, double sal, int age) {
  int namelen = strlen(name);
  int len = namelen > maxlen ? maxlen : namelen;
  employee *ptr = malloc(sizeof(employee));
  ptr->empid=id;
  strncpy(ptr->ename, name);     //what if namelen > 20
  ptr->esalary=salary;
  ptr->eage=age;
}
void display(const employee *pc) {
  //print pc->empid, pc->ename, pc->esalary, pc->eage
}
void release(employee *ptr) {
  free(ptr);
}
