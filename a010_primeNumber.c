// 010 1000까지의 소수를 출력

#include <stdio.h>

int main() {
    int index;
    int primes = 0;

    for (int i = 2; i < 1000; i++) {
        // 2부터 i까지 나누어서 나머지가 0이면 소수가 아니다.
        for (index = 2; index < i; index++) {
            if (i % index == 0) {
                break;
            }
        }
        // index가 i와 같으면 소수이다.
        if (index == i) {
            primes++;
            printf("%4d%c", i, primes % 15 == 0 ? '\n' : ' ');
        }
    }
    printf("\n");
    printf("1000까지의 소수는 %d개 입니다.\n", primes);
}