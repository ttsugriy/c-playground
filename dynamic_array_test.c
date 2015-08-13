#include "dynamic_array.h"
#include <assert.h>

void test(void (*verifier)(DynamicArray *)) {
  DynamicArray *array = dynamic_array_create();
  verifier(array);
  dynamic_array_destroy(array);
}

void new_array_is_empty(DynamicArray *array) {
  assert(dynamic_array_size(array) == 0);
}

void can_add_element(DynamicArray *array) {
  dynamic_array_add(array, 1);
  assert(dynamic_array_size(array) == 1);
  assert(dynamic_array_get(array, 0) == 1);
}

void size_is_updated_on_add_remove(DynamicArray *array) {
  size_t total = 50;
  for (size_t i = 0; i < total; ++i) {
    dynamic_array_add(array, (DynamicArrayItem) i);
    assert(!dynamic_array_empty(array));
    assert(dynamic_array_size(array) == i + 1);
    assert(dynamic_array_get(array, i) == i);
  }
  for (size_t i = 0; i < total; ++i) {
    dynamic_array_remove_at(array, 0);
    assert(dynamic_array_size(array) == (total - i - 1));
  }
  assert(dynamic_array_empty(array));
}

void can_remove_single_item(DynamicArray *array) {
  dynamic_array_add(array, 1);
  dynamic_array_remove_at(array, 0);
  assert(dynamic_array_empty(array));
}

void can_remove_last_item(DynamicArray *array) {
  dynamic_array_add(array, 1);
  dynamic_array_add(array, 2);
  assert(dynamic_array_size(array) == 2);
  dynamic_array_remove_at(array, 1);
  assert(dynamic_array_size(array) == 1);
  assert(dynamic_array_get(array, 0) == 1);
}

void can_remove_first_item(DynamicArray *array) {
  dynamic_array_add(array, 1);
  dynamic_array_add(array, 2);
  assert(dynamic_array_size(array) == 2);
  dynamic_array_remove_at(array, 0);
  assert(dynamic_array_size(array) == 1);
  assert(dynamic_array_get(array, 0) == 2);
}

int main(int argc, char *argv[]) {
  test(new_array_is_empty);
  test(can_add_element);
  test(size_is_updated_on_add_remove);
  test(can_remove_single_item);
  test(can_remove_last_item);
  test(can_remove_first_item);
  return 0;
}