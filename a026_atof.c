// 026 실수를 표시하는 문자열을 숫자로 변환하기
// atof() 함수를 사용하여 문자열을 실수로 변환

#include <ctype.h> // isdigit
#include <math.h>  // pow
#include <stdio.h>
#include <string.h> // strcpy

#define MINUS -1
#define PLUS 1

double my_atof(char *s) {
    int sign = PLUS;        // 부호
    int value = 0;          // 정수부
    double mantissa = 0.0;  // 소수부
    double mandigit = 10.0; // 소수부 자릿수
    int exp = 0;            // 지수부
    int expsign = PLUS;     // 지수부 부호

    if (*s == '-') { // 부호 판별
        sign = MINUS;
        s++;
    } else if (*s == '+') {
        s++;
    }

    // 정수부 계산
    while (*s != '.' && *s != 'e' && *s != 'E' && *s != '\0') {
        if (isdigit(*s)) {
            value = value * 10 + (*s - '0');
        }
        s++;
    }

    // 소수부 계산
    if (*s == '.') {
        while (*s != 'e' && *s != 'E' && *s != '\0') {
            if (isdigit(*s)) {
                // 소수부 자릿수를 10으로 나누면서 소수부를 계산
                mantissa = mantissa + (*s - '0') / mandigit;
                mandigit *= 10;
            }
            s++;
        }
    }

    // 지수부 계산
    if (*s == 'e' || *s == 'E') {
        s++;
        if (*s == '-') { // 지수부 부호 판별
            expsign = MINUS;
            s++;
        } else if (*s == '+') {
            s++;
        }
    }
    while (*s != '\0') {
        if (isdigit(*s)) {
            // 지수부 계산
            exp = exp * 10 + (*s - '0');
            s++;
        }
    }

    return sign * (value + mantissa) * pow(10, expsign * exp);
}

int main() {
    char s[30] = "1.234";
    printf("%f\n", my_atof(s));

    strcpy(s, "1.234e10");
    printf("%e\n", my_atof(s));

    strcpy(s, "-1.234e-10");
    printf("%e\n", my_atof(s));
}