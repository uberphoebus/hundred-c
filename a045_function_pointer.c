// 함수 포인터
// int (*func_ptr)(int, int);
// func_ptr = &add;
// int result = (*func_ptr)(10, 20);

#include <stdio.h>

int add(int a, int b) { return a + b; }

void hello() { printf("Hello, World!\n"); }

int main() {
  int (*func_ptr)(int, int) = add;
  void (*hello_ptr)() = hello;

  printf("%d\n", func_ptr(10, 20));
  hello_ptr();
}