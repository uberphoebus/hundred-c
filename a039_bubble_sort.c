#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 30

void swap(int v[], int i, int j) {
  int temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

void bubble_sort(int v[], int left, int right) {
  for (int i = left; i < right - 1; i++) {
    for (int j = left; j < right - 1 - i; j++) {
      if (v[j] > v[j + 1]) {
        swap(v, j, j + 1);
      }
    }
  }
}

int main() {
  int v[MAX];
  srand(time(NULL));
  for (int i = 0; i < MAX; i++) {
    v[i] = rand() % 100000;
  }

  for (int i = 0; i < MAX; i++) {
    printf("%10d %c", v[i], ((i + 1) % 10 == 0) ? '\n' : ' ');
  }

  bubble_sort(v, 0, MAX);

  printf("bubble_sort\n");
  for (int i = 0; i < MAX; i++) {
    printf("%10d %c", v[i], ((i + 1) % 10 == 0) ? '\n' : ' ');
  }
}