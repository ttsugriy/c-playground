#pragma once


// evaluates postfix expression like and returns the result.
// Example:
//   evaluate_postfix("2 3 +"); ==> 5
// Note: input is expected to be a valid non-empty postfix expression.
int evaluate_postfix(const char* expression);