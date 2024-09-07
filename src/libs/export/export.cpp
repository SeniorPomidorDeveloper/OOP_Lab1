#include "export.hpp"

#include <fstream>
#include <unistd.h>
#include <string.h>



string export_Graph(const Graph& graph)
{
    string file_name = "graph.dot";
    ofstream file_out(file_name);
    if (!file_out.is_open()) 
    {
        throw runtime_error("Failed to open output file");
    }
    file_out << "graph Graph {\n" << "\tnode [shape = circle];\n";
    for (size_t i = 0; i < graph.get_size(); ++i)
    {
        file_out << "\t" << i << ";\n";
        for (size_t j = i + 1; j < graph.get_size(); ++j) if (graph.is_connected(i, j))
        file_out << "\t" << i << " -- " << j << ";\n";
    }
    file_out << "}\n";
    file_out.close();
    const size_t BUF_SIZE = 1024;
    char dir_path[BUF_SIZE];
    if (getcwd(dir_path, BUF_SIZE) == NULL) throw runtime_error("Failed to get path dir");
    return string(dir_path) + "/" + file_name;
}

string export_Graph(const Graph& graph, const int *path, const size_t path_len)
{
    vector<vector<int>> path_matrix(graph.get_size(), vector<int>(graph.get_size(), 0));
    for (size_t i = 0; i < path_len - 1; i++)
    {
        if (graph.is_connected(path[i], path[i + 1])) 
        {
            path_matrix[path[i]][path[i + 1]] = 1;
        }
        else return "";
    }
    string file_name = "graph.dot";
    ofstream file_out(file_name);
    if (!file_out.is_open()) 
    {
        throw runtime_error("Failed to open output file");
    }
    file_out << "graph Graph {\n" << "\tnode [shape = circle];\n";
    for (size_t i = 0; i < graph.get_size(); ++i)
    {
        file_out << "\t" << i << ";\n";
        for (size_t j = i + 1; j < graph.get_size(); ++j) if (graph.is_connected(i, j))
        {
            file_out << "\t" << i << " -- " << j;
            if (path_matrix[i][j] == 1) file_out << " [color=red]";
            file_out << ";\n";
        }
    }
    file_out << "}\n";
    file_out.close();
    const size_t BUF_SIZE = 1024;
    char dir_path[BUF_SIZE];
    if (getcwd(dir_path, BUF_SIZE) == NULL) runtime_error("Failed to get path dir");
    return string(dir_path) + "/" + file_name;
}

string export_Graph(const Graph& graph, const vector<int>& path)
{
    vector<vector<int>> path_matrix(graph.get_size(), vector<int>(graph.get_size(), 0));
    for (size_t i = 0; i < path.size() - 1; i++)
    {
        if (graph.is_connected(path[i], path[i + 1])) 
        {
            path_matrix[path[i]][path[i + 1]] = 1;
        }
        else return "";
    }
    string file_name = "graph.dot";
    ofstream file_out(file_name);
    if (!file_out.is_open()) 
    {
        throw runtime_error("Failed to open output file");
    }
    file_out << "graph Graph {\n" << "\tnode [shape = circle];\n";
    for (size_t i = 0; i < graph.get_size(); ++i)
    {
        file_out << "\t" << i << ";\n";
        for (size_t j = i + 1; j < graph.get_size(); ++j) if (graph.is_connected(i, j))
        {
            file_out << "\t" << i << " -- " << j;
            if (path_matrix[i][j] == 1) file_out << " [color=red]";
            file_out << ";\n";
        }
    }
    file_out << "}\n";
    file_out.close();
    const size_t BUF_SIZE = 1024;
    char dir_path[BUF_SIZE];
    if (getcwd(dir_path, BUF_SIZE) == NULL) runtime_error("Failed to get path dir");
    return string(dir_path) + "/" + file_name;;
}