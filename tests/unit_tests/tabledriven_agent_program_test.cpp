// Gordon Zuehlke 3-9-20

#include <memory>
#include "gtest/gtest.h"
#include "agent/agent.h"
#include "agent/percept.h"
#include "agent/action.h"
#include "agent/tabledriven_agent_program.h"

using namespace::testing;

class TestTableDrivenAgentProgram: public Test {
public:


};


TEST_F(TestTableDrivenAgentProgram, test_string) {
    EXPECT_EQ(2, 2);
}


