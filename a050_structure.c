// 050 구조체를 사용하여 점과 사각형 표현
// 두 점 사이의 거리 계산, 사각형의 면적 계산

#include <math.h>
#include <stdio.h>

struct point {
    int x;
    int y;
};

struct rectangle {
    struct point p1;
    struct point p2;
};

double distance(struct point p1, struct point p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;

    return sqrt(pow(dx, 2) + pow(dy, 2));
}

double area(struct rectangle r) {
    return abs(r.p1.x - r.p2.x) * abs(r.p1.y - r.p2.y);
}

int main() {
    struct point pt1 = {10, 20};
    struct point pt2 = {30, 40};
    struct rectangle rect = {pt1, pt2};

    printf("두 점 사이의 거리는 %f입니다.\n", distance(pt1, pt2));
    printf("사각형의 면적은 %f입니다.\n", area(rect));
}