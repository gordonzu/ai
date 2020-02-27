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

TEST_F(TestUtilities, test_size) {
    EXPECT_TRUE(attribMap.size() == 7);
}
 
TEST_F(TestUtilities, test_integerkey_lookup) {
    it = attribMap.find(0);
    str_out << it->first << ", " << it->second;
    EXPECT_STREQ(str_out.str().c_str(), "0, 2");
}

TEST_F(TestUtilities, test_stringLiteral_key_lookup) {
    it = attribMap.find("key1");
    str_out << it->first << ", " << it->second;
    EXPECT_STREQ(str_out.str().c_str(), "key1, val1");
}

TEST_F(TestUtilities, test_retrieve_boolean_attribute) {
    it = attribMap.find("key2");
    str_out << it->first << ", " << it->second;
    EXPECT_STREQ(str_out.str().c_str(), "key2, true");
}

TEST_F(TestUtilities, test_stringVariable_key_lookup) {
    it = attribMap.find(key1);
    str_out << it->first << ", " << it->second;
    EXPECT_STREQ(str_out.str().c_str(), "key55, value55");
}

TEST_F(TestUtilities, test_map_string_representation) {
    std::string strMap = "<map>\n";
    strMap += "  key: 0, value: 2\n"; 
    strMap += "  key: key1, value: val1\n"; 
    strMap += "  key: key2, value: true\n"; 
    strMap += "  key: key55, value: value55\n"; 
    strMap += "  key: key66, value: value66\n"; 
    strMap += "  key: key77, value: 547996\n"; 
    strMap += "  key: key88, value: false\n"; 
    strMap += "</map>\n";

    EXPECT_TRUE(attribMap.size() == 7);
    auto str = ut::map_to_string(attribMap);
    EXPECT_STREQ(strMap.c_str(), str.c_str());
}
































