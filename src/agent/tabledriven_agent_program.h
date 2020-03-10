// Gordon Zuehlke

#ifndef AICPP_TABLE_DRIVEN_AGENT_PROGRAM_H
#define AICPP_TABLE_DRIVEN_AGENT_PROGRAM_H

#include "agent_program.h"

class TableDrivenAgentProgram: public AgentProgram {
public:    
    virtual ActionPtr execute(const Percept& p) {
        ActionPtr aPtr = std::make_shared<Action>();
        return aPtr;
    }

};
#endif





