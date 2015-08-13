#include "dynamic_array_stack.h"

#include <stdlib.h>
#include <assert.h>

typedef DynamicArrayStackItem Item;
typedef struct DynamicArrayStack Stack;

Stack *dynamic_array_stack_create() {
  Stack *stack = malloc(sizeof(Stack));
  assert(stack);
  stack->array = dynamic_array_create();
  return stack;
}

size_t dynamic_array_stack_size(const Stack *stack) {
  assert(stack);
  return dynamic_array_size(stack->array);
}

int dynamic_array_stack_empty(const Stack *stack) {
  assert(stack);
  return dynamic_array_stack_size(stack) == 0;
}

Item dynamic_array_stack_top(Stack *stack) {
  assert(!dynamic_array_stack_empty(stack));
  size_t last_idx = dynamic_array_size(stack->array) - 1;
  return dynamic_array_get(stack->array, last_idx);
}

void dynamic_array_stack_pop(Stack *stack) {
  assert(stack);
  assert(!dynamic_array_stack_empty(stack));
  size_t last_idx = dynamic_array_size(stack->array) - 1;
  dynamic_array_remove_at(stack->array, last_idx);
}

void dynamic_array_stack_push(Stack *stack, Item item) {
  assert(stack);
  dynamic_array_add(stack->array, item);
}

void dynamic_array_stack_destroy(Stack *stack) {
  dynamic_array_destroy(stack->array);
  free(stack);
}
