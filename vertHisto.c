// -----An attempt to print Vertical Histogram----- //

#include <stdio.h>
// #include <conio.h>

// -----Extra variables used----- //
int row = 0, colm = 0, j;
char array[10][10], transpose[10][10];

int main() {
  int i;

  while ((i = getchar()) != '\n') // EOF )
  {
    if (i == ' ' || i == '\t') {
      // printf("\n");
      colm = 0;
      row++;
    } else {
      // printf("*");
      array[row][colm] = '#';
      colm++;
    }
  }

  // -----Transpose of an Array----- //
  for (i = 0; i < 10; ++i)
    for (j = 0; j < 10; ++j)
      transpose[i][j] = array[j][i];

  // -----Reverse Display of an Array----- //
  // -----$ Ignore how printf is written-- //
  for (i = 9; i >= 0; i--)
    for (j = 9; j >= 0; j--)
      printf(j == 0 ? "%c\n" : "%c", transpose[i][j]);

  return 0;
}
