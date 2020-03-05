// Gordon Zuehlke 2/27/20

#ifndef AICPP_TABLE_H
#define AICPP_TABLE_H

#include <vector>
#include <map>
#include "util/attribute.h"

using AttribVector = std::vector<Attribute>;
using AttribMap = std::map<Attribute, Attribute>;
using AttribTable = std::map<Attribute, AttribMap>; 

class AttribLookupTable {
public:
    AttribLookupTable() = default;

    size_t get_size() {
        return attr_table.size();
    }

private:
    AttribTable attr_table;
};
#endif // AICPP_TABLE_H



