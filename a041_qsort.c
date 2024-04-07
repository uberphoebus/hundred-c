#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 30

void swap(int v[], int i, int j) {
  int temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

void my_qsort(int v[], int left, int right) {
  int i, last;

  if (left >= right) {
    return;
  }

  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++) {
    if (v[i] < v[left]) {
      swap(v, ++last, i);
    }
  }

  swap(v, left, last);
  my_qsort(v, left, last - 1);
  my_qsort(v, last + 1, right);
}

int compare(const void *a, const void *b) { return *(int *)a - *(int *)b; }

int main() {
  int i;
  int v[MAX];

  srand(time(NULL));
  for (i = 0; i < MAX; i++) {
    v[i] = rand() % 100000;
  }

  for (i = 0; i < MAX; i++) {
    printf("%10d %c", v[i], ((i + 1) % 10 == 0) ? '\n' : ' ');
  }

  // qsort(v, MAX, sizeof(int), compare);
  my_qsort(v, 0, MAX - 1);

  printf("qsort\n");
  for (i = 0; i < MAX; i++) {
    printf("%10d %c", v[i], ((i + 1) % 10 == 0) ? '\n' : ' ');
  }
}