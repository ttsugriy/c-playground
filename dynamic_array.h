#pragma once

#include <stddef.h>
#include <stdbool.h>

typedef int DynamicArrayItem;

typedef struct DynamicArray {
  size_t size;
  size_t capacity;
  DynamicArrayItem *items;
} DynamicArray;

DynamicArray *dynamic_array_create();

void dynamic_array_add(DynamicArray *array, const DynamicArrayItem item);

void dynamic_array_remove_at(DynamicArray *array, size_t position);

size_t dynamic_array_size(const DynamicArray *array);

bool dynamic_array_empty(const DynamicArray *array);

DynamicArrayItem dynamic_array_get(const DynamicArray *array, size_t position);

void dynamic_array_set(
    const DynamicArray *array, size_t position, const DynamicArrayItem item
);

void dynamic_array_destroy(DynamicArray *array);