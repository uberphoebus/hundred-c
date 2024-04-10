#define _CRT_SECURE_NO_WARNINGS
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  char *buffer;
  size_t fsize;

  FILE *fp = fopen("../test.txt", "rb");
  FILE *ofp = fopen("../output.txt", "wb");
  fseek(fp, 0, SEEK_END);
  fsize = ftell(fp);
  printf("sizeof file = %zu bytes\n", fsize);

  buffer = (char *)malloc(fsize);
  memset(buffer, 0, fsize);

  rewind(fp);                    // fseek(fp, 0, SEEK_SET);
  fread(buffer, fsize, 1, fp);   // fread(buffer, sizeof(char), count, fp);
  fwrite(buffer, fsize, 1, ofp); // fwrite(buffer, sizeof(char), count, ofp);

  fclose(fp);
  fclose(ofp);
  free(buffer);
  printf("file copy complete\n");
}