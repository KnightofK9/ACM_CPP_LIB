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
    int** matrix;
    int n;

    AdjacencyMatrixGraph(int n) {
        this->matrix = new int*[n];
        for(int i = 0; i < n; i++){
            this->matrix[i] = new int[n];
        }
        this->n = n;
    }

    virtual ~AdjacencyMatrixGraph() {
        for(int y  = 0; y<n;y++){
            for(int x = 0; x<n; x++){
                delete matrix[y][x];
            }
            delete[] matrix[y];
        }
        delete[] matrix;
        matrix = nullptr;
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
