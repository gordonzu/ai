// Gordon Zuehlke 2/27/20

#include "gtest/gtest.h"
#include "util/attribute.h"
#include "util/attrib_lookup_table.h"

using namespace::testing;

class TestTable : public Test 
{
public:
    TestTable() : rowh1{"Gordon Zuehlke"}, rowh2{"Diana Goldberg"}, 
                  rowh3{"Biz Markie"}, rowh4{"Ricky Ricardo"},
                  col1{"is_employed"}, col2{"salary"}, 
                  col3{"job_title"}, col4{"license_to_kill"},
                  str1{"employed"}, str2{"unemployed"},
                  b1{true}, b2{false},
                  cstr1{"Developer"}, cstr2{"Accountant"},
                  cstr3{"Rapper"}, cstr4{"Big Band Leader"},
                  i{85000}, j{50000}, ii{300000}, jj{175000}, t{AttribLookupTable{}}   
    {}

    Attribute rowh1, rowh2, rowh3, rowh4, col1, col2, col3, col4;
    std::string str1, str2;
    bool b1, b2;
    const char* cstr1; 
    const char* cstr2; 
    const char* cstr3; 
    const char* cstr4; 
    unsigned i; 
    unsigned j; 
    unsigned ii; 
    unsigned jj;
	AttribLookupTable t;
};

TEST_F(TestTable, test_size_is_zero) {
    EXPECT_TRUE(t.get_size() == 0);
}

TEST_F(TestTable, test_add_data) {
    EXPECT_TRUE(t.get_size() == 0);
    t.set_value(rowh1, col3, cstr1);
    EXPECT_TRUE(t.get_size() == 1);
}

TEST_F(TestTable, test_get_data) {
    EXPECT_FALSE(t.get_value(rowh1, col2) == j);
	EXPECT_FALSE(t.get_value(rowh1, col2));

    EXPECT_TRUE(t.set_value(rowh1, col3, cstr1));
    EXPECT_FALSE(t.get_value(rowh1, col2) == cstr1);
	EXPECT_TRUE(t.get_value(rowh1, col3) == cstr1);
}

TEST_F(TestTable, test_table_clear) {
    EXPECT_TRUE(t.get_size() == 0);
    EXPECT_TRUE(t.set_value(rowh1, col3, cstr1));
    EXPECT_TRUE(t.set_value(rowh2, col3, cstr2));
    EXPECT_TRUE(t.set_value(rowh3, col3, cstr3));
    EXPECT_TRUE(t.set_value(rowh4, col3, cstr4));

    EXPECT_TRUE(t.get_size() == 4);
    EXPECT_TRUE(t.table_clear());
    EXPECT_TRUE(t.get_size() == 0);
}















































 
