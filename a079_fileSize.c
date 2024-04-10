#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
  int fsize;
  FILE *fp = fopen("../test.txt", "r");
  fseek(fp, 0, SEEK_END); // 파일 포인터를 파일의 끝으로 이동

  fsize = ftell(fp); // 파일 포인터의 위치를 알아냄
  printf("파일의 크기는 %d바이트입니다.\n", fsize);

  fseek(fp, 0, SEEK_SET); // 파일 포인터를 파일의 처음으로 이동
  printf("fp = %ld\n", ftell(fp)); // 파일 포인터의 위치를 알아냄

  fseek(fp, -10, SEEK_CUR); // 파일 포인터를 현재 위치에서 10바이트 앞으로 이동
  printf("fp = %ld\n", ftell(fp));

  fseek(fp, 10, SEEK_END);
  printf("fp = %ld\n", ftell(fp));

  fclose(fp);
}