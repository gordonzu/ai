// dynamic_object.cpp
// gordonyx 05-12-2023

#include "dynamic_object.h"

DynamicObject::DynamicObject(const DynamicObject& x) {
    this->attributes_.insert(x.attributes_.begin(), x.attributes_.end());
}

DynamicObject& DynamicObject::operator=(const DynamicObject& x) {
    if (this != &x) {
        this->attributes_.clear();
        this->attributes_.insert(x.attributes_.begin(), x.attributes_.end());
    }
    return *this;
}

bool DynamicObject::operator==(const DynamicObject& x) const {
    return this->attributes_ == x.attributes_;
}

bool DynamicObject::set_attribute(const Attribute& key,  const Attribute& val) {
    auto x = attributes_.emplace(key, val);
    if (x.second) return true;
    return false;
}

const std::optional<Attribute> DynamicObject::get_attribute(const Attribute& key) const {
    try {
        auto it = attributes_.find(key);
        if (it != attributes_.end()) {
            return std::optional<Attribute>(it->second);
        } 
        else {
            throw lookup_exception();
        }
    }
    catch(lookup_exception& e) {
        std::cerr << "  In get_attribute key: " 
            << key 
            << " returns no value in attributes map." 
            << std::endl;
        std::cerr << e.what() << std::endl; 
    } 
    catch(std::exception& e) {
        std::cerr << "DynamicObject::get_attribute throws..." << std::endl;
        std::cerr << "DynamicObject::get_attribute throws..." << std::endl;
        std::cerr << e.what() << std::endl;
    }
    return std::nullopt;
}

std::string& DynamicObject::describe_attributes(std::string& type_) {
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

std::string& DynamicObject::get_type() {
    type_ = typeid(*this).name();
    if (type_.size() <= size_t(10))
        return type_ = type_.substr(1, type_.size());
    return type_ = type_.substr(2, type_.size());
}

const std::map<Attribute, Attribute>& DynamicObject::get_map() const {
    return attributes_;
}

std::string& DynamicObject::get_string() {
    type_.clear();
    type_ = get_type();
    return describe_attributes(type_);
}

bool DynamicObject::has_value() {
    return attributes_.size() > 0;
}

std::ostream& operator<<(std::ostream& out, DynamicObject& x) {
    x.type_.clear();
    x.type_ = x.get_type();
    out << x.describe_attributes(x.type_);
    return out;
}





















