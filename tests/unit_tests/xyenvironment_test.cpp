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

TEST_F(TestXYEnvironment, test_add_agent) {
    EXPECT_EQ(env.get_location(agent), loc);
    EXPECT_EQ(env.objects_at_location(loc), size_t(1));
}

TEST_F(TestXYEnvironment, test_add_object2) {
    XYLocation yy{9,9};
    env.add(wall, yy);
    EXPECT_EQ(env.objects_at_location(yy), size_t(1));
    EXPECT_EQ(env.get_num_objects(), size_t(2));
    EXPECT_EQ(env.get_num_agents(), size_t(1));
}

TEST_F(TestXYEnvironment, test_add_object_twice) {
    EXPECT_EQ(env.objects_at_location(loc), size_t(1));
    XYLocation xy{5,5};
    env.add(agent, xy);
    EXPECT_EQ(env.objects_at_location(xy), size_t(1));
    EXPECT_EQ(env.get_location(agent), xy);
}

TEST_F(TestXYEnvironment, test_objects_are_unique) {
    EnvPtr agent2 = std::make_shared<MockAgent>();
    EXPECT_NE(agent, agent2);
}

TEST_F(TestXYEnvironment, test_add_two_objects_one_location) {
    XYLocation xy{9,8};
    env.move_absolute(agent,xy);
    EXPECT_EQ(env.objects_at_location(xy), size_t(1));
    EnvPtr agent2 = std::make_shared<MockAgent>();
    env.move_absolute(agent2,xy);
    EXPECT_EQ(env.objects_at_location(xy), size_t(2));
}

TEST_F(TestXYEnvironment, change_object_location) {
    XYLocation xy{5,6};
    env.add(agent, xy);
    EXPECT_EQ(env.objects_at_location(xy), size_t(1));
    EXPECT_EQ(env.objects_at_location(loc), size_t(0));
}

TEST_F(TestXYEnvironment, test_get_current_location) {
    XYLocation xy{3,4};
    EXPECT_EQ(env.get_location(agent), xy);
    XYLocation xy2{12,5};
    EXPECT_NE(env.get_location(agent), xy2);
}

TEST_F(TestXYEnvironment, test_move_to_absolute_location) {
    XYLocation xy{5,3};
    env.move_absolute(agent, xy);
    EXPECT_EQ(env.get_location(agent), xy);
    EXPECT_NE(env.get_location(agent), loc); 
}

TEST_F(TestXYEnvironment, test_move_object) {
    XYLocation xy{5,5};
    env.add(agent, xy);
    EXPECT_EQ(env.get_location(agent), xy);

    XYLocation loc54{5,4};
    XYLocation loc64{6,4};
    XYLocation loc65{6,5};

    env.move_object(agent, XYLocation::Direction::NORTH);
    EXPECT_EQ(env.get_location(agent), loc54);
    env.move_object(agent, XYLocation::Direction::EAST);
    EXPECT_EQ(env.get_location(agent), loc64);
    env.move_object(agent, XYLocation::Direction::SOUTH);
    EXPECT_EQ(env.get_location(agent), loc65);
    env.move_object(agent, XYLocation::Direction::WEST);
    EXPECT_EQ(env.get_location(agent), xy);
}

TEST_F(TestXYEnvironment, test_persistence_of_move) {
    EXPECT_EQ(env.get_location(agent), loc);
}
 
TEST_F(TestXYEnvironment, test_is_blocked) {
    XYLocation xy{5,5};
    env.add(agent, xy);
    EXPECT_EQ(env.is_blocked(xy), false);
    env.add(wall, xy);
    EXPECT_EQ(env.is_blocked(xy), true);
}

TEST_F(TestXYEnvironment, test_move_with_blocking_walls) {
    XYLocation xy{5,5};
    env.add(agent, xy);

    XYLocation xyNorth{5,6};
    XYLocation xySouth{5,4};
    XYLocation xyWest{4,5};
    XYLocation xyEnd{6,5};

    EnvPtr northwall = std::make_shared<Wall>();
    EnvPtr southwall = std::make_shared<Wall>();
    EnvPtr westwall = std::make_shared<Wall>();
    env.add(northwall, xyNorth);
    EXPECT_EQ(env.is_blocked(xyNorth), true);
   
    env.add(southwall, xySouth);
    env.add(westwall, xyWest);
    EXPECT_EQ(env.get_num_objects(), size_t(4));
    
    env.move_object(agent, XYLocation::Direction::NORTH); // should not move
    env.move_object(agent, XYLocation::Direction::SOUTH); // should not move
    env.move_object(agent, XYLocation::Direction::WEST);  // should not move
    env.move_object(agent, XYLocation::Direction::EAST);  // SHOULD move
    EXPECT_EQ(env.get_location(agent), xyEnd);
}

TEST_F(TestXYEnvironment, test_get_objects_near) {
    XYLocation loc{5,5};
    XYLocation loc2{7,4};
    XYLocation loc3{5,7};
    XYLocation loc4{3,10};
    XYLocation loc5{3,11};
    
    EnvPtr b = std::make_shared<MockAgent>();
    EnvPtr c = std::make_shared<MockAgent>();
    EnvPtr w = std::make_shared<MockAgent>();

    env.add(agent, loc);
    env.add(b, loc2);
    env.add(c, loc3);
    env.add(w, loc4);

    EXPECT_EQ(env.get_objects_near(agent, 3).size(), size_t(2));
    EXPECT_EQ(env.get_objects_near(b, 3).size(), size_t(1));

    env.move_object(b, XYLocation::Direction::SOUTH);
    EXPECT_EQ(env.get_objects_near(b, 3).size(), size_t(2));

    env.add(c, loc5);
    EXPECT_EQ(env.get_objects_near(c, 4).size(), size_t(1));
}

TEST_F(TestXYEnvironment, test_make_perimeter) {
    env.make_perimeter(5);

    EXPECT_TRUE(env.is_blocked(XYLocation{1,1}));
    EXPECT_TRUE(env.is_blocked(XYLocation{1,2}));
    EXPECT_TRUE(env.is_blocked(XYLocation{1,5}));
    EXPECT_TRUE(env.is_blocked(XYLocation{2,1}));
    EXPECT_TRUE(env.is_blocked(XYLocation{5,2}));
    EXPECT_TRUE(env.is_blocked(XYLocation{5,5}));
    EXPECT_TRUE(env.is_blocked(XYLocation{4,1}));

    EXPECT_FALSE(env.is_blocked(XYLocation{7,5}));
    EXPECT_FALSE(env.is_blocked(XYLocation{2,8}));
    EXPECT_FALSE(env.is_blocked(XYLocation{4,4}));
    EXPECT_FALSE(env.is_blocked(XYLocation{3,2}));
}


