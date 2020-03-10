// Gordon Zuehlke 3-7-20

#ifndef AICPP_AGENT_PROGRAM_H
#define AICPP_AGENT_PROGRAM_H

#include "util/attrib_lookup_table.h"
#include "agent/action.h"
#include "agent/percept.h"
#include <algorithm>

using namespace::ag;
using PRow = std::vector<Percept>;
using SVec = std::vector<std::string>;
using PVecs = std::vector<PRow>;
using AMap = std::map<std::string, Action>;
using PMap = std::map<PRow, std::map<std::string, Action>>;
using MMap = std::map<PRow, Action>;
using ActionPtr = std::shared_ptr<Action>;

class AgentProgram {
public:
    virtual ~AgentProgram() = default;
    virtual ActionPtr execute(const Percept& p) = 0;
};
#endif //AICPP_AGENT_PROGRAM_H

