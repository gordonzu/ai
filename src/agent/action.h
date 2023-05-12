// Gordon Zuehlke 3-9-20

#ifndef AICPP_ACTION_H
#define AICPP_ACTION_H

#include "dynamic_object.h"

namespace ag {
    class Action : public DynamicObject {
    public:
        Action(); 
        virtual ~Action() = default;
        explicit Action(const std::string& str);
        bool is_no_op(); 

    private:
        std::string attrib;
        bool no_op;
        std::string col{"name"};
    };
}
#endif //AICPP_ACTION_H


