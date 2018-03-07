#include <stdio.h>
#include <stdlib.h>

#define BIGINT long long int

int compare(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int main(void) {
  static BIGINT minDotproduct;

  int vectorSize;
  scanf("%d", &vectorSize);

  int vector1[vectorSize];
  for (int counter = 0; counter < vectorSize; counter++)
    scanf("%d", &vector1[counter]);

  int vector2[vectorSize];
  for (int counter = 0; counter < vectorSize; counter++)
    scanf("%d", &vector2[counter]);

  qsort(vector1, vectorSize, sizeof(int), compare);
  qsort(vector2, vectorSize, sizeof(int), compare);

  for (int index1 = 0, index2 = vectorSize - 1; index1 < vectorSize;
       index1++, index2--) {
    minDotproduct += vector1[index1] * vector2[index2];
  }

  printf("%lld\n", minDotproduct);

  return EXIT_SUCCESS;
}
