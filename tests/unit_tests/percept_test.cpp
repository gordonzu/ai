// Gordon Zuehlke 2/22/20

#include <memory>
#include "gtest/gtest.h"
#include "agent/percept.h"

using namespace::testing;

class TestPercept: public Test {
public:
    TestPercept() : 
        key1{"key1"}, val1{"value1"}, 
        key2{"key2"}, val2{999999},
        key3{"key3"}, val3{true} {}

	Attribute key1, val1, key2, val2, key3, val3;
};

TEST_F(TestPercept, testString) {
    auto str = "Percept[key1=value1]";
    Percept percept1{key1, val1};
    EXPECT_STREQ(print_string(percept1).c_str(), str);

    auto str2 = "Percept[key1=value1, key2=999999]";
    Percept percept2{key1, val1, key2, val2};
    EXPECT_STREQ(print_string(percept2).c_str(), str2);

    auto str3 = "Percept[key3=true]";
    Percept percept3{key3, val3};
    EXPECT_STREQ(print_string(percept3).c_str(), str3);
}

TEST_F(TestPercept, testEquals) {
    Percept p3;
    Percept p4;
    EXPECT_TRUE(p3 == p4);
    Percept p5{key1, val1};
    EXPECT_FALSE(p3 == p5);
    Percept p6{key1, val1};
    EXPECT_TRUE(p6 == p5);
}






