// 053 구조체와 공용체를 사용하여 도형의 면적 계산

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define COUNT 3

struct {
    int x;
    float y;
    char z;
} myStruct;

union {
    int x;
    float y;
    char z;
} myUnion;

enum FigureType { CIRCLE, TRIANGLE, RECTANGLE };

struct figure {
    enum FigureType type;
    union {
        int radius;
        int tri_sides[3];
        int rect_sides[2];
    };
};

float area(struct figure *f) {
    float area, s;
    switch (f->type) {
    case CIRCLE:
        area = 3.141592 * f->radius * f->radius;
        break;
    case TRIANGLE:
        s = (f->tri_sides[0] + f->tri_sides[1] + f->tri_sides[2]) / 2.0;
        area = sqrt(s * (s - f->tri_sides[0]) * (s - f->tri_sides[1]) *
                    (s - f->tri_sides[2]));
        break;
    case RECTANGLE:
        area = f->rect_sides[0] * f->rect_sides[1];
        break;
    }
    return area;
}

void printFigure(struct figure *f) {
    switch (f->type) {
    case CIRCLE:
        printf("원의 반지름은 %d, 면적은 %.2f입니다.\n", f->radius, area(f));
        break;
    case TRIANGLE:
        printf("삼각형의 세변의 길이는 %d, %d, %d, 면적은 %.2f입니다.\n",
               f->tri_sides[0], f->tri_sides[1], f->tri_sides[2], area(f));
        break;
    case RECTANGLE:
        printf("사각형의 두변의 길이는 %d, %d, 면적은 %f입니다.\n",
               f->rect_sides[0], f->rect_sides[1], area(f));
        break;
    }
}

bool checkTriangle(struct figure fig) {
    int max = 0;
    for (int i = 1; i <= 2; i++) {
        if (max < fig.tri_sides[i])
            max = i;
    }

    int otherSum = 0;
    for (int i = 0; i <= 2; i++) {
        if (i != max)
            otherSum += fig.tri_sides[i];
    }

    if (fig.tri_sides[max] < otherSum)
        return true;
    else
        return false;
}

int main() {

    printf("sizeof myStruct = %ld\n", sizeof(myStruct));
    printf("sizeof myUnion  = %ld\n", sizeof(myUnion));

    struct figure fig[COUNT];

    for (int i = 0; i < COUNT; i++) {
        printf("\n도형의 타입은? (C:원, T:삼각형, R:사각형) ");
        char type = getchar();

        switch (type) {
        case 'C':
            fig[i].type = CIRCLE;
            printf("\n반지름을 입력하세요 :");
            scanf("%d", &fig[i].radius);
            break;
        case 'T':
            fig[i].type = TRIANGLE;
            printf("\n삼각형의 세변의 길이를 입력하세요 :");
            scanf("%d %d %d", &fig[i].tri_sides[0], &fig[i].tri_sides[1],
                  &fig[i].tri_sides[2]);
            if (checkTriangle(fig[i]) == false) {
                printf("삼각형이 아닙니다. 다시 입력하세요.\n");
                i--;
                continue;
            }
            break;
        case 'R':
            fig[i].type = RECTANGLE;
            printf("\n사각형의 두변의 길이를 입력하세요 :");
            scanf("%d %d", &fig[i].rect_sides[0], &fig[i].rect_sides[1]);
            break;
        default:
            i--;
            break;
        }
    }

    for (int i = 0; i < COUNT; i++) {
        printFigure(&fig[i]);
    }
}