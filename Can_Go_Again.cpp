#include <bits/stdc++.h>
using namespace std;
class Edge {
public:
    int u, v, c;
    Edge(int u, int v, int c) {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> EdgeList;
    while (m--) {
        int u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }
    
    int src;
    cin >> src;

    vector<int> dis(n + 1, INT_MAX);
    dis[src] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (Edge edge : EdgeList) {
            if (dis[edge.u] < INT_MAX && dis[edge.u] + edge.c < dis[edge.v]) {
                dis[edge.v] = dis[edge.u] + edge.c;
            }
        }
    }

    bool negativeCycle = false;
    for (Edge edge : EdgeList) {
        if (dis[edge.u] < INT_MAX && dis[edge.u] + edge.c < dis[edge.v]) {
            negativeCycle = true;
            break;
        }
    }

    if (negativeCycle) {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }

    int t;
    cin >> t;
    while (t--) {
        int des;
        cin >> des;
        if (dis[des] == INT_MAX) {
            cout << "Not Possible" << endl;
        } else {
            cout << dis[des] << endl;
        }
    }
    
    return 0;
}
