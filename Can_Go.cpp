#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
vector<pair<int, int>> adj[N];
int dis[N];

void dijkstra(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    dis[source] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (cost > dis[node]) continue;

        for (pair<int,int> edge : adj[node]) {
            int childNode = edge.first;
            int childCost = edge.second;

            if (cost + childCost < dis[childNode]) {
                dis[childNode] = cost + childCost;
                pq.push({dis[childNode], childNode});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
    }

    int src;
    cin >> src;

    for (int i = 1; i <= n; i++) {
        dis[i] = INT_MAX;
    }

    dijkstra(src);

    int t;
    cin >> t;
    while (t--) {
        int des, cost;
        cin >> des >> cost;

        if (dis[des] <= cost) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
