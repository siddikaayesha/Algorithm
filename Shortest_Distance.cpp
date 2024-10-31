#include <bits/stdc++.h>
#define ll long long int
using namespace std;
const ll INF = 1e5+5;
int main() {
    ll n, e;
    cin >> n >> e;
    ll adj[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = INF;
            if (i == j) {
                adj[i][j] = 0;
            }
        }
    }

    while (e--) {
        ll u, v, c;
        cin >> u >> v >> c;
        u--;
        v--;
        if (adj[u][v] > c) {
            adj[u][v] = c;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adj[i][k] < INF && adj[k][j] < INF) {
                    if (adj[i][j] > adj[i][k] + adj[k][j]) {
                        adj[i][j] = adj[i][k] + adj[k][j];
                    }
                }
            }
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int src, des;
        cin >> src >> des;
        src--;
        des--;

        if (adj[src][des] == INF) {
            cout << -1 << endl;
        } else {
            cout << adj[src][des] << endl;
        }
    }

    return 0;
}
