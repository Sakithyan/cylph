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

static void test_length(void) {
    Array *a = array_create(5);
    TEST_ASSERT_EQUAL_size_t(5, array_length(a));
    array_free(a);

    Array *empty = array_create(0);
    TEST_ASSERT_EQUAL_size_t(0, array_length(empty));
    array_free(empty);
}

static void test_new_elements_are_zero(void) {
    Array *a = array_create(3);
    double value = -1.0;
    for (size_t i = 0; i < 3; i++) {
        TEST_ASSERT_EQUAL_INT(0, array_get(a, i, &value));
        TEST_ASSERT_EQUAL_DOUBLE(0.0, value);
    }
    array_free(a);
}

static void test_set_then_get(void) {
    Array *a = array_create(3);
    TEST_ASSERT_EQUAL_INT(0, array_set(a, 0, 1.5));
    TEST_ASSERT_EQUAL_INT(0, array_set(a, 2, -4.0));

    double value = 0.0;
    TEST_ASSERT_EQUAL_INT(0, array_get(a, 0, &value));
    TEST_ASSERT_EQUAL_DOUBLE(1.5, value);
    TEST_ASSERT_EQUAL_INT(0, array_get(a, 1, &value));
    TEST_ASSERT_EQUAL_DOUBLE(0.0, value);
    TEST_ASSERT_EQUAL_INT(0, array_get(a, 2, &value));
    TEST_ASSERT_EQUAL_DOUBLE(-4.0, value);
    array_free(a);
}

static void test_get_out_of_range(void) {
    Array *a = array_create(3);
    double value = 42.0;
    TEST_ASSERT_EQUAL_INT(-1, array_get(a, 3, &value));
    TEST_ASSERT_EQUAL_DOUBLE(42.0, value); /* out is left untouched on error */
    array_free(a);

    Array *empty = array_create(0);
    TEST_ASSERT_EQUAL_INT(-1, array_get(empty, 0, &value));
    array_free(empty);
}

static void test_set_out_of_range(void) {
    Array *a = array_create(3);
    TEST_ASSERT_EQUAL_INT(-1, array_set(a, 3, 7.0));
    TEST_ASSERT_EQUAL_size_t(3, array_length(a)); /* the array is unchanged */
    array_free(a);

    Array *empty = array_create(0);
    TEST_ASSERT_EQUAL_INT(-1, array_set(empty, 0, 7.0));
    array_free(empty);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_create_and_free);
    RUN_TEST(test_create_empty);
    RUN_TEST(test_free_null_is_safe);
    RUN_TEST(test_length);
    RUN_TEST(test_new_elements_are_zero);
    RUN_TEST(test_set_then_get);
    RUN_TEST(test_get_out_of_range);
    RUN_TEST(test_set_out_of_range);
    return UNITY_END();
}
