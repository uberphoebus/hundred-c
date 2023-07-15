// 024 정수와 문자열의 변환
// atoi() 함수는 문자열을 정수로 변환하는 함수
// itoa() 함수는 정수를 문자열로 변환하는 함수

#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

int my_atoi(const char *s) {
    int value = 0;

    while (*s) {
        if (*s >= '0' && *s <= '9') {
            value = value * 10 + (*s - '0'); // 10진수로 변환
            s++;
        } else {
            printf("non-number found!");
            return -1;
        }
    }
    return value;
}

char *my_itoa(int v) {
    int digits = 0; // 자릿수
    int t = v;

    while (t) {
        digits++;
        t /= 10; // 10으로 나누어 자릿수를 구함
    }

    char *number = (char *)malloc(digits + 1); // 자릿수 + NULL 문자
    number[digits] = '\0';

    while (digits != 0) {
        number[--digits] = v % 10 + '0'; // 10으로 나눈 나머지를 문자로 변환
        v /= 10; // 10으로 나눈 몫을 다시 v에 저장
    }

    return number;
}

int main() {
    char buffer[30];

    printf("atoi()    : %d\n", atoi("12345"));
    printf("my_atoi() : %d\n", my_atoi("12345"));
    printf("my_itoa() : %s\n", my_itoa(12345));
}