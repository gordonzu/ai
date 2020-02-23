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

TEST_F(TestPercept, testString)
{/*
    auto str = "Percept[key1=value1]";
    Percept percept1{key1, val1};
    ASSERT_STREQ(print_string(percept1).c_str(), str);

    auto str2 = "Percept[key1=value1, key2=999999]";
    Percept percept2{key1, val1, key2, val2};
    ASSERT_STREQ(print_string(percept2).c_str(), str2);

    auto str3 = "Percept[key3=true]";
    Percept percept3{key3, val3};
    ASSERT_STREQ(print_string(percept3).c_str(), str3);*/
}


