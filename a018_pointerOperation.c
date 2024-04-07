#include <stdio.h>

int main() {
  int a = 10;
  int b = 20;
  int c[5] = {1, 2, 3, 4, 5};

  int *pa = &a;
  int *pb = &b;
  int *pc;

  // pointer operation
  // p + i = p + i * sizeof(*p)
  pc = c + 2;
  printf("[%p] pc = %d\n", pc, *pc); // c[2] = 3
  
  pc = pc - 1;
  printf("[%p] pc = %d\n", pc, *pc); // c[1] = 2

  pc = c;
  printf("[%p] pc = %d\n", pc, *pc); // c[0] = 1

  // pointer subtraction
  // p - q = (p - q) / sizeof(*p)
  int *pd = &c[4];
  int cnt = pd - pc;
  printf("[%p] - [%p] = %d\n", pd, pc, cnt); // 4

}