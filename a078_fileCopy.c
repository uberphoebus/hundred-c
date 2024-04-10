#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *ifp; // 입력용 파일 포인터 선언
  FILE *ofp; // 출력용 파일 포인터 선언

  char sname[20];
  char tname[20];

  void fileCopy(FILE *, FILE *);

  printf("소스 파일 이름을 입력하세요: ");
  scanf("%s", sname);

  if ((ifp = fopen(sname, "r")) == NULL) {
    printf("오류: 파일 %s을(를) 열 수 없습니다.\n", sname);
    exit(1);
  }

  printf("대상 파일 이름을 입력하세요: ");
  scanf("%s", tname);

  if (!strcmp(tname, "stdout")) {
    ofp = stdout;
  } else {
    ofp = fopen(tname, "w");
  }

  fileCopy(ifp, ofp);
  fclose(ifp);
  fclose(ofp);
}

void fileCopy(FILE *ifp, FILE *ofp) {
  int c;
  while ((c = fgetc(ifp)) != EOF) {
    // 한글자씩 쓰기
    fputc(c, ofp);

    // 문자열로 쓰기
    /*
    char line[80];
    while (fgets(line, 80, ifp) != NULL) {
      fputs(line, ofp);
    }
    */
  }
}