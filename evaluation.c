#include "evaluation.h"
#include "dynamic_array_stack.h"
#include <assert.h>
#include <math.h>

const int NOT_SET = -1;
const int BASE = 10;

int is_digit(const char ch) {
  return ch >= '0' && ch <= '9';
}

int to_digit_int(const char ch) {
  assert(is_digit(ch));
  return ch - '0';
}

int is_operation(const char ch) {
  return ch == '+' || ch == '-' || ch == '/' || ch == '*';
}

int max(int a, int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

int apply(const char operation, const int operand1, const int operand2) {
  assert(is_operation(operation));
  switch (operation) {
    case '+':
      return operand1 + operand2;
    case '-':
      return operand1 - operand2;
    case '/':
      return operand1 / operand2;
    case '*':
      return operand1 * operand2;
    default:
      assert(0);
  }
}

int evaluate_postfix(const char* expression) {
  assert(expression);
  int operand = NOT_SET;
  DynamicArrayStack* stack = dynamic_array_stack_create();
  const char* temp = expression;
  do {
    const char ch = *temp;
    if (is_digit(ch)) {
      operand = max(to_digit_int(ch), operand * BASE + to_digit_int(ch));
    } else if (ch == ' ' || ch == '\0') {
      if (operand != NOT_SET) {
        dynamic_array_stack_push(stack, operand);
        operand = NOT_SET;
      }
    } else {
      assert(is_operation(ch));
      const int operand2 = dynamic_array_stack_top(stack);
      dynamic_array_stack_pop(stack);
      const int operand1 = dynamic_array_stack_top(stack);
      dynamic_array_stack_pop(stack);
      dynamic_array_stack_push(stack, apply(ch, operand1, operand2));
    }
  } while (*(temp++) != '\0');
  assert(operand == NOT_SET);
  assert(dynamic_array_stack_size(stack) == 1);
  const int result = dynamic_array_stack_top(stack);
  dynamic_array_stack_destroy(stack);
  return result;
}
