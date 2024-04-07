// call by value -> 값만 복사해서 넘겨줌
// call by reference -> 주소값을 넘겨줌

#include <stdio.h>

// call by value
void swap(int x, int y) {
  int temp;
  temp = x;
  x = y;
  y = temp;
}

// call by reference
void swap2(int *x, int *y) {
  int temp;
  temp = *x;
  *x = *y;
  *y = temp;
}

int main() {
  int x = 3;
  int y = 4;

  swap(x, y);
  printf("swap()  -> x = %d, y = %d\n", x, y); // x = 3, y = 4

  swap2(&x, &y);
  printf("swap2() -> x = %d, y = %d\n", x, y); // x = 4, y = 3
}