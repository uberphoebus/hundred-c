// 002 랜덤 숫자 만들기
// srand() : seed
// rand() : random number
// time() : random seed time
// dice 1 ~6, count 30

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a[10];            // 저장 배열
    int dice[30];         // 주사위
    int min = 1, max = 6; // 최소값, 최대값

    srand(time(NULL)); // 랜덤시드 설정

    for (int i = 0; i < 10; i++) {
        a[i] = rand();
    }

    printf("max = %x, %d\n", max, max); // print hexa, decimal
    for (int i = 0; i < 10; i++) {
        printf("%3d ", a[i]);
    }
    printf("\n");

    for (int i = 0; i < 30; i++) {
        dice[i] = rand() % max + min; // 1 ~ 6
    }

    for (int i = 0; i < 30; i++) {
        printf("%6d%c", dice[i], (i + 1) % 10 != 0 ? ' ' : '\n');
    }
    printf("\n");
}