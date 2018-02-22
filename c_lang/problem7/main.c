#include <stdio.h>
#include <stdlib.h>

#define NOOFALPHABETS 26
#define MAXLEN 100001

#define ASCIIOF_a 97
#define NEWLINE '\n'

static char inputString[MAXLEN] = "abcccc";

static long int occurrence[NOOFALPHABETS];
static long int hasSameFrequency;

long int noalpha = 97;

int main(void) {
  scanf("%100000s", inputString);

  for (long int indx = 0; inputString[indx] != '\0'; indx++)
    hasSameFrequency = ++occurrence[inputString[indx] - ASCIIOF_a];

  for (long int indx = 0; indx < NOOFALPHABETS; indx++) {
    if (occurrence[indx] && hasSameFrequency != occurrence[indx]) {
      puts("NO");
      return EXIT_SUCCESS;
    }
  }

  puts("YES");

  return EXIT_SUCCESS;
}
