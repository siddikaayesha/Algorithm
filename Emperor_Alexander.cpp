#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int u, v, w;
    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

class DisjointSetUnion {
public:
    vector<int> parent, rank;
    
    DisjointSetUnion(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++)
            parent[i] = i;
    }

    int find(int node) {
        if (parent[node] != node)
            parent[node] = find(parent[node]);
        return parent[node];
    }

    void union_sets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } 
            else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } 
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

bool compareEdges(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.emplace_back(u, v, w);
    }
    
    sort(edges.begin(), edges.end(), compareEdges);
    
    DisjointSetUnion dsu(n);
    int totalCost = 0, edgesUsed = 0;
    vector<Edge> mstEdges;

    for (size_t i = 0; i < edges.size(); i++) {
        Edge edge = edges[i];
        if (dsu.find(edge.u) != dsu.find(edge.v)) {
            dsu.union_sets(edge.u, edge.v);
            totalCost += edge.w;
            edgesUsed++;
            mstEdges.push_back(edge);
        }
    }
    
    if (edgesUsed != n - 1) {
        cout << "Not Possible" << endl;
    } 
    else {
        cout << m - edgesUsed << " " << totalCost << endl;
    }

    return 0;
}
