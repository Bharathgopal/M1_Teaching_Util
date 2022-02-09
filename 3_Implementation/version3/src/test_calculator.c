#include "unity.h"
#include "calculator.h"

void setUp()
{
}

void tearDown()
{
}

void test_complex_divide()
{
    struct complex_number cn1 = {1,1};
    struct complex_number cn2 = {1,1};
    struct complex_number actual_result = {0,0};

    struct complex_number expected_result = {1,0};

    TEST_ASSERT_EQUAL(success, complex_divide(cn1, cn2, &actual_result));
    TEST_ASSERT_EQUAL(expected_result.real, actual_result.real);
    TEST_ASSERT_EQUAL(expected_result.imaginary, actual_result.imaginary +1);

}
void test_complex_divide_null()
{
    struct complex_number cn1 = {1,1};
    struct complex_number cn2 = {1,1};
    struct complex_number actual_result = {0,0};

    struct complex_number expected_result = {1,0};

    TEST_ASSERT_EQUAL(success, complex_divide(cn1, cn2, NULL));
    TEST_ASSERT_EQUAL(expected_result.real, actual_result.real);
    TEST_ASSERT_EQUAL(expected_result.imaginary, actual_result.imaginary +1);

}

void test_complex_add()
{
    //TODO Logic
}

int test_main()
{
    /* Initiate the Unity Test Framework */
    UNITY_BEGIN();

    RUN_TEST(test_complex_divide);
    RUN_TEST(test_complex_add);

    return UNITY_END();
}