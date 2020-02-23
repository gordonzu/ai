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
        agent = std::make_shared<MockAgent>();
        wall = std::make_shared<Wall>();
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

TEST_F(TestXYEnvironment, testAddObject2) {
    XYLocation yy{9,9};
    env.add(wall, yy);
    EXPECT_EQ(env.objects_at_location(yy), size_t(1));
    EXPECT_EQ(env.get_num_objects(), size_t(2));
    EXPECT_EQ(env.get_num_agents(), size_t(1));
}
