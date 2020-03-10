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

    bool set_value(const Attribute& row, 
                   const Attribute& col, 
                   const Attribute& val) {
        x = attr_table.size();
        if ((outer = attr_table.find(row)) != attr_table.end()) {
            return update_row(row, col, val);
        }
        return insert_row(row, col, val);
    }

    std::optional<Attribute> get_value(const Attribute& row, 
                                       const Attribute& col) {
        if ((outer = attr_table.find(row)) != attr_table.end()) {
			if ((inner = outer->second.find(col)) != outer->second.end())
			{
				return inner->second;
			}	
		}
		return std::nullopt;		
    }

private:
    AttribTable attr_table;
    AttribMap::iterator inner;
    AttribTable::iterator outer;
    size_t x;

    bool update_row(const Attribute& row, 
                    const Attribute& col, 
                    const Attribute& val) {
        inner = outer->second.find(col);
        if (inner != outer->second.end()) {
            inner->second = val;
            return outer->second.at(col) == val;
        }
        outer->second.emplace(col, val);
        return outer->second.at(col) == val;
    }

    bool insert_row(const Attribute& row, 
                    const Attribute& col, 
                    const Attribute& val) {
        attr_table[row][col] = val;
        return attr_table.size() == ++x;   
    }
};
#endif // AICPP_TABLE_H



