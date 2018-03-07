#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

int getNextInteger() {
  char character;
  int number = 0;

  while ((character = getchar()) != ' ' && character != '\n')
    number = (number * 10) + (character - '0');

  return number;
}

int *getNewArray(int size) {
  int *inputBuffer;
  inputBuffer = (int *)malloc(size * sizeof(int));

  return inputBuffer;
}

int getLeastValue() {
  int *inputBuffer;
  int currentInteger;
  scanf("%d", &currentInteger);

  inputBuffer = getNewArray(currentInteger);
  inputBuffer[0] = getNextInteger();

  int minimumNumber = 0;

  for (int counter = 1; counter < currentInteger; counter++) {
    scanf("%d", &inputBuffer[counter]);
    if (inputBuffer[minimumNumber] > inputBuffer[counter])
      minimumNumber = counter;
  }

  free(inputBuffer);

  return (minimumNumber + 1);
}

int main(void) {
  printf("%d", getLeastValue());
  return EXIT_SUCCESS;
}
