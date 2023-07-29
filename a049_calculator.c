// 049 사칙 계산기

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

double calculate(double x, char op, double y) {
    switch (op) {
    case '+':
        return x + y;
    case '-':
        return x - y;
    case '*':
        return x * y;
    case '/':
        return x / y;
    default:
        return 0.0;
    }
}

int main() {
    char buf[80];
    double result = 0.0;
    char op = '+'; // 초기값을 '+'로 설정

    while (true) {
        printf("\n사칙계산기(종료는 'q'를 입력하세요)\n");
        printf("수식을 입력하세요. 예) a+b | a-b | a*b | a/b\n==> ");

        fgets(buf, 80, stdin); // 표준 입력으로부터 최대 80자리까지 읽어들임
        char *p = buf;
        double value[2] = {0.0}; // 피연산자 저장 배열
        int index = 0;

        while (*p != '\n') { // buf의 끝까지 반복
            if (*p == 'q')
                return 0;
            if (isdigit(*p)) {           // 숫자면
                float v = strtof(p, &p); // 숫자로 변환하여
                value[index++] = v;      // 피연산자 저장
            } else if (*p == '+') {
                op = '+', p++;
            } else if (*p == '-') {
                op = '-', p++;
            } else if (*p == '*') {
                op = '*', p++;
            } else if (*p == '/') {
                op = '/', p++;
            } else if (isspace(*p)) {
                p++;
            }
        }

        if (op == '/' && value[1] == 0) {
            printf("Division by 0 exception\n");
            continue;
        } else {
            result = calculate(value[0], op, value[1]);
        }
        printf("%f %c %f = %f\n", value[0], op, value[1], result);
    }
}