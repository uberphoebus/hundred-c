// 033 피보나치수열과 동적 알고리즘
// Fibo(1) = 1;
// Fibo(2) = 1;
// Fibo(n) = Fibo(n-1) + Fibo(n-2);
// 1. 배열 사용(반복)
// 2. 재귀적 알고리즘
// 3. 동적 알고리즘

#include <stdio.h>
#include <time.h>

void printResult(int a[], int n, double t) {
    for (int i = 0; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n실행시간 : %lf\n", t);
}

int RecurFibonacci(int n) {
    if (n <= 2)
        return 1;
    else
        return RecurFibonacci(n - 1) + RecurFibonacci(n - 2);
}

int dp[100];
int DynaFibonacci(int n) {
    if (n <= 2)
        return 1;
    else if (dp[n] != 0) // 이미 계산된 값이면
        return dp[n];
    else
        return dp[n] = DynaFibonacci(n - 1) + DynaFibonacci(n - 2);
}

int main() {
    double start, end;
    int n;
    int f[100];

    printf("n = ");
    scanf("%d", &n);

    // 1. 배열 사용(반복)
    start = (double)clock() / CLOCKS_PER_SEC;
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i - 1] + f[i - 2];
    }
    end = (double)clock() / CLOCKS_PER_SEC;
    printResult(f, n, end - start);

    // 2. 재귀적 알고리즘
    start = (double)clock() / CLOCKS_PER_SEC;
    for (int i = 1; i <= n; i++) {
        f[i] = RecurFibonacci(i);
    }
    end = (double)clock() / CLOCKS_PER_SEC;
    printResult(f, n, end - start);

    // 3. 동적 알고리즘
    start = (double)clock() / CLOCKS_PER_SEC;
    for (int i = 1; i <= n; i++) {
        f[i] = DynaFibonacci(i);
    }
    end = (double)clock() / CLOCKS_PER_SEC;
    printResult(f, n, end - start);
}