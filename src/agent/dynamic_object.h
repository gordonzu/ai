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

    friend std::ostream& operator<<(std::ostream& out, DynamicObject& x) {
        x.type_.clear();
        x.type_ = x.get_type();
        out << x.describe_attributes(x.type_);
	    return out;
    }

    std::string& get_type() {
        type_ = typeid(*this).name();
        if (type_.size() <= size_t(10))
            return type_ = type_.substr(1, type_.size());
        return type_ = type_.substr(2, type_.size());
    }

    std::string& describe_attributes(std::string& type_) {
        type_.append("[");
        bool first = true;

        for (auto& x : attributes_) {
            if (first) {
                first = false;
            } else {
                type_.append(", ");
            }
            type_.append(print_string(x.first));
            type_.append("=");
            type_.append(print_string(x.second));
        }
        type_.append("]");
        return type_;
    }

protected:
    DynamicObject() = default;

private:
    std::map<Attribute,Attribute> attributes_;
    std::string type_;
};
#endif //AICPP_DYNAMIC_OBJECT_H


