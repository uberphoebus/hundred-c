#include <stdio.h>
#include <string.h>
#include <malloc.h>

// src -> dest
char * my_strcpy(char *dest, const char *src) {
  dest = (char *)malloc(strlen(src) + 1);
  int i = 0;
  while (dest[i] = src[i]) {
    i++;
  }
  dest[i] = '\0';
  return dest;
}

char * my_strcat(char *str1, char *str2) {
  char *result = (char *)malloc(strlen(str1) + strlen(str2) + 1); // 메모리 할당
  int i = 0;

  // str1 복사
  while (str1[i] != '\0') {
    result[i] = str1[i];
    i++;
  }

  char *ptr = result + strlen(str1); // str1의 끝부분부터 시작

  // str2 복사
  while (*str2 != '\0') {
    *ptr++ = *str2++;
  }
  *ptr = '\0'; // 문자열 끝에 '\0' 추가
  return result;
}

int main() {
  char s[] = "Hello World!";
  char *t = NULL;
  char u[] = "C Programming language";

  t = my_strcpy(t, s);
  printf("my_strcpy() : %s -> %s\n", s, t);
  printf("my_strcat() : %s + %s -> %s\n", s, u, my_strcat(s, u));
}