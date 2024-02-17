#include <stdio.h>

int main() {
  int a[10] = {45, 66, 78, 24, 59, 64, 33, 75, 18, 50};
  int min, max;
  int sum = 0;

  min = a[0];
  max = a[0];

  for (int i = 0; i < 10; i++) {
    sum += a[i];
    if (a[i] < min) {
      min = a[i];
    } else if (a[i] > max) {
      max = a[i];
    }
  }

  printf("min %d | max %d | avg %.2f\n", min, max, sum/10.0);

  return 0;
}