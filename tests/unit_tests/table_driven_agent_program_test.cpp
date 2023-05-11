// Gordon Zuehlke 3-9-20

#include <memory>
#include "gtest/gtest.h"
#include "mock_agent.h"
#include "agent/percept.h"
#include "agent/action.h"
#include "agent/table_driven_agent_program.h"

using namespace::testing;

class TestTableDrivenAgentProgram: public Test {
public:

    MockAgent agent;
    Percept p;
    std::shared_ptr<AgentProgram> ptrProg;
};

TEST_F(TestTableDrivenAgentProgram, test_null_program) {
    EXPECT_FALSE(agent.set_program(nullptr));
}

TEST_F(TestTableDrivenAgentProgram, test_noop_action) {
    agent.set_program(nullptr);
    auto action = agent.execute(p);
    EXPECT_TRUE(action->is_no_op());
}

TEST_F(TestTableDrivenAgentProgram, test_live_program) {
    Percept p{"key1", "value1"};
    auto action = agent.execute(p);
    EXPECT_FALSE(action->is_no_op());
}

TEST_F(TestTableDrivenAgentProgram, test_existing_sequences) {
    agent.set_program(ptrProg);

    EXPECT_TRUE(true);
}






















