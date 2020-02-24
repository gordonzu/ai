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
protected:
    DynamicObject() = default;

public:
    virtual ~DynamicObject() = default;

    DynamicObject(const DynamicObject& x) {
	    attributes_.insert(x.attributes_.begin(), x.attributes_.end()); 
    }

    DynamicObject& operator=(const DynamicObject& x) {
        if (this != &x) {
            attributes_.clear();
            attributes_.insert(x.attributes_.begin(), x.attributes_.end());
        }
        return *this;
    }

    bool operator==(const DynamicObject& x) const {
        return attributes_ == x.attributes_;
    }

    bool set_attribute(const Attribute& key,  const Attribute& val) {
        //std::cout << "Print key=" << key << " val=" << val << std::endl; 
        auto x = attributes_.emplace(key, val);
        if (x.second) return true;
        return false;
        //std::cout << "attributes_ size: " << attributes_.size() << std::endl;
    }
    
    const std::optional<Attribute> get_attribute(const Attribute& key) const {
            //std::cout << "--------------------------------------" << std::endl;  
            //std::cout << "Calling DynamicObject::get_attribute()" << std::endl;  
            //std::cout << "attributes_ size: " << attributes_.size() << std::endl;  
            //std::cout << "Passed in key: " << print_string(key) << std::endl;  

        try {
            auto it = attributes_.find(key);
            if (it != attributes_.end()) {
                return std::optional<Attribute>(it->second);
            } 
            else {
               throw lookup_exception();
            }
        }
        catch(lookup_exception& e) {/*
            std::cerr << "  In get_attribute key: " 
                      << key 
                      << " returns no value in attributes map." 
                      << std::endl;
            std::cerr << e.what() << std::endl; */
        } 
        catch(std::exception& e) {/*
            std::cerr << "DynamicObject::get_attribute throws..." << std::endl;
            std::cerr << "DynamicObject::get_attribute throws..." << std::endl;
            std::cerr << e.what() << std::endl;*/
        }
        return std::nullopt;
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

    std::string& get_type() {
        type_ = typeid(*this).name();
        if (type_.size() <= size_t(10))
            return type_ = type_.substr(1, type_.size());
        return type_ = type_.substr(2, type_.size());
    }

    const std::map<Attribute, Attribute>& get_map() const {
        return attributes_;
    }

    std::string& get_string() {
        type_.clear();
        type_ = get_type();
        return describe_attributes(type_);
    }

    friend std::ostream& operator<<(std::ostream& out, DynamicObject& x) {
        x.type_.clear();
        x.type_ = x.get_type();
        out << x.describe_attributes(x.type_);
	    return out;
    }

private:
    std::map<Attribute,Attribute> attributes_;
    std::string type_;
};
#endif //AICPP_DYNAMIC_OBJECT_H


