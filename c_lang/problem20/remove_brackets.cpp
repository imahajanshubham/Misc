#include <bits/stdc++.h>

using namespace std;

#define PLUS_SIGN '+'
#define MINUS_SIGN '-'
#define OPENPARENS '('
#define CLOSEPARENS ')'

string expression;
int expressionLength;

char *finalExpression;
static int indx;
static int counter;

stack<int> inputStack;

void updateStackWithNewParens(void) {
  if (expression[counter - 1] == MINUS_SIGN) {
    int value = (inputStack.top() == 1) ? 0 : 1;
    inputStack.push(value);
  }
}

void evalParensWithMinusSign(void) {
  if (inputStack.top() == 1)
    finalExpression[indx++] = PLUS_SIGN;

  else if (inputStack.top() == 0)
    finalExpression[indx++] = MINUS_SIGN;
}

void evalParensWithPlusSign(void) {
  if (inputStack.top() == 1)
    finalExpression[indx++] = MINUS_SIGN;

  if (inputStack.top() == 0)
    finalExpression[indx++] = PLUS_SIGN;
}

void initValues(void) {
  expressionLength = expression.length();
  finalExpression = new char(expressionLength);

  inputStack.push(0);
}

char *rmParensFromExpr(void) {
  initValues();

  while (counter < expressionLength) {
    if (expression[counter] == PLUS_SIGN)
      evalParensWithPlusSign();

    else if (expression[counter] == MINUS_SIGN)
      evalParensWithMinusSign();

    else if (expression[counter] == OPENPARENS && counter > 0)
      updateStackWithNewParens();

    else if (expression[counter - 1] == PLUS_SIGN)
      inputStack.push(inputStack.top());

    else if (expression[counter] == CLOSEPARENS)
      inputStack.pop();

    else
      finalExpression[indx++] = expression[counter];

    counter++;
  }

  return finalExpression;
}

int main(void) {
  cin >> expression;
  cout << rmParensFromExpr();

  return 0;
}
