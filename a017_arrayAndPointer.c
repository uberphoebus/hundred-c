#include <stdio.h>

int add3(int *p) {
  int sum = 0;
  for (int i = 0; i < 3; i++) {
    sum += p[i];
  }
  return sum;
}

int main() {
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int *p;
  p = a;

  // 배열의 이름은 배열의 첫번째 요소의 주소값을 가리킴
  printf("%p %d\n", p, *p);
  printf("%p %d\n", a, *a);
  printf("%p %d\n", &a[0], a[0]);

  for (int i = 0; i < 10; i++) {
    *(p + i) = *(p + i) * 10;
  }

  // p + i = a + i = &a[i]
  // *(p + i) = *(a + i) = a[i] = p[i]
  printf("a[2] = %d\n", a[2]);
  printf("*(p + 2) = %d\n", *(p + 2));
  printf("*(a + 2) = %d\n", *(a + 2));
  
  printf("add3 : %d\n", add3(a));
  p++;
  // a++; // error
  printf("add3 : %d\n", add3(p));
}