//
// Created by Olcay Taner YILDIZ on 8.05.2023.
//

#include <string>
#include <vector>
#include <iostream>
#include "Graph.h"
#include "../DisjointSet.h"
#include "../Queue.h"
#include "../Heap/Heap.h"
#include "../Heap/MinHeap.h"

void bfsRecursive(std::string startNode, std::string endNode, std::vector<int> &path, std::vector<int> &shortestPath,
                  std::vector<bool> &visited);

namespace array{

    Graph::Graph(int vertexCount) : AbstractGraph(vertexCount){
        edges = new int*[vertexCount];
        names = new std::string[vertexCount];
        for (int i = 0; i < vertexCount; i++){
            edges[i] = new int[vertexCount];
        }
        for (int i = 0; i < vertexCount; i++){
            for (int j = 0; j < vertexCount; j++){
                edges[i][j] = 0;
            }
        }
    }

    Graph::~Graph() {
        for (int i = 0; i < vertexCount; i++){
            delete[] edges[i];
        }
        delete[] edges;
    }

    void Graph::addEdge(std::string from, std::string to) {
        edges[findIndex(from)][findIndex(to)] = 1;
    }

    void Graph::addEdge(std::string from, std::string to, int weight) {
        edges[findIndex(from)][findIndex(to)] = weight;
    }

    void Graph::connectedComponentDisjointSet() {
        DisjointSet sets = DisjointSet(vertexCount);
        for (int fromNode = 0; fromNode < vertexCount; fromNode++){
            for (int toNode = 0; toNode < vertexCount; toNode++){
                if (edges[fromNode][toNode] > 0){
                    if (sets.findSetRecursive(fromNode) != sets.findSetRecursive(toNode)){
                        sets.unionOfSets(fromNode, toNode);
                    }
                }
            }
        }
    }

    void Graph::depthFirstSearch(bool *visited, int fromNode) {
        for (int toNode = 0; toNode < vertexCount; toNode++){
            if (edges[fromNode][toNode] > 0){
                if (!visited[toNode]){
                    visited[toNode] = true;
                    depthFirstSearch(visited, toNode);
                }
            }
        }
    }

    void Graph::breadthFirstSearch(std::string startNode , std::string endNode) {

        int startIndex = findIndex(startNode);
        int endIndex = findIndex(endNode);

        std::vector<int> path;
        std::vector<int> shortestPath;
        std::vector<bool> visited(vertexCount, false);

        /*queue.enqueue(Element(startIndex));
        visited[startIndex] =true;
        distances[startIndex] = 0;*/
        //path.push_back(startIndex);

        bfsRecursive(startNode, endNode, path, shortestPath, visited) ;

        if (shortestPath.empty()) {
            std::cout << "no possible path" << std::endl;
        }
        else {
            std::cout << "Shortest path: ";
            for ( int node : path) {
                std::cout << names[node] << " ";
            }
                std::cout <<  std::endl;
            }
        }
       /* delete[] visited;
        delete[] distances;*/

        /*  Queue queue = Queue(100);
        queue.enqueue( Element(startNode));
        while (!queue.isEmpty()){
            fromNode = queue.dequeue().getData();
            for (int toNode = 0; toNode < vertexCount; toNode++) {
                if (edges[fromNode][toNode] > 0) {
                    if (!visited[toNode]){
                        visited[toNode] = true;
                        queue.enqueue( Element(toNode));
                    }
                }
            }
        }*/


    void Graph::bfsRecursive (std::string startNode, std::string endNode, std::vector<int> &path, std::vector<int> &shortestPath, std::vector<bool>& visited) {

        int startIndex = findIndex(startNode);
        int endIndex = findIndex(endNode);
        path.push_back(startIndex);
        visited[startIndex] = true;

        if (startIndex == endIndex && shortestPath.empty() || path.size() < shortestPath.size()) {
            shortestPath = path;
        } else {
            for (int toNode = 0 ; toNode < vertexCount ; toNode++ ) {
                if (edges[startIndex][toNode] > 0 && !visited[toNode]) {
                    bfsRecursive(names[toNode], endNode, path, shortestPath, visited);
                }
            }
        }
        visited[startIndex] = false;
        path.pop_back();



    }

