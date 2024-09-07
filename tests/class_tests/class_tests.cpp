#include "../test.hpp"

class ClassTest : public testing::Test {
    public:
        Graph *graph;
        
        void SetUp() 
        {
            graph = new Graph();
        }
        void TearDown() 
        { 
            delete graph; 
        }
};

TEST_F(ClassTest, Test_init_graph)
{
    // Act
    size_t size = graph->get_size();

    // Assert
    ASSERT_EQ(size, 0);
}

TEST_F(ClassTest, Test_add_Node_get_row)
{
    // Act
    graph->add_Node();
    size_t size = graph->get_size();
    vector<int> row = graph->get_row(size - 1);
    vector<int> answer = {0};

    // Assert
    ASSERT_EQ(size, 1);
    ASSERT_TRUE(row == answer);
}

TEST_F(ClassTest, Test_add_Edge_and_is_connected)
{
    // Act
    graph->add_Node();
    graph->add_Node();
    graph->add_Edge(0, 1);
    vector<int> row1 = graph->get_row(0);
    vector<int> row2 = graph->get_row(1);
    vector<int> answer1 = {0, 1};
    vector<int> answer2 = {1, 0};
    bool connected = graph->is_connected(0, 1);

    // Assert
    ASSERT_TRUE(row1 == answer1);
    ASSERT_TRUE(row2 == answer2);
    ASSERT_TRUE(connected);
}

TEST_F(ClassTest, Test_remove_edge_and_is_conected)
{
    // Act
    graph->add_Node();
    graph->add_Node();
    graph->add_Edge(0, 1);
    graph->remove_Edge(0, 1);
    vector<int> row1 = graph->get_row(0);
    vector<int> row2 = graph->get_row(1);
    vector<int> answer1 = {0, 0};
    vector<int> answer2 = {0, 0};
    bool connected = graph->is_connected(0, 1);

    // Assert
    ASSERT_TRUE(row1 == answer1);
    ASSERT_TRUE(row2 == answer2);
    ASSERT_FALSE(connected);
}

TEST_F(ClassTest, Test_remove_node)
{
    // Act
    graph->add_Node();
    graph->remove_Node(0);
    size_t size = graph->get_size();
    vector<int> row = graph->get_row(0);
    vector<int> answer = {};

    // Assert
    ASSERT_TRUE(row == answer);
    ASSERT_EQ(size, 0);
}