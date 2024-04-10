#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int pq[100] = {0};
int count = 0;

void printPQ();
void insert(int x);
int _remove();

int main() {
  int n, d, k;
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("Enter the element: ");
    scanf("%d", &d);
    insert(d);
  }
  printPQ();

  printf("Enter the number of elements to remove: ");
  scanf("%d", &k);
  for (int i = 0; i < k - 1; i++) {
    _remove();
  }
  printf("[%d] Removed: %d\n", k, _remove());
}

void printPQ() {
  for (int i = 0; i < count; i++) {
    printf("%5d ", pq[i]);
  }
  printf("\n");
}

void insert(int x) {
  int i = count;
  pq[count++] = x;

  // up-heap
  while (i > 0) {
    int p = (i - 1) / 2;
    if (pq[p] >= x) {
      break;
    }
    pq[i] = pq[p];
    i = p;
  }
  pq[i] = x;
}

int _remove() {
  int max = pq[0];
  int root = pq[count - 1];
  count--;

  // down-heap
  int i = 0;
  while (i * 2 + 1 < count) {
    pq[i] = root;
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int c;
    if (right < count && pq[right] > pq[left]) {
      c = right;
    } else {
      c = left;
    }

    if (pq[c] > pq[i]) {
      int t = pq[c];
      pq[c] = pq[i];
      pq[i] = t;
      i = c;
    } else {
      break;
    }
  }
  return max;
}