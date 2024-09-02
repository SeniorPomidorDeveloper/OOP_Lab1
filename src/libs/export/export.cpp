#include "export.hpp"

#include <fstream>

string export_Graph(const Graph& graph)
{
    string file_name = "graph.dot";
    ofstream file_out(file_name);
    if (!file_out.is_open()) 
    {
        throw "Failed to open output file.";
    }
    file_out << "graph Graph {\n" << "\tnode [shape = circle];\n";
    for (size_t i = 0; i < graph.get_size(); ++i)
    {
        file_out << "\t" << i << ";\n";
        for (size_t j = i + 1; j < graph.get_size(); ++j) if (graph.is_connected(i, j))
        file_out << "\t" << i << " -- " << j << ";\n";
    }
    file_out << "}\n";
    string path = "./" + file_name;
    return path;
}

string export_Graph(const Graph& graph, const int *path);

string export_Graph(const Graph& graph, const vector<int>& path);