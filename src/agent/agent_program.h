// Gordon Zuehlke

#ifndef AICPP_TABLE_DRIVEN_AGENT_PROGRAM_H
#define AICPP_TABLE_DRIVEN_AGENT_PROGRAM_H

#include "percept.h"
#include "action.h"
#include <memory>

using namespace::ag;
using ActionPtr = std::shared_ptr<Action>;

class AgentProgram {
public:    
    ActionPtr execute(const Percept& p); 
};

#endif


// using PRow = std::vector<Percept>;
// using SVec = std::vector<std::string>;
// using PVecs = std::vector<PRow>;
// using AMap = std::map<std::string, Action>;
// using PMap = std::map<PRow, std::map<std::string, Action>>;
// using MMap = std::map<PRow, Action>;



