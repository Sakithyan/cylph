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

int main(void) {
    test_create_and_free();
    test_create_empty();
    test_free_null_is_safe();
    return 0;
}