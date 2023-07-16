// 027 2진수 -> 10진수
// int는 4바이트, long과 long long은 8바이트

#include <math.h>
#include <stdio.h>

int binary_to_decimal(long long n) {
    int dec = 0;
    int rem; // 나머지

    for (int i = 0; i < 32; i++) {
        rem = n % 10; // 2진수를 10으로 나눈 나머지
        dec += rem * pow(2, i); // 2의 0승부터 31승까지 2진수를 10진수로 변환
        n /= 10;                // 2진수를 10으로 나눈 몫
    }

    return dec;
}

int main() {
    printf("sizeof(int)       = %ld\n", sizeof(int));
    printf("sizeof(long)      = %ld\n", sizeof(long));
    printf("sizeof(long long) = %ld\n\n", sizeof(long long));

    long long bin;
    int dec;

    printf("2진수 입력: ");
    scanf("%lld", &bin);

    dec = binary_to_decimal(bin);
    printf("%lld(binary) = %d(decimal)\n", bin, dec);
}