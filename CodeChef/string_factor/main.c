#include <stdio.h>
#include <stdlib.h>

int main(void) {
  // SUBTASK COND #1: 'S' i.e array size <= 10000.
  char inputBuffer[100001];

  // TASK COND #1: Input 't' - no. of test cases.
  int noOfTestCases;
  scanf("%d", &noOfTestCases);

  for (int testNo = 0; testNo < noOfTestCases; testNo++) {
    // TASK COND #2: Input a string in Binary Form.
    // Ex.: 0101111011
    scanf("%100000s", inputBuffer);

    // Factor of string is defined as a substring.
    // In this case it's '01'.
    int noOfFactors = 0;

    // Finding the no. of factors (occurences) of "01" in the given binary
    // string.
    for (int counter = 0; inputBuffer[counter] != '\0'; counter++) {
      if (inputBuffer[counter] == '0' &&
          inputBuffer[counter + 1] == '1')
        noOfFactors++;
    }

    printf("%d\n", noOfFactors);
  }

  return EXIT_SUCCESS;
}
