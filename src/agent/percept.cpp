// percept.cpp
// gordonyx 05/12/23

#include "percept.h"

Percept::Percept(const Attribute& key, const Attribute& val) {
    set_attribute(key, val);
}

Percept::Percept(const Attribute& key1, const Attribute& val1,
                 const Attribute& key2, const Attribute& val2) {
    set_attribute(key1, val1);
    set_attribute(key2, val2);
}

Percept::Percept(const Percept& x) : DynamicObject(x) {}

Percept& Percept::operator=(const Percept& x) noexcept {
    if (this != &x) 
        DynamicObject::operator=(x);
    return *this;
}

bool Percept::operator==(const Percept& x) const {
    return DynamicObject::operator==(x);
}

bool Percept::operator<(const Percept& x) const {
    return get_map() < x.get_map();
}

std::ostream& operator<<(std::ostream& out, const Percept& x) {
    return out << (DynamicObject&)x;	
}		


