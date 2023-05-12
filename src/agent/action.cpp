// action.cpp
// gordonyx 05/12/23

#include "action.h"

namespace ag {

Action::Action() : no_op{true} { }

Action::Action(const std::string& str) : attrib{str}, no_op{false} { }

bool Action::is_no_op() {
    return no_op;
}
} 
