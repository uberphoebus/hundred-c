// 004 겹치지 않는 랜덤 숫자 만들기
// 1~10 사이의 숫자를 랜덤하게 10개 출력하는데, 겹치지 않게 출력

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CNT 10

int main() {
    int check[CNT + 1] = {0}; // 중복 체크 배열
    int rand_num[CNT] = {0};  // 랜덤 숫자 저장 배열
    int min = 1, max = 10;    // 최소값, 최대값

    srand(time(0));

    for (int i = 0; i < CNT; i++) {
        int x;
        do {
            x = rand() % max + min;
        } while (check[x] == 1); // 중복이면 다시 랜덤 숫자 생성
        check[x] = 1; // 중복 체크 배열에 중복이 아닌 것으로 표시
        rand_num[i] = x; // 랜덤 숫자 저장
    }

    for (int i = 0; i < CNT; i++) {
        printf("%3d ", rand_num[i]);
    }
    printf("\n");
}