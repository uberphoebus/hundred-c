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
  return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double area(struct rectangle r) {
  return distance(r.p1, r.p2) * distance(r.p1, r.p2);
}

int main() {
  struct point pt1 = {10, 20};
  struct point pt2 = {30, 40};
  struct rectangle r = {pt1, pt2};

  printf("%f\n", distance(pt1, pt2));
  printf("%f\n", area(r));
}