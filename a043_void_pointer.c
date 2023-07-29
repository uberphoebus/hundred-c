// 043 void pointer
// void 포인터는 간접참조와 포인터 연산이 불가능
// 형변환을 통해서만 사용 가능

#include <stdio.h>
#define INT 0
#define FLOAT 1
#define DOUBLE 2

void *add(void *a, void *b, void *result, int type) {
    switch (type) {
    case INT:
        // a와 b를 int형 포인터로 형변환하여 간접참조
        // result도 int형 포인터로 형변환하여 간접참조
        *(int *)result = *((int *)a) + *((int *)b);
        break;
    case FLOAT:
        *(float *)result = *((float *)a) + *((float *)b);
        break;
    case DOUBLE:
        *(double *)result = *((double *)a) + *((double *)b);
        break;
    }
    return result;
}

int main() {
    int x = 10, y = 20, intResult;
    float f1 = 1.3, f2 = 2.4, floatResult;
    double d1 = 2.5, d2 = 3.3, doubleResult;

    printf("%d\n", *(int *)add(&x, &y, &intResult, INT));
    printf("%f\n", *(float *)add(&f1, &f2, &floatResult, FLOAT));
    printf("%lf\n", *(double *)add(&d1, &d2, &doubleResult, DOUBLE));
}