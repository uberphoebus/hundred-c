// 003 몬테카를로 시뮬레이션 크랩스 게임 확률 계산
// 주사위 두개를 백만번 던져서 두 주사위 숫자의 합을 배열에 저장하고 확률을 출력

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TRIALS 1000000

int main() {
    int cnt[13] = {0};    // 주사위 두개의 합을 저장할 배열
    int min = 1, max = 6; // 주사위 눈의 최소값, 최대값
    int dice;             // 주사위 두개의 합

    srand(time(0));

    for (int i = 0; i < TRIALS; i++) {
        dice = rand() % max + min + rand() % max + min;
        cnt[dice]++;
    }

    for (int i = 2; i <= 12; i++) {
        printf("%2d : %6d %6.2f%%\n", i, cnt[i], cnt[i] / (double)TRIALS * 100);
    }
}