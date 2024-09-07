/*! \defgroup Graph_module Модуль графа */

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <cstddef>
#include <vector>
#include <list>

using namespace std;

//! Класс графа
/*!
    \ingroup Graph_module

    \details Класс описывающий логическую структуру графа. 
*/
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
        bool is_connected(const size_t num_node1, const size_t num_node2) const;
        vector<int> get_row(const size_t num_node) const;
        size_t get_size() const;
};

#endif // GRAPH_HPP