// 022 대문자와 소문자의 변환

#include <stdio.h>

char *to_upper(char *s) {
    char *ptr = s;

    while (*ptr) {
        if (*ptr >= 'a' && *ptr <= 'z') {
            *ptr -= 'a' - 'A';
        }
        ptr++;
    }

    return s;
}

char *to_lower(char *s) {
    char *ptr = s;

    while (*ptr) {
        if (*ptr >= 'A' && *ptr <= 'Z') {
            *ptr += 'a' - 'A';
        }
        ptr++;
    }

    return s;
}

int main() {
    char s[] = "Hello World!";
    printf("to_upper() : %s -> %s\n", s, to_upper(s));
    printf("to_lower() : %s -> %s\n", s, to_lower(s));
}