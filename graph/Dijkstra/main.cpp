#include <iostream>
#include <vector>

using namespace std;
const int INF = 1000000000;

void Dijkstra(int n, int s, vector<vector<int>> G, vector<int>& pre, vector<int>& d) {
    /**
     * init
     */
    vector<bool> visit(n);
    fill(d.begin(), d.end(), INF);
    for (int i = 0; i < n; ++ i) {
        pre[i] = i;
    }
    d[s] = 0;

    for (int i = 0; i < n; ++ i) {
        int u = -1;
        int min = INF;
        /**
         * 找到从起始点s触发最小距离的点作为中介点；
         */
        for (int j = 0; j < n; ++ j) {
            if (visit[j] == false && d[j] < min) {
                u = j;
                min = d[j];
            }
        }
        if (u == -1) return;
        /**
         * 记录中介点；
         */
        visit[u] = true;
        /**
         * 根据新的中介点，更新从起始点s触发经过中介点u的距离d；
         */
        for (int j = 0; j < n; ++j) {
            if (visit[j] == false && d[u] + G[u][j] < d[j]) {
                d[j] = d[u] + G[u][j];
                pre[j] = u;
            }
        }
    }
}


/**
 * 递归的方式遍历从s到v的最短路径。
 */
void DFSPrint(int s, int v, vector<int> pre)
{
    if (v == s) {
        cout << s << " ";
        return;
    }
    DFSPrint(s, pre[v], pre);
    cout << v << " ";
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    int n = 6;
    vector<int> pre(n);
    vector<int> d(n);
    vector<vector<int>> G = { {0,1,INF,4,4,INF},
                              {INF,0,INF,2,INF,INF},
                              {INF,INF,0,INF,INF,1},
                              {INF,INF,2,0,3,INF},
                              {INF,INF,INF,INF,0,3},
                              {INF,INF,INF,INF,INF,0} };

    Dijkstra(n, 0, G, pre, d);
    for (auto x : d)
        cout << x << " ";
    cout << endl;

    //输出从起点s到顶点v的最短路径
    DFSPrint(0, 5, pre);
    return 0;
}
