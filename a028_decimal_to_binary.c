// 028 비트연산으로 10진수를 2진수로 변환
// mask(0001) 변수와 AND 연산을 활용

#include <math.h>
#include <stdio.h>

long long decimal_to_binary(int dec) {
    long long bin = 0;
    int mask = 0x01;
    int bit;

    for (int i = 0; i < 16; i++) {
        bit = dec & mask; // 맨 뒷자리가 0인지 1인지 판별
        bin +=
            bit *
            pow(10, i); // 2진수를 10진 형태로 저장하므로 10의 거듭제곱을 곱함
        dec = dec >> 1; // 2진수를 오른쪽으로 1비트씩 이동
    }

    return bin;
}

int main() {
    long long bin;
    int dec;

    printf("10진수 입력: ");
    scanf("%d", &dec);

    bin = decimal_to_binary(dec);
    printf("%d(decimal) = %lld(binary)\n", dec, bin);
}