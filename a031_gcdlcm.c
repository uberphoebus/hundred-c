// 031 최대공약수와 최소공배수
// 유클리드 호제법 : gcd(a, b) = gcd(b, a%b)
// gcd(60, 24) = gcd(24, 12) = gcd(12, 0) = 12

#include <stdio.h>

int gcd(int x, int y);

int main() {
    int a, b, GCD, LCM;

    printf("두 수를 입력하세요 : ");
    scanf("%d %d", &a, &b);

    GCD = gcd(a, b);
    LCM = a * b / GCD;

    printf("GCD(%d, %d) : %d\n", a, b, GCD);
    printf("LCM(%d, %d) : %d\n", a, b, LCM);
}

int gcd(int x, int y) {
    if (y == 0)
        return x;
    else
        return gcd(y, x % y); // a%b가 0이 될 때까지 재귀호출
}
