//
// Created by Olcay Taner YILDIZ on 15.05.2023.
//

#ifndef DATASTRUCTURES_CPP_ABSTRACTGRAPH_H
#define DATASTRUCTURES_CPP_ABSTRACTGRAPH_H


#include "Path.h"
#include "../List/Graph/Edge.h"
#include "iostream"

class AbstractGraph {
protected:
    int vertexCount;
    virtual void depthFirstSearch(bool* visited, int fromNode) = 0;
    virtual void breadthFirstSearch(std::string startNode , std::string endNode) = 0;
    virtual Edge* edgeList(int& edgeCount) = 0;
    Path* initializePaths(int source) const;
public:
    explicit AbstractGraph(int vertexCount);
    int connectedComponentDfs();
    int connectedComponentBfs();
    void kruskal();
};


#endif //DATASTRUCTURES_CPP_ABSTRACTGRAPH_H
