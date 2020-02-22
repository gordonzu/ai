// gordon zuehlke 2/21/20
// Test class for XYEnvironment

#include "gtest/gtest.h"

using namespace::testing;

class TestXYEnvironment: public Test {
public:
    TestXYEnvironment() {}
};

TEST_F(TestXYEnvironment, test_equals) {
    EXPECT_EQ(1, 1);
}
