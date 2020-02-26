// Gordon Zuehlke 2/22/20

#include <memory>
#include "gtest/gtest.h"
#include "util/utilities.h"
#include "agent/percept.h"

using namespace::testing;

class TestUtilities: public Test {
public:
    TestUtilities() : key1{"key55"}, val1{"value55"},
                      key2{"key66"}, val2{"value66"},
                      key3{"key77"}, val3{547996},
                      key4{"key88"}, val4{false} {

        attribMap.emplace(0, 2);
        attribMap.emplace("key1", "val1");
        attribMap.emplace("key2", true);
        attribMap.emplace(key1, val1);
        attribMap.emplace(key2, val2);
        attribMap.emplace(key3, val3);
        attribMap.emplace(key4, val4);
    }
 
    Attribute key1, val1, key2, val2, key3, val3, key4, val4;
    attribute_map attribMap;
    attribute_map::iterator it;   
    std::stringstream str_out;
};

TEST_F(TestUtilities, test_attribute_map) {
    EXPECT_TRUE(attribMap.size() == 7);

}
 
