#include "../test.hpp"
#include <string>
#include <fstream>

string file_to_string(string file_name)
{
    ifstream file_in(file_name);
    if (!file_in.is_open()) {
        throw runtime_error("Could not open file");
    }
    stringstream buffer;
    buffer << file_in.rdbuf();
    file_in.close();
    return buffer.str();
}

TEST(ExportTests, export_v1) 
{
    Graph graph = Graph();
    graph.add_Node();
    graph.add_Node();
    graph.add_Edge(0, 1);
    string path_file = export_Graph(graph);
    string file_gen = file_to_string(path_file);
    string file_ans = file_to_string("./answers/test1.dot");
    ASSERT_STREQ(file_gen.c_str(), file_ans.c_str());
}

TEST(ExportTests2, export_v2) 
{
    Graph graph = Graph();
    graph.add_Node();
    graph.add_Node();
    graph.add_Edge(0, 1);
    string path_file = export_Graph(graph, {0, 1});
    string file_gen = file_to_string(path_file);
    string file_ans = file_to_string("./answers/test2.dot");
    EXPECT_STREQ(file_gen.c_str(), file_ans.c_str());
}

TEST(ExportTests2, export_v2_NOTFOUND) 
{
    Graph graph = Graph();
    graph.add_Node();
    graph.add_Node();
    graph.add_Edge(0, 1);
    string path_file = export_Graph(graph, {0, 3});
    EXPECT_STREQ(path_file.c_str(), "");
}

TEST(ExportTests2, export_v3) 
{
    Graph graph = Graph();
    graph.add_Node();
    graph.add_Node();
    graph.add_Edge(0, 1);
    string path_file = export_Graph(graph, {0, 1});
    string file_gen = file_to_string(path_file);
    string file_ans = file_to_string("./answers/test2.dot");
    EXPECT_STREQ(file_gen.c_str(), file_ans.c_str());
}

TEST(ExportTests2, export_v3_NOTFOUND) 
{
    Graph graph = Graph();
    graph.add_Node();
    graph.add_Node();
    graph.add_Edge(0, 1);
    string path_file = export_Graph(graph, {0, 3});
    EXPECT_STREQ(path_file.c_str(), "");
}