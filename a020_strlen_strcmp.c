#include <stdio.h>
#include <string.h>

size_t my_strlen(const char *s) {
  size_t i = 0;

  // 문자열의 끝을 만날 때까지 반복 -> '\0'이면 i를 반환
  while (s[i] != '\0') {
    i++;
  }
  return i;
}

size_t my_strlen2(const char *s) {
  const char *p = s;

  // 문자열의 끝을 만날 때까지 반복 -> '\0'이면 p - s를 반환
  while (*p != '\0') {
    p++;
  }
  return p - s;
}

int my_strcmp(const char *s, const char *t) {
  int i;

  // 두 문자열을 비교해서 다른 문자가 나오면 break
  for (i = 0; s[i] != '\0' && t[i] != '\0'; i++) {
    if (s[i] != t[i]) {
      break;
    }
  }

  if (s[i] > t[i]) {
    return 1;
  } else if (s[i] == t[i]) {
    return 0;
  } else {
    return -1;
  }
}

int main() {
  char s[] = "Hello World!";
  char t[] = "hello World!";

  printf("strlen(s)     = %ld\n", strlen(s));
  printf("my_strlen(s)  = %ld\n", my_strlen(s));
  printf("my_strlen2(s) = %ld\n", my_strlen2(s));

  printf("strcmp(s, t)    = %d\n", strcmp(s, t));
  printf("my_strcmp(s, t) = %d\n", my_strcmp(s, t));
}