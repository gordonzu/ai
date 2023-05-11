// Gordon Zuehlke

#ifndef AICPP_TABLE_DRIVEN_AGENT_PROGRAM_H
#define AICPP_TABLE_DRIVEN_AGENT_PROGRAM_H

#include "agent_program.h"

class TableDrivenAgentProgram: public AgentProgram {
public:    
    ActionPtr execute(const Percept& p) override; 
};
#endif





