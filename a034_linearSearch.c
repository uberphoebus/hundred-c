// 034 선형탐색
// 0~10000 사이의 1000개 숫자를 랜덤 생성
// 최소값과 최대값을 찾고, 선형탐색으로 원하는 값의 인덱스 찾기

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10000
#define CNT 1000

int search(int a[], int v);
void printArr(int a[], int n);
void find_min_max(int a[], int n);

int main() {
    int a[CNT];
    int value, index;

    srand(time(NULL));
    for (int i = 0; i < CNT; i++) {
        a[i] = rand() % MAX;
    }

    printArr(a, CNT);
    find_min_max(a, CNT);

    printf("찾고자 하는 값 : ");
    scanf("%d", &value);

    if ((index = search(a, value)) == -1)
        printf("%d은(는) 배열 안에 없습니다.\n", value);
    else
        printf("%d은(는) a[%d]에 있습니다.\n", value, index);
}

int search(int a[], int v) {
    for (int i = 0; i < CNT; i++) {
        if (a[i] == v)
            return i;
    }
    return -1;
}

void find_min_max(int a[], int n) {
    int min = a[0], max = a[0]; // 배열의 첫번째 원소로 초기화
    for (int i = 1; i < n; i++) {
        if (min > a[i])
            min = a[i]; // min보다 작은 값이 나오면 min에 저장
        if (max < a[i])
            max = a[i]; // max보다 큰 값이 나오면 max에 저장
    }
    printf("\nmin = %d, max = %d\n", min, max);
}

void printArr(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%c%6d", (i % 10 == 0) ? '\n' : ' ', a[i]);
    }
}