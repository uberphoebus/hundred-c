// 037 qsort 재귀 이진탐색
// qsort로 정렬 -> 재귀 이진탐색

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 10000
#define CNT 100

void printArr(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%c%6d", (i % 10 == 0) ? '\n' : ' ', a[i]);
    }
}

int compare(const void *p, const void *q) {
    // 오름차순 정렬
    return *(int *)p - *(int *)q;
}

int bSearch(int a[], int low, int high, int key) {
    if (low <= high) {              // low가 high보다 작거나 같을 때
        int mid = (low + high) / 2; // 중간 인덱스
        if (key == a[mid]) // 찾는 값이 중간 값과 같으면 중간 인덱스 리턴
            return mid;
        else if (key < a[mid]) // 찾는 값이 중간 값보다 작으면 왼쪽 탐색
            return bSearch(a, low, mid - 1, key);
        else // 찾는 값이 중간 값보다 크면 오른쪽 탐색
            return bSearch(a, mid + 1, high, key);
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

    printf("\n찾을 값: ");
    scanf("%d", &value);

    if ((index = bSearch(a, 0, CNT - 1, value)) == -1)
        printf("찾는 값이 없습니다.\n");
    else
        printf("%d는 %d번째에 있습니다.\n", value, index + 1);
}