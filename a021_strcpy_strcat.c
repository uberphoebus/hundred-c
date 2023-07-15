// 021 문자열의 복사와 문자열의 연결

#include <malloc.h>
#include <stdio.h>
#include <string.h>

// source에서 dest로 문자열 복사
char *my_strcpy(char *dest, char *source) {
    dest = (char *)malloc(strlen(source) +
                          1); // source의 길이 + 1 만큼 메모리 할당
    int i = 0;
    while (dest[i] = source[i]) { // source의 문자열을 dest에 복사
        i++;
    }
    dest[i] = '\0';
    return dest;
}

// str1에 str2 문자열을 결합
char *my_strcat(char *str1, char *str2) {
    char *result = (char *)malloc(strlen(str1) + strlen(str2) +
                                  1); // 두 문자열의 길이 + 1 만큼 메모리 할당
    int i = 0;

    while (str1[i] != '\0') {
        result[i] = str1[i]; // str1의 문자열을 result에 복사
        i++;
    }

    char *ptr = result + strlen(str1); // str1의 문자열 길이만큼 포인터 이동
    while (*str2 != '\0') {
        *ptr++ = *str2++; // str2의 문자열을 result에 복사
    }
    *ptr = '\0';

    return result;
}

int main() {
    char s[] = "Hello World!";
    char *t = NULL;
    char u[] = "C programming language!";

    t = my_strcpy(t, s);
    printf("my_strcpy() : %s -> %s\n", s, t);
    printf("my_strcat() : %s\n", my_strcat(s, u));
}