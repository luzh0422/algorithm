//
// Created by Luzh on 2019/12/12.
//

#include "Graph.h"
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <map>
#include <stack>

Graph::Graph(int v) {
    this->mV = v;
    adj = new std::list<int>[v];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::BFSUtil(int v, bool *visited) {
    std::queue<int> queue;

    visited[v] = true;
    queue.push(v);

    std::list<int>::iterator i;

    while(!queue.empty()) {
        v = queue.front();
        std::cout << v << " ";
        queue.pop();
        for (i = adj[v].begin(); i != adj[v].end(); i++) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push(*i);
            }
        }
    }
    std::cout << std::endl;
}

void Graph::BFS(int v) {
    bool *visited = new bool[mV];
    for (int i = 0; i < mV; ++ i) {
        visited[i] = false;
    }
    BFSUtil(v, visited);
}

void Graph::DFS(int v) {
    bool *visited = new bool[mV];
    for (int i = 0; i < mV; ++ i) {
        visited[i] = false;
    }
    visited[v] = true;
    std::stack<int> stack;
    stack.push(v);

    std::list<int>::iterator it;
    while(!stack.empty()) {
        v = stack.top();
        std::cout << v << " ";
        stack.pop();
        for (it = adj[v].begin(); it != adj[v].end(); ++ it) {
            if (visited[*it] == false) {
                visited[*it] = true;
                stack.push(*it);
            }
        }
    }
    std::cout << std::endl;
}

void Graph::DFSRecursion(int v, bool* visited) {
    visited[v] = true;
    std::cout << v << " ";
    for (std::list<int>::iterator it = adj[v].begin(); it != adj[v].end(); ++ it) {
        if (visited[*it] == false) {
            DFSRecursion(*it, visited);
        }
    }
}

class Node * Graph::cloneGraph(class Node * node) {
    if (!node) return NULL;

    std::queue<Node* > m_queue;
    std::map<Node*, Node*> m_map;
    Node* temp;
    Node* p;

    m_queue.push(node);

    while (!m_queue.empty()) {
        temp = m_queue.front();
        m_queue.pop();
        p = new Node(temp->val, {});
        m_map.insert({temp, p});
        for (std::vector<Node*>::iterator i = temp->neighbors.begin(); i != temp->neighbors.end(); ++ i) {
            if (m_map.find(*i) == m_map.end()) {
                m_queue.push(*i);
            }
        }
    }
    std::map<Node*, Node*>::iterator it;
    for (it = m_map.begin(); it != m_map.end(); ++ it) {
        for (Node *neighborsNode: it->first->neighbors) {
            it->second->neighbors.push_back(m_map.find(neighborsNode)->second);
        }
    }
    return m_map.find(node)->second;
}

class Node * Graph::cloneGraphWithDFS(class Node * node) {
    if (!node) return NULL;

    std::stack<Node* > stack;
    std::map<Node*, Node*> map;
    Node* temp;
    Node* p;
    stack.push(node);
    while(!stack.empty()) {
        temp = stack.top();
        stack.pop();
        p = new Node(temp->val, {});
        map.insert({temp, p});
        for (std::vector<Node*>::iterator it = temp->neighbors.begin(); it != temp->neighbors.end(); ++ it) {
            if (map.find(*it) == map.end()) {
                stack.push(*it);
            }
        }
    }
    for (std::map<Node*, Node*>::iterator it = map.begin(); it != map.end(); ++ it) {
        for (Node* neighborNode: it->first->neighbors) {
            it->second->neighbors.push_back(map.find(neighborNode)->second);
        }
    }
    return map.find(node)->second;
}

bool Graph::canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
    std::map<int, int> indegree;
    for (auto& v : prerequisites) {
        indegree[v[0]]++;
    }
    std::queue<int> queue;
    for (int i = 0; i < numCourses; ++ i) {
        if (indegree[i] == 0) {
            queue.push(i);
        }
    }
    int cnt = 0;
    while(!queue.empty()) {
        int k = queue.front();
        std::cout << k << " ";
        queue.pop();
        cnt++;
        for (auto& v : prerequisites) { // 没有构建graph，而是直接在依赖关系中查找；
            if (k == v[1]) {
                if (--indegree[v[0]] == 0) {
                    queue.push(v[0]);
                }
            }
        }
    }
    std::cout << std::endl;
    if (cnt != numCourses) {
        std::cout << "Failed to Complete topology sort" << std::endl;
        return false;
    }
    return true;
}


