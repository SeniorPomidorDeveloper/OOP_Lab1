#include "graph.hpp"

void Graph::add_Node()
{
    for (vector<int>& row : adjacency_matrix)
    {
        row.push_back(0);
    }
    adjacency_matrix.push_back(vector<int>(size + 1, 0));
    size++;
}

void Graph::add_Edge(const size_t num_node1, const size_t num_node2)
{
    if (num_node1 < size && num_node2 < size && num_node1 != num_node2)
    {
        adjacency_matrix[num_node1][num_node2] = 1;
        adjacency_matrix[num_node2][num_node1] = 1;
    }
}

void Graph::remove_Node(const size_t num_node)
{
    if (num_node < size)
    {
        adjacency_matrix.erase(adjacency_matrix.begin() + num_node);
        for (vector<int>& row : adjacency_matrix)
        {
            row.erase(row.begin() + num_node);
        }
        size--;
    }
}

void Graph::remove_Edge(const size_t num_node1, const size_t num_node2)
{
    if (num_node1 < size && num_node2 < size && num_node1 != num_node2)
    {
        adjacency_matrix[num_node1][num_node2] = 0;
        adjacency_matrix[num_node2][num_node1] = 0;
    }
}

bool Graph::is_connected(const size_t num_node1, const size_t num_node2)
{
    if (num_node1 < size && num_node2 < size && num_node1 != num_node2)
    {
        return adjacency_matrix[num_node1][num_node2] == 1;
    }
    return false;
}

vector<int>& Graph::get_row(const size_t num_node)
{
    if (num_node < size)
    {
        return adjacency_matrix[num_node];
    }
    return adjacency_matrix[size - 1];
}

size_t Graph::get_size()
{
    return size;
}

void print_Graph(Graph& graph)
{
    for (size_t i = 0; i < graph.get_size(); ++i)
    {
        for (int j : graph.get_row(i))
        {
            cout << j << " ";
        }
        cout << endl;
    }
}