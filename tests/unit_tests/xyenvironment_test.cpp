// gordon zuehlke 2/21/20
// Test class for XYEnvironment

#include "gtest/gtest.h"
#include "environment/xyenv/xy_environment.h"
#include "environment/xyenv/wall.h"
#include "mock_agent.h"

using namespace::testing;

class TestXYEnvironment: public Test {
public:
    TestXYEnvironment() {
        agent = std::make_unique<MockAgent>();
        wall = std::make_unique<Wall>();
        env.add(agent, loc);        
    }

    EnvPtr agent;
    EnvPtr wall;
    XYLocation loc{3,4};
    XYEnvironment env{10,12};
};

TEST_F(TestXYEnvironment, testAddAgent) {
    EXPECT_EQ(env.get_location(agent), loc);
    EXPECT_EQ(env.objects_at_location(loc), size_t(1));
}
