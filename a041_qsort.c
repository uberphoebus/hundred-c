// 041 quick sort
// 여러 정렬 알고리즘 중 가장 빠름
// 같은 시간복잡도를 가진 정렬 중에서는 가장 적은 교환을 필요로 하는 정렬
// 기준값(pivot)을 기준으로 작은 값은 왼쪽, 큰 값은 오른쪽으로 분할하여 정렬

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

void swap(int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void my_qsort(int v[], int left, int right) {
    // left: 정렬할 배열의 시작 인덱스
    // right: 정렬할 배열의 마지막 인덱스
    // last = pivot의 위치

    int i, last;

    if (left >= right) // 원소가 1개인 경우
        return;

    swap(v, left, (left + right) / 2); // 배열의 중간 값을 pivot으로 설정
    last = left;                       // pivot의 위치를 last에 저장
    for (i = left + 1; i <= right; i++) {
        if (v[i] < v[left]) {             // pivot보다 작은 값이 나오면
            swap(v, ++last, i);           // last의 다음 위치와 교환
            for (int i = 0; i < MAX; i++) // 정렬 과정 출력
                printf("%d ", v[i]);
            printf("\n");
        }
    }
    swap(v, left, last); // pivot을 중간으로 이동

    my_qsort(v, left, last - 1); // pivot을 기준으로 왼쪽 부분 배열 정렬
    my_qsort(v, last + 1, right); // pivot을 기준으로 오른쪽 부분 배열 정렬
}

int main() {
    int i;
    int v[MAX] = {5, 3, 8, 4, 9, 1, 6, 2, 7, 0};

    // srand(time(NULL));
    // for (i = 0; i < MAX; i++)
    //     v[i] = rand() % MAX;

    printf("정렬 전: \n");
    for (i = 0; i < MAX; i++)
        printf("%d ", v[i]);

    printf("\n정렬 중: \n");
    my_qsort(v, 0, MAX - 1);
}