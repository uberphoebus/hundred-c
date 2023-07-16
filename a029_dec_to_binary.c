// 029 재귀함수로 10진수 -> 2진수
// INT_MAX = 2147483647 -> limit.h

#define SIZE 32
#include <limits.h> // INT_MAX
#include <malloc.h> // malloc
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strcpy

char *itoa(int v) {
    int digits = 0;
    int t = v;

    while (t) {
        digits++;
        t /= 10;
    }

    char *number = (char *)malloc(digits + 1);
    number[digits] = '\0';

    while (digits != 0) {
        number[--digits] = v % 10 + '0';
        v /= 10;
    }

    return number;
}

int checkOverflow(char buffer[]) {
    char intmax[11];
    strcpy(intmax, itoa(INT_MAX)); // intmax = "2147483647"

    if (strlen(buffer) > strlen(intmax)) {
        return 1;
    } else if (strlen(buffer) == strlen(intmax)) {
        for (int i = 0; i < 11; i++) {
            if (buffer[i] > intmax[i]) {
                return 1;
            }
        }
    }
    return 0;
}
void array_d2b(int n) {
    int arr[SIZE] = {0};
    int i, length = 0; // 배열 길이

    for (i = 0; n > 0; i++) {
        arr[i] = n % 2; // 2로 나눈 나머지를 앞에서부터 배열에 저장
        n /= 2;         // 2로 나눈 몫을 다시 n에 저장
        length++;       // 배열 길이를 구하기 위해 1씩 증가
    }
    length--; // 배열 길이를 구하기 위해 1씩 증가했으므로 1 감소

    while (length >= 0) {
        printf("%d", arr[length]); // 배열의 뒤에서부터 출력
        length--;
    }
}
void recursive_d2b(int n) {
    if (n >= 2) {
        recursive_d2b(n / 2);
    }
    printf("%d", n % 2);
}

int main() {
    int n;
    // char number[11] = {0}; // 10자리 숫자 + NULL
    char number[11] = "27";
    strcpy(number, "8");

    if (checkOverflow(number) == 1) {
        printf("Overflow");
        exit(0);
    } else {
        printf("No Overflow");
    }

    n = atoi(number);

    printf("\n10진수 %d의 2진수는: ", n);
    array_d2b(n);

    printf("\n10진수 %d의 2진수는: ", n);
    recursive_d2b(n);
    printf("\n");
}