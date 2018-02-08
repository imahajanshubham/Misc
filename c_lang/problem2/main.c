#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int occurOfQuestion = 0;
  int inpQuestionCount = 0;

  int noOfStudents;
  int noOfQuestions;

  // Input initial values.
  scanf("%d %d", &noOfQuestions, &noOfStudents);

  int inputBuffer[noOfQuestions];

  for (int counter = 0; counter < noOfQuestions; counter++) {
    // Input the no of times, a question has appeared.
    scanf("%d", &inputBuffer[counter]);

    inpQuestionCount += inputBuffer[counter];

    // If the total no. of occurences of ith question is 'not' less/equal to the
    // specified limit, then update the no. of occurences.
    if (occurOfQuestion < inputBuffer[counter]) {
      occurOfQuestion = inputBuffer[counter];
    }
  }

  // TEST COND #2: No two consecutively numbered students should get same
  // question to solve.
  if (noOfStudents % 2 != 0) {
    noOfStudents++;
    inpQuestionCount++;
  }

  int totalQuestions = 2 * occurOfQuestion;

  // TEST COND #1: ith question should be asked to exactly Ai students.
  // i.e. no. of questions == no. of students.
  if (totalQuestions <= noOfStudents && inpQuestionCount == noOfStudents)
    puts("YES");

  else
    puts("NO");

  return EXIT_SUCCESS;
}
