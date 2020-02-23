// Gordon Zuehlke 2/22/20

#ifndef AICPP_PERCEPT_H
#define AICPP_PERCEPT_H

#include <assert.h>
#include "dynamic_object.h"

class Percept: public DynamicObject {
public:
    Percept() {}

    Percept(const Attribute& key, const Attribute& val) {
       set_attribute(key, val);
    }

};

#endif //AICPP_PERCEPT_H
