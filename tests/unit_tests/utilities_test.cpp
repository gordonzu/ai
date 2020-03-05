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

        attribs.emplace(0, 2);
        attribs.emplace("key1", "val1");
        attribs.emplace("key2", true);
        attribs.emplace(key1, val1);
        attribs.emplace(key2, val2);
        attribs.emplace(key3, val3);
        attribs.emplace(key4, val4);
    }

 
    Attribute key1, val1, key2, val2, key3, val3, key4, val4;
    AttribMap attribs;
    AttribMap::iterator it;   
    std::stringstream str_out;
};

TEST_F(TestUtilities, test_size) {
    EXPECT_TRUE(attribs.size() == 7);
}
 
TEST_F(TestUtilities, test_integerkey_lookup) {
    it = attribs.find(0);
    str_out << it->first << ", " << it->second;
    EXPECT_STREQ(str_out.str().c_str(), "0, 2");
}

TEST_F(TestUtilities, test_stringLiteral_key_lookup) {
    it = attribs.find("key1");
    str_out << it->first << ", " << it->second;
    EXPECT_STREQ(str_out.str().c_str(), "key1, val1");
}

TEST_F(TestUtilities, test_retrieve_boolean_attribute) {
    it = attribs.find("key2");
    str_out << it->first << ", " << it->second;
    EXPECT_STREQ(str_out.str().c_str(), "key2, true");
}

TEST_F(TestUtilities, test_stringVariable_key_lookup) {
    it = attribs.find(key1);
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

    EXPECT_TRUE(attribs.size() == 7);
    auto str = ut::map_to_string(attribs);
    EXPECT_STREQ(strMap.c_str(), str.c_str());
}

namespace t {
    Attribute key{"key365"};

    auto return_key1(bool b) {
        return b ? std::optional<Attribute>(key) : std::nullopt;
    }

    auto return_key2(bool b) {
        return b ? std::optional<Attribute>("key") : std::nullopt;
    }
     
    auto return_key3(bool b) {
        return b ? std::optional<Attribute>(true) : std::nullopt;
    }
}

TEST_F(TestUtilities, test_bool_attributes) {
    std::optional<Attribute> retval = t::key;
    EXPECT_TRUE(retval);

    EXPECT_TRUE(t::return_key1(true)); 
    EXPECT_FALSE(t::return_key1(false)); 

    EXPECT_TRUE(t::return_key2(true));
    EXPECT_FALSE(t::return_key2(false));

    EXPECT_TRUE(t::return_key3(true));
    EXPECT_FALSE(t::return_key3(false));
}

TEST_F(TestUtilities, test_string_attributes) {
    std::vector<Attribute> vec;

    vec.emplace_back(Percept{"key1", "value1"});
    EXPECT_STREQ(print_string(vec[0]).c_str(), "Percept[key1=value1]");

    vec.emplace_back(Percept{key2, val2});
    EXPECT_STREQ(print_string(vec[1]).c_str(), "Percept[key66=value66]");

    const char* vstr = 
        "Percept[key1=value1], " 
        "Percept[key66=value66], "
        "Percept[6758=false], "  
        "Percept[key3=true], "
        "Percept[key4=99973879]"; 

    vec.emplace_back(Percept{6758, false});
    vec.emplace_back(Percept{"key3", true});
    vec.emplace_back(Percept{"key4", 99973879});

    EXPECT_STREQ(ut::print_vec(vec).c_str(), vstr);
}



























