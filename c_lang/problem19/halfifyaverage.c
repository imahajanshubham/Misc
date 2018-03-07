#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int lowerLimit;
  int upperLimit;

  int number;
  int average;

  scanf("%d %d", &lowerLimit, &upperLimit);

  for (number = lowerLimit; number <= upperLimit; number += 2) {
    if (number == lowerLimit)
      average = (number + (number + 1)) / 2;
    else {
      int tempAverage = (number + (number + 1)) / 2;
      average = (average + tempAverage) / 2;
    }
  }

  printf("%d\n", average);

  return EXIT_SUCCESS;
}
