#include "evaluation.h"
#include <assert.h>

void test_simple() {
  assert(evaluate_postfix("1") == 1);
  assert(evaluate_postfix("11") == 11);
}

void test_addition() {
  assert(evaluate_postfix("2 3 +") == 5);
}

void test_subtraction() {
  assert(evaluate_postfix("2 3 -") == -1);
}

void test_multiplication() {
  assert(evaluate_postfix("3 4 *") == 12);
}

void test_division() {
  assert(evaluate_postfix("12 4 /") == 3);
}

void test_complex() {
  assert(evaluate_postfix("1 2 + 12 3 / -") == -1);
}

int main(int argc, char * argv[]) {
  test_simple();
  test_addition();
  test_subtraction();
  test_multiplication();
  test_division();
  test_complex();
  return 0;
}

