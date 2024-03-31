#include <stdio.h>

int main() {

  int x = 10, y = 20;
  int z[3] = {1, 2, 3};
  int *p;

  p = &x;      // p = 0x7ffebc4b3a7c
  y = *p;      // y = 10
  *p = *p + y; // *p = 20, x = 20
  p = &z[0];   // p = 0x7ffebc4b3a70
  *p = 30;     // z[0] = 30

  printf("[%p] : %d\n", p, *p);           // [0x7ffebc4b3a70] : 30
  printf("[%p] : %d\n", p + 1, *(p + 1)); // [0x7ffebc4b3a74] : 2
  printf("[%p] : %d\n", p + 2, *(p + 2)); // [0x7ffebc4b3a78] : 3

  int a[3] = {10, 20, 30};
  int *q = a;
  printf("\n[%p] : %d\n", q, *q); // [0x7ffebc4b3a70] : 10
  q = q + 1;
  printf("[%p] : %d\n", q, *q);   // [0x7ffebc4b3a74] : 20

  int *ip;
  char *cp;
  double *dp;
  printf("sizeof(ip) = %d\n", sizeof(ip)); // 8
  printf("sizeof(cp) = %d\n", sizeof(cp)); // 8
  printf("sizeof(dp) = %d\n", sizeof(dp)); // 8

  return 0;
}