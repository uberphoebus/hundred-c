#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000
#define CNT 1000

int binarySearch(int a[], int n, int v);
int swap(int v[], int i, int j);
void sort(int a[], int left, int right);
void printArr(int a[], int n);

int main() {
  int a[CNT];
  int value, index;

  srand(time(NULL));
  for (int i = 0; i < CNT; i++) {
    a[i] = rand() % MAX;
  }

  sort(a, 0, CNT);
  printArr(a, CNT);

  printf("Enter a value to search: ");
  scanf("%d", &value);

  if ((index = binarySearch(a, CNT, value)) != -1) {
    printf("Found at index %d\n", index);
  } else {
    printf("Not found\n");
  }
}

int swap(int v[], int i, int j) {
  int temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

void sort(int v[], int left, int right) {
  for (int i = left; i < right; i++) {
    for (int j = 0; j < right - 1; j++) {
      if (v[j] > v[j + 1]) {
        swap(v, j, j + 1);
      }
    }
  }
}

int binarySearch(int a[], int n, int v) {
  int low = 0, high = n - 1, mid;
  while (low <= high) {
    mid = (low + high) / 2;
    if (a[mid] == v) {
      return mid;
    } else if (a[mid] < v) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return -1;
}

void printArr(int a[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%c%6d", (i % 20 == 0) ? '\n' : ' ', a[i]);
  }
  printf("\n");
}