// void pointer
// 어떤 형의 주소도 저장할 수 있는 포인터이지만,
// 데이터의 크기를 알 수 없으므로, 간접참조와 포인터 연산이 불가능하다.

#include <stdio.h>

#define INT 0
#define FLOAT 1
#define DOUBLE 2

void *add(void *a, void *b, void *result, int type) {
  switch (type) {
  case INT:
    *(int *)result = *(int *)a + *(int *)b;
    break;
  case FLOAT:
    *(float *)result = *(float *)a + *(float *)b;
    break;
  case DOUBLE:
    *(double *)result = *(double *)a + *(double *)b;
    break;
  }
  return result;
}

int main() {
  int x = 10, y = 20, intResult;
  float f1 = 1.3, f2 = 2.5, floatResult;
  double d1 = 3.4, d2 = 4.5, doubleResult;

  printf("%d\n", *(int *)add(&x, &y, &intResult, INT));
  printf("%f\n", *(float *)add(&f1, &f2, &floatResult, FLOAT));
  printf("%lf\n", *(double *)add(&d1, &d2, &doubleResult, DOUBLE));
}
