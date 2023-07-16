// 032 실행시간 측정
// clock() 함수 사용
// clock_t clock(void);

#include <stdio.h>
#include <time.h>

int main() {
    double start, end;

    start = (double)clock() / CLOCKS_PER_SEC; // 초당 클록수로 나눔

    int sum = 0;
    for (int i = 0; i < 100000000; i++) {
        sum++;
    }

    end = (double)clock() / CLOCKS_PER_SEC;
    printf("sum = %d, 실행시간 = %lf\n", sum, end - start);
}