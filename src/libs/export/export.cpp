#include "export.hpp"

#include <fstream>
#include <unistd.h>
#include <string.h>
#include <algorithm>
#include <functional>
#include <iostream>

string fill_path(const int eage)
{
    if (eage == 1) return " [color=red]";
    return "";
}

/*!
    \ingroup Export_module

    \brief Функция, создающая файл в с расширением .dot и записывающая в него граф.
    \param[in] graph граф.
    \throw std::runtime_error - При возникновении ошибки открытия файла или получении пути до файла.
*/
string export_Graph(const Graph& graph, const vector<vector<int>> *path_matrix)
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
        {
            file_out << "\t" << i << " -- " << j;
            if (path_matrix != nullptr) file_out << fill_path((*path_matrix)[i][j]);
            file_out << ";\n";
        }
    }
    file_out << "}\n";
    file_out.close();
    const size_t BUF_SIZE = 1024;
    char dir_path[BUF_SIZE];
    if (getcwd(dir_path, BUF_SIZE) == NULL) throw runtime_error("Failed to get path dir");
    return string(dir_path) + "/" + file_name;
}

/*!
    \ingroup Export_module

    \brief Функция, создающая файл в с расширением .dot и записывающая в него граф. Также эта функция закрашивает указанный путь.
    \param[in] graph граф.
    \param[in] path указатель на массив, содержащий в себе путь.
    \param[in] path_len длинна массива.
    \return Путь до зозданного файла.
    \throw std::domain_error - При подаче несуществующего пути.
    \throw std::runtime_error - При возникновении ошибки открытия файла или получении пути до файла.
*/
string export_Graph(const Graph& graph, const int *path, const size_t path_len)
{
    if (!graph.has_path(path, path_len)) throw domain_error("This path does not exist!");
    vector<vector<int>> path_matrix(graph.get_size(), vector<int>(graph.get_size(), 0));
    for (int const *point = path; point != path + path_len - 1; ++point) path_matrix[*point][*(point + 1)] = 1;
    return export_Graph(graph, &path_matrix);
}

/*!for_each (path, path + path_len - 1, [&path_matrix](const int *point) {path_matrix[*point][*(point + 1)] = 1;});
    \ingroup Export_module

    \brief Функция, создающая файл в с расширением .dot и записывающая в него граф. Также эта функция закрашивает указанный путь.
    \param[in] graph граф.
    \param[in] path вектор, содержащий в себе путь.
    \return путь до зозданного файла.
    \throw std::domain_error - При подаче несуществующего пути.
    \throw std::runtime_error - При возникновении ошибки открытия файла или получении пути до файла.
*/
string export_Graph(const Graph& graph, const vector<int>& path)
{
    if (!graph.has_path(path)) throw domain_error("This path does not exist!");
    vector<vector<int>> path_matrix(graph.get_size(), vector<int>(graph.get_size(), 0));
    for (vector<int>::const_iterator point = path.begin(); point != path.end() - 1; ++point) path_matrix[*point][*(point + 1)] = 1;
    return export_Graph(graph, &path_matrix);
}