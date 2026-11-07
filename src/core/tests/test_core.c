#include "unity.h"
#include "cylph.h"

void setUp(void) {}
void tearDown(void) {}

static void test_version_major_is_zero(void) {
    TEST_ASSERT_EQUAL_INT(0, cylph_version_major());
}

static void test_version_minor_is_one(void) {
    TEST_ASSERT_EQUAL_INT(1, cylph_version_minor());
}

static void test_version_patch_is_zero(void) {
    TEST_ASSERT_EQUAL_INT(0, cylph_version_patch());
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_version_major_is_zero);
    RUN_TEST(test_version_minor_is_one);
    RUN_TEST(test_version_patch_is_zero);
    return UNITY_END();
}