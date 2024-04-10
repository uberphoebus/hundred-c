#define _CRT_SECURE_NO_WARNINGS
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

enum FigureType { CIRCLE, RECTANGLE, TRIANGLE };

struct figure {
  enum FigureType type;
  union {
    int radius;
    int tri_sides[3];
    int rect_sizd[2];
  };
};

float area(struct figure *f);
void printFigure(struct figure *f);
bool checkTriangle(struct figure fig);
double _sqrt(double n);

int main() {
  printf("basic data types\n");
  printf("sizeof char     = %ld\n", sizeof(char));         // 1 -> not 4
  printf("sizeof uint8_t  = %ld\n", sizeof(__uint8_t));    // 1
  printf("sizeof uint16_t = %ld\n", sizeof(__uint16_t));   // 2
  printf("sizeof uint     = %ld\n", sizeof(__u_int));      // 4
  printf("sizeof uint32_t = %ld\n", sizeof(__uint32_t));   // 4
  printf("sizeof uint64_t = %ld\n", sizeof(__uint64_t));   // 8
  printf("sizeof int8     = %ld\n", sizeof(__int8_t));     // 1
  printf("sizeof int16    = %ld\n", sizeof(__int16_t));    // 2
  printf("sizeof int      = %ld\n", sizeof(int));          // 4 (not 8)
  printf("sizeof int32    = %ld\n", sizeof(__int32_t));    // 4
  printf("sizeof int64    = %ld\n", sizeof(__int64_t));    // 8
  printf("sizeof float    = %ld\n", sizeof(float));        // 4
  printf("sizeof double   = %ld\n", sizeof(double));       // 8
  printf("sizeof __float128 = %ld\n", sizeof(__float128)); // 16

  printf("\nstruct and union\n");
  printf("sizeof myStruct = %ld\n", sizeof(myStruct)); // 12 -> not 9
  printf("sizeof myUnion  = %ld\n", sizeof(myUnion));  // 4

  printf("\narea of figures\n");
  struct figure fig[COUNT];
  for (int i = 0; i < COUNT; i++) {
    printf(
        "Enter the type of figure (c = circle, r = rectangle, t = triangle): ");
    char type = getchar();

    switch (type) {
    case 'c':
      fig[i].type = CIRCLE;
      printf("Enter the radius of the circle: ");
      scanf("%d", &fig[i].radius);
      break;
    case 't':
      fig[i].type = TRIANGLE;
      printf("Enter the sides of the triangle: ");
      scanf("%d %d %d", &fig[i].tri_sides[0], &fig[i].tri_sides[1],
            &fig[i].tri_sides[2]);
      if (checkTriangle(fig[i]) == false) {
        printf("Triangle is invalid\n");
        i--;
        continue;
      }
      break;
    case 'r':
      fig[i].type = RECTANGLE;
      printf("Enter the sides of the rectangle: ");
      scanf("%d %d", &fig[i].rect_sizd[0], &fig[i].rect_sizd[1]);
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

double _sqrt(double n) {
  double x = 1.0;
  for (int i = 0; i < 10; i++) {
    x = (x + n / x) / 2;
  }
  return x;
}

float area(struct figure *f) {
  float area, s;
  switch (f->type) {
  case CIRCLE:
    area = 3.14 * f->radius * f->radius;
    break;
  case TRIANGLE:
    s = (f->tri_sides[0] + f->tri_sides[1] + f->tri_sides[2]) / 2.0;
    area = _sqrt(s * (s - f->tri_sides[0]) * (s - f->tri_sides[1]) *
                 (s - f->tri_sides[2]));
    break;
  case RECTANGLE:
    area = f->rect_sizd[0] * f->rect_sizd[1];
    break;
  }
  return area;
}

void printFigure(struct figure *f) {
  switch (f->type) {
  case CIRCLE:
    printf("Circle with radius %d has area %f\n", f->radius, area(f));
    break;
  case TRIANGLE:
    printf("Triangle with sides %d, %d, %d has area %f\n", f->tri_sides[0],
           f->tri_sides[1], f->tri_sides[2], area(f));
    break;
  case RECTANGLE:
    printf("Rectangle with sides %d, %d has area %f\n", f->rect_sizd[0],
           f->rect_sizd[1], area(f));
    break;
  }
}

bool checkTriangle(struct figure fig) {
  if (fig.tri_sides[0] + fig.tri_sides[1] <= fig.tri_sides[2] ||
      fig.tri_sides[1] + fig.tri_sides[2] <= fig.tri_sides[0] ||
      fig.tri_sides[2] + fig.tri_sides[0] <= fig.tri_sides[1]) {
    return false;
  }
  return true;
}