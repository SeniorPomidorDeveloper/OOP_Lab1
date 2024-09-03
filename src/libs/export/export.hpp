#ifndef EXPORt_HPP
#define EXPORt_HPP

#include <string>

#include "../graph/graph.hpp"

using namespace std;

string export_Graph(const Graph& graph);
string export_Graph(const Graph& graph, const int *path, const size_t path_len);
string export_Graph(const Graph& graph, const vector<int>& path); 

#endif // EXPORt_HPP