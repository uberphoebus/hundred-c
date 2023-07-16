// 035 이진탐색
// 0~10000 사이의 1000개 숫자를 랜덤 생성 -> 정렬 -> 이진탐색

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000
#define CNT 1000

int binarySearch(int a[], int n, int v);
void sort(int v[], int left, int right);
void swap(int v[], int i, int j);
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

    printf("\n\nInput a number to search: ");
    scanf("%d", &value);

    if ((index = binarySearch(a, CNT, value)) == -1) {
        printf("%d은(는) 배열 안에 없습니다.", value);
    } else {
        printf("%d은(는) a[%d]에 있습니다.", value, index);
    }
    printf("\n");
}

// 이진탐색 : 크기가 n인 배열에서 v를 탐색
int binarySearch(int a[], int n, int v) {
    int low = 0;      // 배열의 왼쪽 인덱스
    int high = n - 1; // 배열의 오른쪽 인덱스
    int mid;          // 배열의 중간 인덱스

    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == v)     // 중간 인덱스가 v와 같으면
            return mid;      // 인덱스 반환
        else if (a[mid] < v) // 중간 인덱스가 v보다 작으면
            low = mid + 1;   // 왼쪽 인덱스 아래는 버림
        else
            high =
                mid - 1; // 중간 인덱스가 v보다 크면 오른쪽 인덱스 아래는 버림
    }
    return -1; // low보다 high가 작아지면 배열에 v가 없음
}

void sort(int v[], int left, int right) {
    // 순차적으로 비교하며 정렬
    for (int i = left; i < right; i++) {
        for (int j = 0; j < right - 1; j++) {
            if (v[j] > v[j + 1]) {
                swap(v, j, j + 1);
            }
        }
    }
}

void swap(int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void printArr(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%c%6d", (i % 20 == 0) ? '\n' : ' ', a[i]);
}