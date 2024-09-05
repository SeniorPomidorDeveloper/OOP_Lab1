#include "program.hpp"

#include "./libs/graph/graph.hpp"
#include "./libs/export/export.hpp"
#include <iostream>


void add_Node_Graph(Graph& graph)
{
    graph.add_Node();
}

void del_Node_Graph(Graph& graph)
{
    size_t num_node;
    cout << "Enter the number of the node to delete: ";
    cin >> num_node;
    if (cin.eof())
    {
        throw logic_error("EOF");
    }
    graph.remove_Node(num_node);
}

void add_Edge_Graph(Graph& graph)
{
    size_t num_node1 , num_node2;
    cout << "Enter the number of the first node: ";
    cin >> num_node1;
    if (cin.eof())
    {
        throw logic_error("EOF");
    }
    cout << "Enter the number of the second node: ";
    cin >> num_node2;
    if (cin.eof())
    {
        throw logic_error("EOF");
    }
    graph.add_Edge(num_node1, num_node2);
}

void del_Edge_Graph(Graph& graph)
{
    size_t num_node1 , num_node2;
    cout << "Enter the number of the first node: ";
    cin >> num_node1;
    if (cin.eof())
    {
        throw logic_error("EOF");
    }
    cout << "Enter the number of the second node: ";
    cin >> num_node2;
    if (cin.eof())
    {
        throw logic_error("EOF");
    }
    graph.remove_Edge(num_node1, num_node2);
}

void path1(Graph& graph)
{
    try
    {
        cout << "Path: " << export_Graph(graph) << endl;
    }
    catch(const std::exception& e)
    {
        throw logic_error("EOF");
    }
}

void path2(Graph& graph)
{
    size_t len_path;
    cout << "Enter the length of the path: ";
    cin >> len_path;
    if (cin.eof())
    {
        throw logic_error("EOF");
    }
    cout << "Enter the path: ";
    int *path = new int[len_path];
    for (size_t i = 0; i < len_path; ++i)
    {
        cin >> path[i];
        if (cin.eof())
        {
            delete[] path;
            throw logic_error("EOF");
        }
    }
    try
    {
        cout << "Path: " << export_Graph(graph, path, len_path) << endl;
    }
    catch(const exception& e)
    {
        throw e;
    }
    delete[] path;
}

void path3(Graph& graph)
{
    size_t len_path;
    cout << "Enter the length of the path: ";
    cin >> len_path;
    if (cin.eof())
    {
        throw logic_error("EOF");
    }
    cout << "Enter the path: ";
    vector<int> path(len_path);
    for (size_t i = 0; i < len_path; ++i)
    {
        cin >> path[i];
        if (cin.eof())
        {
            throw logic_error("EOF");
        }
    }
    try
    {
        cout << "Path: " << export_Graph(graph, path) << endl;
    }
    catch(const exception& e)
    {
        throw e;
    }
}

void menu_export()
{
    cout << "0. (Graph)" << endl;
    cout << "1. (Graph, array)" << endl;
    cout << "2. (Graph, vector)" << endl;
    cout << "Enter your choice: ";
}

void Graph_to_Dot(Graph& graph)
{
    vector<void(*)(Graph&)> funcs = {path1, path2, path3};
    menu_export();
    size_t func_num;
    cin >> func_num;
    if (cin.eof())
    {
        throw logic_error("EOF");
    }
    if (func_num < funcs.size())
    {
        try
        {
            funcs[func_num](graph);
        }
        catch(const exception& e)
        {
            throw e;
        }
    }
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

short int menu()
{
    short int option;
    cout << "0. Add Node" << endl;
    cout << "1. Delete Node" << endl;
    cout << "2. Add Edge" << endl;
    cout << "3. Delete Edge" << endl;
    cout << "4. Graph to DOT" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> option;
    if (cin.eof())
    {
        throw logic_error("EOF");
    }
    return option;
}

void program()
{
    Graph graph = Graph();
    vector<void(*)(Graph&)> funcs = {add_Node_Graph, del_Node_Graph, add_Edge_Graph, del_Edge_Graph, Graph_to_Dot};
    short int option;
    do
    {
        print_Graph(graph);
        option = menu();
        if (option < 5)
        {
            try
            {
                funcs[option](graph);
            }
            catch(const exception& e)
            {
                throw e;
            }
        }
    } while (option != 5);
}