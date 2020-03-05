// Gordon Zuehlke 2/22/20

#ifndef AICPP_UTILITIES_H
#define AICPP_UTILITIES_H

#include <vector>
#include <map>
#include <algorithm>
#include <memory>
#include "util/attribute.h"
#include "environment/environment_obj.h"

using EnvVector = std::vector<std::shared_ptr<EnvironmentObj>>;
using AttribVector = std::vector<Attribute>;
using AttribMap = std::map<Attribute, Attribute>;
using AttribTable = std::map<Attribute, AttribMap>; 

namespace ut {
    inline std::string map_to_string(const AttribMap& x) {
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

    inline std::string print_vec(const AttribVector& v) {
        std::string out;
        for (const auto& x: v) {
            out.append(print_string(x));
            out.append(", ");
        }
        return out.substr(0, out.size()-2);
    }
}
#endif // AICPP_UTILITIES_H


