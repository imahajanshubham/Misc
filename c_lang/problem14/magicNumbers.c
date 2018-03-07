#include <stdio.h>
#include <stdlib.h>

#define MAX 500

int multiply(int localNumber, int value[], int noOfDigits) {
  int carry = 0;

  for (int indx = 0; indx < noOfDigits; indx++) {
    int prod = value[indx] * localNumber + carry;

    value[indx] = prod % 10;
    carry = prod / 10;
  }

  while (carry) {
    value[noOfDigits] = carry % 10;
    carry = carry / 10;

    noOfDigits++;
  }

  return noOfDigits;
}

int factorial(int number, int value[]) {
  value[0] = 1;
  int noOfDigits = 1;

  for (int localNumber = 2; localNumber <= number; localNumber++) {
    noOfDigits = multiply(localNumber, value, noOfDigits);
  }

  return noOfDigits;
}

int main(void) {
  int value[MAX];
  int noOfDigits;

  int number;
  scanf("%d", &number);

  noOfDigits = factorial(number, value);
  int tempNoOfDigits = noOfDigits;

  for (int counter = noOfDigits - 1; counter >= 0; counter--)
    printf("%d", value[counter]);

  printf(" %d", tempNoOfDigits);

  return EXIT_SUCCESS;
}
