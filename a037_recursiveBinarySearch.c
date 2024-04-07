#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000
#define CNT 1000

void printArr(int a[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%c%6d", (i % 20 == 0) ? '\n' : ' ', a[i]);
  }
  printf("\n");
}

int compare(const void *p, const void *q) { return *(int *)p - *(int *)q; }

int bSearch(int a[], int low, int high, int key) {
  if (low <= high) {
    int mid = (low + high) / 2;
    if (key == a[mid]) {
      return mid;
    } else if (key > a[mid]) {
      return bSearch(a, mid + 1, high, key);
    } else {
      return bSearch(a, low, mid - 1, key);
    }
  }
  return -1;
}

int main() {
  int a[CNT];
  int value, index;

  srand(time(NULL));
  for (int i = 0; i < CNT; i++) {
    a[i] = rand() % MAX;
  }

  qsort(a, CNT, sizeof(int), compare);
  printArr(a, CNT);

  printf("Enter a value to search: ");
  scanf("%d", &value);

  if ((index = bSearch(a, 0, CNT - 1, value)) != -1) {
    printf("Found at index %d\n", index);
  } else {
    printf("Not found\n");
  }
}