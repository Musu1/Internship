#include "../Src/function.c"
#include "../Src/unity.h"
#include "../Src/unity_internals.h"

void test_Add(void)
{
  TEST_ASSERT_EQUAL(15, add(7,8));
}
int main(void)
{
  UNITY_BEGIN();
  RUN_TEST(test_Add);
  return UNITY_END();
}
