#include "dynamic_array.h"
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

const int RESIZE_FACTOR = 2;

DynamicArray *dynamic_array_create() {
  DynamicArray *array = malloc(sizeof(DynamicArray));
  assert(array);
  array->capacity = 1;
  array->size = 0;
  array->items = malloc(array->capacity * sizeof(DynamicArrayItem));
  assert(array->items);
  return array;
}

size_t dynamic_array_capacity(const DynamicArray *array) {
  assert(array);
  return array->capacity;
}

void dynamic_array_resize(DynamicArray *array, size_t new_capacity) {
  assert(array);
  array->items = realloc(
      array->items, new_capacity * sizeof(DynamicArrayItem)
  );
  array->capacity = new_capacity;
  assert(array->items);
}

void dynamic_array_add(
    DynamicArray *array, const DynamicArrayItem item
) {
  assert(array);
  if (dynamic_array_size(array) == dynamic_array_capacity(array)) {
    dynamic_array_resize(
        array, dynamic_array_capacity(array) * RESIZE_FACTOR
    );
  }
  array->items[array->size++] = item;
}

void dynamic_array_remove_at(DynamicArray *array, size_t position) {
  assert(array);
  assert(position < dynamic_array_size(array));
  memcpy(
      array->items + position,
      array->items + position + 1,
      dynamic_array_size(array) - position + 1
  );
  array->size -= 1;
  if (dynamic_array_size(array) < dynamic_array_capacity(array) / 2) {
    dynamic_array_resize(array, dynamic_array_capacity(array) / 2);
  }
}

size_t dynamic_array_size(const DynamicArray *array) {
  assert(array);
  return array->size;
}

bool dynamic_array_empty(const DynamicArray *array) {
  assert(array);
  return dynamic_array_size(array) == 0;
}

DynamicArrayItem dynamic_array_get(const DynamicArray *array, size_t position) {
  assert(array);
  assert(position < array->size);
  return array->items[position];
}

void dynamic_array_set(
    const DynamicArray *array, size_t position, const DynamicArrayItem item
) {
  assert(array);
  assert(position < array->size);
  array->items[position] = item;
}

void dynamic_array_destroy(DynamicArray *array) {
  if (!array) {
    return;
  }
  free(array->items);
  free(array);
}
