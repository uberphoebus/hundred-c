// 039 버블정렬
// 인접한 2개의 원소를 비교하여 더 큰 수를 뒤로 보내는 정렬 방법
// 한번 반복할 때마다 가장 큰 수가 뒤로 보내지며, 물방울 모습과 비슷

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

void swap(int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void bubble_sort(int v[], int left, int right) {
    // right - 1인 이유는 마지막 원소는 비교할 필요가 없기 때문
    for (int i = left; i < right - 1; i++) {

        // 반복마다 가장 큰수가 뒤로 보내지므로
        // i번째 반복에서는 뒤에서 i개의 원소는 정렬되어 있음
        // 따라서 i번째 반복에서는 뒤에서 i개의 원소는 비교할 필요가 없음
        for (int j = left; j < right - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                swap(v, j, j + 1);
                printf("(i, j) = (%d, %d) : ", i, j);
                for (int k = 0; k < MAX; k++) {
                    printf("%3d", v[k]);
                }
                printf("\n");
            }
        }
    }
}

int main() {
    int v[MAX];

    srand(time(NULL));
    for (int i = 0; i < MAX; i++)
        v[i] = rand() % MAX;

    for (int i = 0; i < MAX; i++)
        printf("%3d %c", v[i], (i % 10 == 9) ? '\n' : ' ');

    bubble_sort(v, 0, MAX);

    printf("\n...bubble sorting\n");
    for (int i = 0; i < MAX; i++)
        printf("%3d %c", v[i], (i % 10 == 9) ? '\n' : ' ');
}