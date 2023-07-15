// 011 에라토스테네스의 체
// 1부터 N까지의 소수와 개수를 출력
// 1. 소수인지 아닌지를 판별하는 배열을 만든다.
// 2. 2부터 시작해서 특정 수의 배수에 해당하는 수를 모두 지운다.

#include <stdbool.h>
#include <stdio.h>
#define N 10000

int main() {
    bool a[N + 1];  // 소수 판별 배열
    int primes = 0; // 소수 개수

    a[0] = a[1] = false; // 0과 1은 소수가 아님

    for (int i = 2; i <= N; i++) {
        a[i] = true; // 2부터 N까지 소수로 간주
    }

    for (int i = 2; i <= N / 2; i++) {     // 2부터 N/2까지만 검사
        for (int j = 2; j <= N / i; j++) { // i의 배수를 지움
            a[i * j] = false;              // i의 배수는 소수가 아님
        }
    }

    for (int i = 1; i <= N; i++) {
        if (a[i]) {
            primes++;
            printf("%4d%c", i, primes % 20 == 0 ? '\n' : ' ');
        }
    }

    printf("\n1부터 %d까지의 소수는 모두 %d개입니다.\n", N, primes);
}