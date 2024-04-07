#include <stdio.h>
#include <string.h>

char *my_reverse(char *s) {
  char *end = s + strlen(s) - 1;

  // 문자열의 시작과 끝을 가리키는 포인터를 이용해서 문자열을 뒤집는다.
  for (char *ptr = s; ptr < end; ptr++, end--) {
    char tmp = *ptr; // ptr이 가리키는 값을 tmp에 저장
    *ptr = *end; // ptr이 가리키는 값을 end가 가리키는 값으로 변경
    *end = tmp; // end가 가리키는 값을 tmp로 변경
  }
  return s;
}

int main() {
  char s[] = "Hello, World!";
  // printf("_strrev()    : %s\n", _strrev(s));
  printf("my_reverse() : %s\n", my_reverse(s));
  return 0;
}