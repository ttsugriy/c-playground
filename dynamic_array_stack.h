#pragma once

#include "dynamic_array.h"
#include <stddef.h>

typedef int DynamicArrayStackItem;

typedef struct DynamicArrayStack {
    DynamicArray* array;
} DynamicArrayStack;

DynamicArrayStack *dynamic_array_stack_create();

size_t dynamic_array_stack_size(const DynamicArrayStack *stack);

int dynamic_array_stack_empty(const DynamicArrayStack *stack);

DynamicArrayStackItem dynamic_array_stack_top(DynamicArrayStack *stack);

void dynamic_array_stack_pop(DynamicArrayStack *stack);

void dynamic_array_stack_push(
        DynamicArrayStack *stack, DynamicArrayStackItem item
);

void dynamic_array_stack_destroy(DynamicArrayStack *stack);

