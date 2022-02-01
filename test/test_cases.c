//
// file: test_cases.c
// author: Michael Brockus
// gmail: <michaelbrockus@gmail.com>
//
// USE CASE:
//
// The use case of this file is to contain the test cases needed by this
// project since its important to test once implementation against a set
// of common test cases
//
#include "miok/queue.h"
#include <unity.h>

//
// test var used to run test cases this package
// is being ran with.
//
QueueOf *queue;

//
//  project setup teardown functions if needed
//
void setUp(void)
{
    queue = miok_queue_create();
} // end of function setUp

void tearDown(void)
{
    miok_queue_erase(&queue);
} // end of function tearDown

//
// list of all the test cases for this project
//
static void test_miok_queue_push(void)
{
    TEST_ASSERT_NOT_NULL(queue);
    miok_queue_push(queue, "2021");
    TEST_ASSERT_EQUAL_STRING("2021", miok_queue_peek(queue));

    miok_queue_push(queue, "2077");
    miok_queue_push(queue, "2010");
    TEST_ASSERT_EQUAL_STRING("2021", miok_queue_peek(queue));
} // end of test case

static void test_miok_queue_push_with_nullptr(void)
{
    miok_queue_push(NULL, "2021");
    TEST_ASSERT_EQUAL_STRING(NULL, miok_queue_peek(queue));

    miok_queue_push(NULL, "2077");
    miok_queue_push(NULL, "2010");
    TEST_ASSERT_EQUAL_STRING(NULL, miok_queue_peek(queue));
} // end of test case

static void test_miok_queue_pop(void)
{
    TEST_ASSERT_NOT_NULL(queue);
    miok_queue_push(queue, "red amphibian");
    miok_queue_push(queue, "blue amphibian");
    miok_queue_push(queue, "black amphibian");
    miok_queue_push(queue, "green amphibian");
    miok_queue_push(queue, "yellow amphibian");

    TEST_ASSERT_EQUAL_STRING("red amphibian", miok_queue_peek(queue));
    miok_queue_pop(queue);
    TEST_ASSERT_EQUAL_STRING("blue amphibian", miok_queue_peek(queue));
    miok_queue_pop(queue);
    TEST_ASSERT_EQUAL_STRING("black amphibian", miok_queue_peek(queue));

} // end of test case

static void test_miok_queue_pop_with_nullptr(void)
{
    miok_queue_push(NULL, "red amphibian");
    miok_queue_push(NULL, "blue amphibian");
    miok_queue_push(NULL, "black amphibian");

    TEST_ASSERT_EQUAL_STRING(NULL, miok_queue_peek(queue));
    miok_queue_pop(queue);
    TEST_ASSERT_EQUAL_STRING(NULL, miok_queue_peek(queue));
} // end of test case

static void test_miok_queue_its_empty(void)
{
    TEST_ASSERT_NOT_NULL(queue);
    TEST_ASSERT_TRUE(miok_queue_its_empty(queue));
    miok_queue_push(queue, "red amphibian");
    TEST_ASSERT_FALSE(miok_queue_its_empty(queue));

    TEST_ASSERT_EQUAL_STRING("red amphibian", miok_queue_peek(queue));
} // end of test case

static void test_miok_queue_its_empty_with_nullptr(void)
{
    miok_queue_push(NULL, "red amphibian");
    TEST_ASSERT_TRUE(miok_queue_its_empty(queue));

    TEST_ASSERT_EQUAL_STRING(NULL, miok_queue_peek(queue));
} // end of test case

static void test_miok_queue_not_empty(void)
{
    TEST_ASSERT_NOT_NULL(queue);
    TEST_ASSERT_FALSE(miok_queue_not_empty(queue));
    miok_queue_push(queue, "red amphibian");
    TEST_ASSERT_TRUE(miok_queue_not_empty(queue));

    TEST_ASSERT_EQUAL_STRING("red amphibian", miok_queue_peek(queue));
} // end of test case

static void test_miok_queue_not_empty_with_nullptr(void)
{
    miok_queue_push(NULL, "red amphibian");
    TEST_ASSERT_FALSE(miok_queue_not_empty(queue));

    TEST_ASSERT_EQUAL_STRING(NULL, miok_queue_peek(queue));
} // end of test case

//
//  here main is used as the test runner
//
int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_miok_queue_push);
    RUN_TEST(test_miok_queue_pop);
    RUN_TEST(test_miok_queue_its_empty);
    RUN_TEST(test_miok_queue_not_empty);
    RUN_TEST(test_miok_queue_push_with_nullptr);
    RUN_TEST(test_miok_queue_pop_with_nullptr);
    RUN_TEST(test_miok_queue_its_empty_with_nullptr);
    RUN_TEST(test_miok_queue_not_empty_with_nullptr);

    return UNITY_END();
} // end of function main
