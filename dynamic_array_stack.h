#pragma once

#include <stddef.h>

typedef int DynamicArrayStackItem;

typedef struct DynamicArrayStack {
  int top;
  size_t capacity;
  DynamicArrayStackItem *items;
} DynamicArrayStack;

DynamicArrayStack* dynamic_array_stack_create();

size_t dynamic_array_stack_size(DynamicArrayStack* stack);

int dynamic_array_stack_empty(DynamicArrayStack* stack);

DynamicArrayStackItem dynamic_array_stack_top(DynamicArrayStack* stack);

size_t dynamic_array_stack_capacity(DynamicArrayStack* stack);

void dynamic_array_stack_pop(DynamicArrayStack* stack);

void dynamic_array_stack_push(
    DynamicArrayStack* stack, DynamicArrayStackItem item
);

void dynamic_array_stack_destroy(DynamicArrayStack* stack);

