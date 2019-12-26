//
// Created by Luzh on 2019/12/12.
//

#ifndef BFS_GRAPH_H
#define BFS_GRAPH_H

#include <iostream>
#include <vector>
#include <list>

class Node {
public:
    int val;
    std::vector<Node* > neighbors;

    Node() {}

    Node(int _val, std::vector<Node* > _neighbors): val(_val), neighbors(_neighbors) {}
};

class Graph {
private:
    int mV; // 顶点的数量；
    std::list<int> *adj; // 邻接表；
    void BFSUtil(int v, bool visited[]);

public:
    Graph(int v); // 构造函数；
    void addEdge(int v, int w); // 向图中添加一条边；
    void BFS(int v);
    void DFS(int v);
    void DFSRecursion(int v, bool* visited);
    Node* cloneGraph(Node* node);
    Node* cloneGraphWithDFS(Node* node);
    bool canFinish(int numCourses, std::vector<std::vector<int >>& prerequisites);
};


#endif //BFS_GRAPH_H
