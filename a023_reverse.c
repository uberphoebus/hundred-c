// 023 문자열 뒤집기
// _strrev 함수 구현

#include <stdio.h>
#include <string.h>

char *my_reverse(char *s) {
    char *end = s + strlen(s) - 1; // 문자열의 끝을 가리키는 포인터

    for (char *ptr = s; ptr < end; ptr++, end--) { // 문자열의 앞과 뒤를 바꿈
        char temp = *ptr;
        *ptr = *end;
        *end = temp;
    }

    return s;
}

int main() {
    char s[] = "Hello World!~";
    printf("my_reverse() : %s\n", my_reverse(s));
}