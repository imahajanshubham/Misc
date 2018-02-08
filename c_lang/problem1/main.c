#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // SUBTASK #1: Max array size - 100000.
  char inputBuffer[100001];

  int noOfTestCases;
  scanf("%d", &noOfTestCases);

  for (int testNo = 0; testNo < noOfTestCases; testNo++) {
    scanf("%100000s", inputBuffer);

    int noOfFactors = 0;

    for (int counter = 0; inputBuffer[counter] != '\0'; counter++) {
      if (inputBuffer[counter] == '0' &&
          inputBuffer[counter + 1] == '1')
        noOfFactors++;
    }

    printf("%d\n", noOfFactors);
  }

  return EXIT_SUCCESS;
}
