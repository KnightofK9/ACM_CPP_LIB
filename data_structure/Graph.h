//
// Created by admin on 7/19/2018.
//
#include <vector>

#ifndef ACM_CPP_LIB_GRAPH_H
#define ACM_CPP_LIB_GRAPH_H
typedef std::pair<int, int> ii;
typedef std::vector<ii> vii;

class AdjacencyMatrixGraph {
public:
    std::vector<std::vector<int>> matrix;
    int n;

    AdjacencyMatrixGraph(int n) {
        this->n = n;

        std::vector<int> row;
        row.assign(n,0);
        matrix.assign(static_cast<unsigned int>(n), row);
    }

    virtual ~AdjacencyMatrixGraph() {

    }
};
class AdjacencyListGraph{
public:
    std::vector<vii> AdjList;
    int n;

    AdjacencyListGraph(int n) {
        this->n = n;
    }

};
class EdgeListGraph{
public:
    std::vector< std::pair<int, ii> > EdgeList;
    int n;
    EdgeListGraph(int n) {
        this->n = n;
    }
};

#endif //ACM_CPP_LIB_GRAPH_H
