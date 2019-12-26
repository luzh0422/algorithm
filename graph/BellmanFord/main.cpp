#include <iostream>
#include <vector>
#include <cmath>

using std::cout;
using std::endl;
using std::vector;
const int INF = 1000000000;

struct Edge {
    int from;
    int to;
    double weight;
};

struct Graph {
private:
    int V;
    vector<Edge> E;
    vector<int> pre;
    vector<int> d;

public:
    Graph(int v): V(v) {
        for (int i = 0; i < v; i ++) {
            pre.push_back(i);
        }
//        d.insert(d.begin(), V, INFINITY);
        for (int i = 0; i < v; i ++) {
            d.push_back(INF);
        }
    }
    void insertEdge(int from, int to, double weight) {
        Edge e;
        e.from = from;
        e.to = to;
        e.weight = weight;
        E.push_back(e);
    }

    void bellmanFord(int s) {
//        vector<double > d(V);
        for (int i = 0; i < V; i++) {
            d[i] = INF;
        }
        d[s] = 0;
        bool updated;
        for (int i = 0; i < V; i++) {
            updated = false;
            for (auto edge: E) {
                if (d[edge.from] + edge.weight < d[edge.to]) {
                    d[edge.to] = d[edge.from] + edge.weight;
                    pre[edge.to] = edge.from;
                    updated = true;
                }
            }
            if (!updated) {
                break;
            }
        }
        if (updated) {
            cout << "There is a negative cycle." << endl;
        } else {
            for(int i = 0; i < V; i++) {
                std::cout << d[i] << " ";
            }
            std::cout << std::endl;
        }
    }

    void printBellmanFord(int s, int t) {
//        if (d[t])
        if (s == t) {
            std::cout << s << " ";
            return;
        }
        printBellmanFord(s, pre[t]);
        std::cout << t << " ";
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Graph g(6);
    g.insertEdge(0, 1, 10);
    g.insertEdge(0, 2, 20);
    g.insertEdge(2, 1, -15);
    g.insertEdge(2, 4, 5);
    g.insertEdge(4, 3, -5);
    g.bellmanFord(0);
    g.printBellmanFord(0, 4);
    return 0;
}
