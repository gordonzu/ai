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
    virtual ~DynamicObject() = default;

public:
    DynamicObject(const DynamicObject& x);
    DynamicObject& operator=(const DynamicObject& x);
    bool operator==(const DynamicObject& x) const; 
    bool set_attribute(const Attribute& key,  const Attribute& val);
    const std::optional<Attribute> get_attribute(const Attribute& key) const;
    std::string& describe_attributes(std::string& type_);
    std::string& get_type();
    const std::map<Attribute, Attribute>& get_map() const;
    std::string& get_string();
    bool has_value();
    friend std::ostream& operator<<(std::ostream& out, DynamicObject& x);
    
private:
    std::map<Attribute,Attribute> attributes_;
    std::string type_;
};
#endif //AICPP_DYNAMIC_OBJECT_H