    Path *Graph::bellmanFord(int source) {
        Path* shortestPaths = initializePaths(source);
        for (int i = 0; i < vertexCount - 1; i++){
            for (int fromNode = 0; fromNode < vertexCount; fromNode++){
                for (int toNode = 0; toNode < vertexCount; toNode++){
                    int newDistance = shortestPaths[fromNode].getDistance() + edges[fromNode][toNode];
                    if (newDistance < shortestPaths[toNode].getDistance()){
                        shortestPaths[toNode].setDistance(newDistance);
                        shortestPaths[toNode].setPrevious(fromNode);
                    }
                }
            }
        }
        return shortestPaths;
    }

    Path *Graph::dijkstra(int source) {
        Path* shortestPaths = initializePaths(source);
        MinHeap heap = MinHeap(vertexCount);
        for (int i = 0; i < vertexCount; i++){
            heap.insert( HeapNode(shortestPaths[i].getDistance(), i));
        }
        while (!heap.isEmpty()){
            HeapNode node = heap.deleteTop();
            int fromNode = node.getName();
            for (int toNode = 0; toNode < vertexCount; toNode++){
                int newDistance = shortestPaths[fromNode].getDistance() + edges[fromNode][toNode];
                if (newDistance < shortestPaths[toNode].getDistance()){
                    int position = heap.search(toNode);
                    heap.update(position, newDistance);
                    shortestPaths[toNode].setDistance(newDistance);
                    shortestPaths[toNode].setPrevious(fromNode);
                }
            }
        }
        return shortestPaths;
    }

    int **Graph::floydWarshall() {
        int** distances;
        distances = new int*[vertexCount];
        for (int i = 0; i < vertexCount; i++){
            distances[i] = new int[vertexCount];
            for (int j = 0; j < vertexCount; j++){
                distances[i][j] = edges[i][j];
            }
        }
        for (int k = 0; k < vertexCount; k++){
            for (int i = 0; i < vertexCount; i++){
                for (int j = 0; j < vertexCount; j++){
                    int newDistance = distances[i][k] + distances[k][j];
                    if (newDistance < distances[i][j]){
                        distances[i][j] = newDistance;
                    }
                }
            }
        }
        return distances;
    }

    Edge *Graph::edgeList(int &edgeCount) {
        Edge* list;
        edgeCount = 0;
        for (int i = 0; i < vertexCount; i++){
            for (int j = 0; j < vertexCount; j++){
                if (edges[i][j] > 0){
                    edgeCount++;
                }
            }
        }
        list = new Edge[edgeCount];
        int index = 0;
        for (int i = 0; i < vertexCount; i++){
            for (int j = 0; j < vertexCount; j++){
                if (edges[i][j] > 0){
                    list[index] = Edge(i, j, edges[i][j]);
                    index++;
                }
            }
        }
        return list;
    }

    void Graph::prim() {
        Path* paths = initializePaths(0);
        MinHeap heap = MinHeap(vertexCount);
        for (int i = 0; i < vertexCount; i++){
            heap.insert(HeapNode(paths[i].getDistance(), i));
        }
        while (!heap.isEmpty()){
            HeapNode node = heap.deleteTop();
            int fromNode = node.getName();
            for (int toNode = 0; toNode < vertexCount; toNode++){
                if (paths[toNode].getDistance() > edges[fromNode][toNode]){
                    int position = heap.search(toNode);
                    heap.update(position, edges[fromNode][toNode]);
                    paths[toNode].setDistance(edges[fromNode][toNode]);
                    paths[toNode].setPrevious(fromNode);
                }
            }
        }
    }

    void Graph::addName(int index, std::string name) {
        names[index] = std::move(name);
    }
    std::string* Graph::getNames() {
        return names;
    }
    int **Graph::getEdges() {
        return edges;
    }

     int Graph::findIndex (std::string word) {
        for (int i = 0 ; i < vertexCount ; i++ ) {
            if (names[i] == word) {
                return i;
            }
        }
        return -1;
    }

}
