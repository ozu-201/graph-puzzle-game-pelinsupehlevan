//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//

#ifndef DATASTRUCTURES_CPP_GRAPH_H
#define DATASTRUCTURES_CPP_GRAPH_H


#include "../../General/AbstractGraph.h"
#include "../../List/Graph/Edge.h"
#include "iostream"
#include <string>
#include "vector"

namespace array{
    class Graph : public AbstractGraph{
    private:
        int** edges;
        std::string* names;
    public:
        explicit Graph(int vertexCount);
        ~Graph();
        void addEdge(int from, int to);
        void addEdge(int from, int to, int weight);
        void connectedComponentDisjointSet();
        Path* bellmanFord(int source);
        Path* dijkstra(int source);
        int** floydWarshall();
        void prim();
        std::string* getNames();
        int **getEdges();
        void addName(int index, std::string name);
        void bfsRecursive (std::string startNode, std::string endNode, std::vector<int> &path, std::vector<int> &shortestPath, std::vector<bool>& visited);
        int findIndex (std::string word);
        void breadthFirstSearch(std::string startNode , std::string endNode) override;
    protected:
        void depthFirstSearch(bool* visited, int fromNode) override;
        Edge* edgeList(int& edgeCount) override;


    };

}


#endif //DATASTRUCTURES_CPP_GRAPH_H
