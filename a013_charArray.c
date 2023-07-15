// 013 문자열 처리
// 문자열의 끝은 '\0'으로 표시된다.
// 한글은 3바이트로 표현

#include <stdio.h>

int main() {
    char s[10] = {'a', 'b', 'c', 'd', 'e'};
    char t[] = {'a', 'b', 'c', 'd', 'e', '\0'};
    char u[] = "abcde";
    char v[] = "안녕하세요";
    char w[] = "안"; // 한글은 3바이트 + '\0' = 4바이트
    char x[] = "안녕";

    printf("s = |%s| size = %ld\n", s, sizeof(s));
    printf("t = |%s| size = %ld\n", t, sizeof(t));
    printf("u = |%s| size = %ld\n", u, sizeof(u));
    printf("v = |%s| size = %ld\n", v, sizeof(v));
    printf("w = |%s| size = %ld\n", w, sizeof(w));
    printf("x = |%s| size = %ld\n", x, sizeof(x));
}