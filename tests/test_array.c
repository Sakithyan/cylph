#include <assert.h>
#include <stddef.h>

#include "cylph.h"

static void test_create_and_free(void) {
    Array *a = array_create(5);
    assert(a != NULL);
    array_free(a);
}

static void test_create_empty(void) {
    Array *a = array_create(0);
    assert(a != NULL);
    array_free(a);
}

static void test_free_null_is_safe(void) {
    array_free(NULL);
}

static void test_length(void) {
    Array *a = array_create(5);
    assert(array_length(a) == 5);
    array_free(a);

    Array *empty = array_create(0);
    assert(array_length(empty) == 0);
    array_free(empty);
}

static void test_new_elements_are_zero(void) {
    Array *a = array_create(3);
    double value = -1.0;
    for (size_t i = 0; i < 3; i++) {
        assert(array_get(a, i, &value) == 0);
        assert(value == 0.0);
    }
    array_free(a);
}

static void test_set_then_get(void) {
    Array *a = array_create(3);
    assert(array_set(a, 0, 1.5) == 0);
    assert(array_set(a, 2, -4.0) == 0);

    double value = 0.0;
    assert(array_get(a, 0, &value) == 0);
    assert(value == 1.5);
    assert(array_get(a, 1, &value) == 0);
    assert(value == 0.0);
    assert(array_get(a, 2, &value) == 0);
    assert(value == -4.0);
    array_free(a);
}

static void test_get_out_of_range(void) {
    Array *a = array_create(3);
    double value = 42.0;
    assert(array_get(a, 3, &value) == -1);
    assert(value == 42.0); /* out is left untouched on error */
    array_free(a);

    Array *empty = array_create(0);
    assert(array_get(empty, 0, &value) == -1);
    array_free(empty);
}

static void test_set_out_of_range(void) {
    Array *a = array_create(3);
    assert(array_set(a, 3, 7.0) == -1);
    assert(array_length(a) == 3); /* the array is unchanged */
    array_free(a);

    Array *empty = array_create(0);
    assert(array_set(empty, 0, 7.0) == -1);
    array_free(empty);
}

int main(void) {
    test_create_and_free();
    test_create_empty();
    test_free_null_is_safe();
    test_length();
    test_new_elements_are_zero();
    test_set_then_get();
    test_get_out_of_range();
    test_set_out_of_range();
    return 0;
}