// Gordon Zuehlke 2/22/20

#ifndef AICPP_UTILITIES_H
#define AICPP_UTILITIES_H

#include <vector>
#include <map>
#include <algorithm>
#include <memory>
#include "util/attribute.h"
#include "environment/environment_obj.h"

using envObjs = std::vector<std::shared_ptr<EnvironmentObj>>;
using attributes = std::vector<Attribute>;
using attribute_map = std::map<Attribute, Attribute>;
using attribute_table = std::map<Attribute, attribute_map>; 

namespace ut {
    inline std::string map_to_string(const attribute_map& x) {
            std::stringstream out;	
            out << "<map>" << std::endl;

            for (const auto& e: x) {
                out << std::string(2, ' ') 
                    << "key: " << print_string(e.first) << ", " 
                    << "value: " << print_string(e.second)  
                    << std::endl;
            }
            out << "</map>" << std::endl;
            std::string str_ = out.str();
            return str_; 
        }


}
#endif // AICPP_UTILITIES_H
