// 025 문자열 안에서 다른 문자열 찾기
// strstr() 함수는 문자열 안에서 특정 문자열을 찾아서 그 위치를 반환

#include <stdio.h>
#include <string.h>

char str[] = "ababacabcaab";
char sub[] = "abc";

// 문자열 str에서 sub 문자열이 처음 시작되는 포인터를 리턴
char *my_strstr(const char *str, const char *sub) {
    int len1 = strlen(str);
    int len2 = strlen(sub);

    if (len2 == 0) // sub 문자열이 ""인 경우
        return (char *)str;

    // str의 남은 길이가 sub보다 작다면 비교할 필요가 없음
    while (len1 >= len2) {
        char *s = (char *)str;
        char *t = (char *)sub;

        // sub 문자열이 str 문자열에 있는지 비교
        while (*s == *t && *t != '\0') {
            s++;
            t++;
        }

        if (*t == '\0') // sub 문자열의 끝까지 다 찾았다면
            return (char *)str;

        str++;
        len1--;
    }
    return NULL;
}

int main() {
    printf("strstr()    : %s\n", strstr(str, sub));
    printf("my_strstr() : %s\n", my_strstr(str, sub));
}