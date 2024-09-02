#ifndef EXPORt_HPP
#define EXPORt_HPP

#include <string>

#include "../graph/graph.hpp"

using namespace std;

string export_Graph(const Graph& graph);
string export_Graph(const int *path);
string export_Graph(const vector<int>& path); 

#endif // EXPORt_HPP