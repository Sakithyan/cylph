#include <stddef.h>

#include "unity.h"
#include "cylph.h"

void setUp(void) {}
void tearDown(void) {}

static void test_create_and_free(void) {
    Array *a = array_create(5);
    TEST_ASSERT_NOT_NULL(a);
    array_free(a);
}

static void test_create_empty(void) {
    Array *a = array_create(0);
    TEST_ASSERT_NOT_NULL(a);
    array_free(a);
}

static void test_free_null_is_safe(void) {
    array_free(NULL);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_create_and_free);
    RUN_TEST(test_create_empty);
    RUN_TEST(test_free_null_is_safe);
    return UNITY_END();
}
