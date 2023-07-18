// 040 선택정렬
// 가장 작은 값을 찾아서 맨 앞에 이동시키는 정렬
// 시간복잡도는 버블정렬과 같지만, 교환횟수가 적어서 버블정렬보다 효율적

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

void swap(int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void selection_sort(int v[], int left, int right) {
    for (int i = left; i < right - 1; i++) {
        int min = i;          // 가장 작은 값의 인덱스
        int min_num = v[min]; // 가장 작은 값
        for (int j = i + 1; j < right; j++) {
            if (v[j] < v[min]) {
                min = j; // 가장 작은 값의 인덱스 갱신
                min_num = v[min];
            }
        }
        swap(v, i, min); // 가장 작은 값과 i번째 원소를 교환

        printf("(i, min_num) = (%d, %d) : ", i, min_num);
        for (int k = 0; k < MAX; k++) {
            printf("%3d", v[k]);
        }
        printf("\n");
    }
}

int main() {
    int v[MAX];

    srand(time(NULL));
    for (int i = 0; i < MAX; i++)
        v[i] = rand() % MAX;

    selection_sort(v, 0, MAX);
}