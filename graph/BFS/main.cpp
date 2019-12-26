#include <iostream>
#include <vector>
#include "Graph.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Graph g(5);
    g.addEdge(0, 1);
//    g.addEdge(0, 2);
//    g.addEdge(0, 3);
//    g.addEdge(0, 4);
    g.addEdge(1, 2);
//    g.addEdge(1, 3);
//    g.addEdge(1, 4);
    g.addEdge(2, 3);
//    g.addEdge(2, 4);
    g.addEdge(3, 4);
    std::cout << "Following is BFS Traversal (starting from vertex 2) \n";
    g.BFS(2);
    g.DFS(2);
    bool* visited = new bool(5);
    for (int i = 0; i < 5; i++) {
        visited[i] = false;
    }
    g.DFSRecursion(2, visited);
    std::cout << std::endl;
    std::vector<std::vector<int >> vec;
    std::vector<int> a = {0, 1};
    std::vector<int> b = {1, 0};
    vec.push_back(a);
    vec.push_back(b);
    g.canFinish(2, vec);
    return 0;
}
