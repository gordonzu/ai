// Gordon Zuehlke 2/22/20

#ifndef AICPP_DYNAMIC_OBJECT_H
#define AICPP_DYNAMIC_OBJECT_H

#include <iostream>
#include <map>
#include <memory>
#include <string>
#include <optional>
#include "util/attribute.h"

class DynamicObject {
public:
    virtual ~DynamicObject() = default;

    bool set_attribute(const Attribute& key,  const Attribute& val) {
        //std::cout << "Print key=" << key << " val=" << val << std::endl; 
        auto x = attributes_.emplace(key, val);
        if (x.second) return true;
        return false;
        //std::cout << "attributes_ size: " << attributes_.size() << std::endl;
    }

protected:
    DynamicObject() = default;

private:
    std::map<Attribute,Attribute> attributes_;
    std::string type_;
};
#endif //AICPP_DYNAMIC_OBJECT_H


