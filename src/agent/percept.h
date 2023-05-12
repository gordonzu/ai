// Gordon Zuehlke 2/22/20

#ifndef AICPP_PERCEPT_H
#define AICPP_PERCEPT_H

#include <assert.h>
#include "dynamic_object.h"

class Percept : public DynamicObject {
public:
    Percept() = default; 
    virtual ~Percept() override {}
    Percept(const Percept& x); 
    Percept(const Attribute& key, const Attribute& val);
    Percept(const Attribute& key1, const Attribute& val1,
            const Attribute& key2, const Attribute& val2);

    Percept& operator=(const Percept& x) noexcept;
    bool operator==(const Percept& x) const;
    bool operator<(const Percept& x) const;
    friend std::ostream& operator<<(std::ostream& out, const Percept& x);
};

#endif //AICPP_PERCEPT_H
