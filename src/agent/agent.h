// gordon zuehlke 2/16/20

#ifndef AICPP_AGENT_H
#define AICPP_AGENT_H

#include "environment/environment_obj.h"
#include "agent_program.h"

using ProgramPtr = std::shared_ptr<AgentProgram>;

class Agent : public EnvironmentObj { 
public:
    virtual ~Agent() = default;
    virtual ActionPtr execute(Percept& percept) = 0;
    virtual bool set_program(ProgramPtr p) = 0;
    virtual bool is_alive() = 0;
    virtual void set_alive(bool a) = 0;
};
#endif
