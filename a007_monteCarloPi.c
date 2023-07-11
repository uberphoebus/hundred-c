// 007 몬테카를로 시뮬레이션 원주율
// 랜덤하게 많은 수의 점(100000000)을 만들어 원의 내부에 있는지 판단

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isPowerOfTen(int x);

int main() {
    int x, y;        // 점의 좌표
    int iCnt = 0;    // 원의 내부에 있는 점의 개수
    int oCnt = 0;    // 원의 외부에 있는 점의 개수
    int radius = 50; // 원의 반지름
    double pi;

    for (int i = 0; i < 100000000; i++) {
        x = rand() % (radius * 2);
        y = rand() % (radius * 2);
        if ((pow(x - radius, 2) + pow(y - radius, 2)) <= pow(radius, 2))
            iCnt++;
        else
            oCnt++;

        pi = (double)iCnt / (double)(iCnt + oCnt) * 4;

        if (isPowerOfTen(i))
            printf("i = %10d, iCnt = %10d, oCnt = %10d, pi = %.18f\n", i, iCnt,
                   oCnt, pi);
    }
    printf("\n");
    printf("iCnt = %d, oCnt = %d, pi = %.18f\n", iCnt, oCnt, pi);
}

bool isPowerOfTen(int x) {
    for (int i = 0; i < 10; i++) {
        if (x == pow(10, i))
            return true;
    }
    return false;
}