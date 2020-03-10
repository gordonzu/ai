// Gordon Zuehlke 3-9-20

#ifndef AICPP_ACTION_H
#define AICPP_ACTION_H

#include "dynamic_object.h"

namespace ag {
    class Action : public DynamicObject {
    public:
        Action() : no_op{true} { }

    private:
        bool no_op;
    };
}
#endif //AICPP_ACTION_H


