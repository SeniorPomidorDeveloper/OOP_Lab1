#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <cstddef>
#include <vector>
#include <list>

#include <iostream>

using namespace std;

class Graph
{
    private:
        vector<vector<int>> adjacency_matrix;
        size_t size = 0;
    public:
        void add_Node();
        void add_Edge(const size_t num_node1, const size_t num_node2);
        void remove_Node(const size_t num_node);
        void remove_Edge(const size_t num_node1, const size_t num_node2);
        bool is_connected(const size_t num_node1, const size_t num_node2);
        vector<int>& get_row(const size_t num_node);
        size_t get_size();
};

void print_Graph(Graph& graph);

#endif // GRAPH_HPP