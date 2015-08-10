#include "dynamic_array_stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef DynamicArrayStackItem Item;
typedef struct DynamicArrayStack Stack;

Stack* dynamic_array_stack_create() {
  Stack* stack = malloc(sizeof(Stack));
  assert(stack);
  stack->capacity = 1;
  stack->top = -1;
  stack->items = malloc(stack->capacity * sizeof(Item));
  return stack;
}

size_t dynamic_array_stack_size(Stack* stack) {
  return stack->top + 1;
}

int dynamic_array_stack_full(Stack* stack) {
  return stack->capacity == dynamic_array_stack_size(stack);
}

int dynamic_array_stack_empty(Stack* stack) {
  return dynamic_array_stack_size(stack) == 0;
}

void dynamic_array_stack_resize(Stack* stack, size_t new_capacity) {
  stack->items = realloc(stack->items, new_capacity * sizeof(Item));
  assert(stack->items);
  stack->capacity = new_capacity;
}

Item dynamic_array_stack_top(Stack* stack) {
  assert(!dynamic_array_stack_empty(stack));
  return stack->items[stack->top];
}

size_t dynamic_array_stack_capacity(Stack* stack) {
  return stack->capacity;
}

void dynamic_array_stack_pop(Stack* stack) {
  assert(!dynamic_array_stack_empty(stack));
  stack->top -= 1;
  if (dynamic_array_stack_size(stack) < dynamic_array_stack_capacity(stack) / 2) {
    dynamic_array_stack_resize(stack, dynamic_array_stack_capacity(stack) / 2);
  }
}

void dynamic_array_stack_push(Stack* stack, Item item) {
  if (dynamic_array_stack_full(stack)) {
    dynamic_array_stack_resize(stack, dynamic_array_stack_capacity(stack) * 2);
  }
  stack->items[stack->top + 1] = item;
  stack->top += 1;
}

void dynamic_array_stack_destroy(Stack* stack) {
  free(stack->items);
  free(stack);
}
