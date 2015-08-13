#include "dynamic_array_stack.h"
#include "assert.h"

typedef DynamicArrayStack Stack;

void test(void (*verifier)(Stack *)) {
  Stack *stack = dynamic_array_stack_create();
  verifier(stack);
  dynamic_array_stack_destroy(stack);
}

void stack_is_empty_on_creation(Stack *stack) {
  assert(dynamic_array_stack_empty(stack) && "Stack is not empty");
}

void stack_is_not_empty_after_push(Stack *stack) {
  dynamic_array_stack_push(stack, 1);
  assert(!dynamic_array_stack_empty(stack) && "Stack is empty");
}

void stack_size_is_updated_after_push_and_pop(Stack *stack) {
  int total = 50;
  assert(dynamic_array_stack_empty(stack) && "Stack must be empty");
  for (int i = 1; i <= total; ++i) {
    dynamic_array_stack_push(stack, i);
    assert(!dynamic_array_stack_empty(stack) && "Stack must not be empty");
    assert(dynamic_array_stack_top(stack) == i && "Wrong top");
    assert(dynamic_array_stack_size(stack) == i && "Wrong size");
  }
  for (int i = total; i > 0; --i) {
    dynamic_array_stack_pop(stack);
    assert(dynamic_array_stack_size(stack) == (i - 1) && "Wrong size");
  }
  assert(dynamic_array_stack_empty(stack) && "Stack must be empty");
}

int main(int argc, char *argv[]) {
  test(stack_is_empty_on_creation);
  test(stack_is_not_empty_after_push);
  test(stack_size_is_updated_after_push_and_pop);
  return 0;
}
