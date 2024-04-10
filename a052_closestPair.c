#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POINTS 100
#define MAXPOS 1000

typedef struct point {
  int x;
  int y;
} point;

typedef struct pointPair {
  double idst;
  point p1;
  point p2;
} pointPair;

point p[POINTS];

double _pow(double n, double m);
double _sqrt(double n);
double dist(point p1, point p2);
pointPair makePair(point p1, point p2);
pointPair closestPair();

int main() {
  srand(time(NULL));
  for (int i = 0; i < POINTS; i++) {
    p[i].x = rand() % MAXPOS;
    p[i].y = rand() % MAXPOS;
  }

  pointPair pp = closestPair();
  printf("Closest pair: (%d, %d) and (%d, %d)\n", pp.p1.x, pp.p1.y, pp.p2.x,
         pp.p2.y);
  printf("Distance: %f\n", pp.idst);
}

double _pow(double n, double m) {
  double nn = n;
  if (m == 0) {
    return 1.0;
  }
  for (int i = 0; i < (m - 1); i++) {
    n *= nn;
  }
  return n;
}

double _sqrt(double n) {
  double x = 1.0;
  for (int i = 0; i < 10; i++) {
    x = (x + n / x) / 2;
  }
  return x;
}

double dist(point p1, point p2) {
  return _sqrt(_pow(p1.x - p2.x, 2) + _pow(p1.y - p2.y, 2));
}

pointPair makePair(point p1, point p2) {
  pointPair pp;
  pp.p1 = p1;
  pp.p2 = p2;
  pp.idst = dist(p1, p2);
  return pp;
}

pointPair closestPair() {
  double min = MAXPOS * MAXPOS;
  double d;
  pointPair minPair;

  for (int i = 0; i < POINTS - 1; i++) {
    for (int j = i + 1; j < POINTS; j++) {
      if ((d = dist(p[i], p[j])) < min) {
        min = d;
        minPair = makePair(p[i], p[j]);
      }
    }
  }
  return minPair;
}