#include "graph.hpp"

#include <algorithm>

//! Добавление узла в граф
/*!
    \ingroup Graph_module

    \details Метод класса Graph, добвлющий новый узел путём расширения матрицы смежности.
*/
void Graph::add_Node()
{
    for_each(adjacency_matrix.begin(), adjacency_matrix.end(), [](vector<int>& row)
    {
        row.push_back(0);
    });
    adjacency_matrix.push_back(vector<int>(size + 1, 0)); 
    size++;
}

//! Добавление ребра в граф
/*!
    \ingroup Graph_module

    \details Метод класса Graph, добвлющий новое ребро путём изменения матрицы смежности.

    \param[in] num_node1, num_node2 индексы вершин, принадлежащих ребру, в матрице смежности.
*/
void Graph::add_Edge(const size_t num_node1, const size_t num_node2)
{
    if (num_node1 < size && num_node2 < size && num_node1 != num_node2)
    {
        adjacency_matrix[num_node1][num_node2] = 1;
        adjacency_matrix[num_node2][num_node1] = 1;
    }
}

//! Удаление узла из графа
/*!
    \ingroup Graph_module

    \details Метод класса Graph, удаляющий узел гравфа. Для этого он вырезает столбец и строку из матрицы смежности.

    \param[in] num_node индекс удаляемого узла в матрице смежности.
*/
void Graph::remove_Node(const size_t num_node)
{
    if (num_node < size)
    {
        adjacency_matrix.erase(adjacency_matrix.begin() + num_node); 
        for_each (adjacency_matrix.begin(), adjacency_matrix.end(), [&num_node] (vector<int>& row)
        {
            row.erase(row.begin() + num_node);
        });
        size--;
    }
}

//! Удаление ребра из графа
/*!
    \ingroup Graph_module

    \details Метод класса Graph, удаляющий ребро графа. Для этого он помечает ребро в матрице смежности символом "0".

    \param[in] num_node1, num_node2 индексы вершин, принадлежащих удаляемому ребру, в матрице смежности,.
*/
void Graph::remove_Edge(const size_t num_node1, const size_t num_node2)
{
    if (num_node1 < size && num_node2 < size && num_node1 != num_node2)
    {
        adjacency_matrix[num_node1][num_node2] = 0;
        adjacency_matrix[num_node2][num_node1] = 0;
    }
}

//! Проверка сущиствования ребра в графе
/*!
    \ingroup Graph_module

    \details Метод класса Graph, проверящий метку ячейки в матрице смежности.
    
    \param[in] num_node1, num_node2 индекс вершин, принадлежащих проверяемому ребру, в матрице смежности.
    \return True если такое ребро существет. Иначе False.
*/
bool Graph::is_connected(const size_t num_node1, const size_t num_node2) const
{
    if (num_node1 < size && num_node2 < size && num_node1 != num_node2)
    {
        return adjacency_matrix[num_node1][num_node2] == 1;
    }
    return false;
}

//! Проверка пути
/*!
    \ingroup Graph_module

    \details Метод класса Graph, проверящий сущиствования пути в графе.
    
    \param[in] path массив содержащий путь.
    \param[in] len длина массива.
    \return True если путь существует. Иначе False.
*/
bool Graph::has_path(const int *path, const size_t len) const
{
    if (len <= 1) return false;
    for (size_t i = 0; i < len - 1; ++i)
    {
        if (!this->is_connected(path[i], path[i + 1])) return false;
    }
    return true;
}

//! Проверка пути
/*!
    \ingroup Graph_module

    \details Метод класса Graph, проверящий сущиствования пути в графе.
    
    \param[in] path вектор содержащий путь.
    \return True если путь существует. Иначе False.
*/
bool Graph::has_path(const vector<int> &path) const
{
    if (path.size() <= 1) return false;
    for (size_t i = 0; i < path.size() - 1; ++i)
    {
        if (!this->is_connected(path[i], path[i + 1])) return false;
    }
    return true;
}

//! Гетер строки
/*!
    \ingroup Graph_module
path.size()
    \details Метод класса Graph, возвращающий строку матрицы смежности.

    \param[in] num_row индекс строки в матрице смежности,.
    \return Строку с индексом num_row.
*/
vector<int> Graph::get_row(const size_t num_row) const
{
    if (num_row < size)
    {
        return adjacency_matrix[num_row];
    }
    return {};
}

//! Гетер кол-ва узлов
/*!
    \ingroup Graph_module

    \details Метод класса Graph, возвращающий кол-во узлов гравфа.

    \return Кол-во узлов в графе.
*/
size_t Graph::get_size() const
{
    return size;
}