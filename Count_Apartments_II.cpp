#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool vis[N][N];
char a[N][N];
int n, m; 

bool valid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '.' && !vis[x][y]);
}

int dfs(int x, int y) {
    vis[x][y] = true;
    int room = 1;

    for (pair<int,int> p : d) {
        int nx = x + p.first;
        int ny = y + p.second;
        if (valid(nx, ny)) {
            room += dfs(nx, ny);
            }
    }
    return room;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            vis[i][j] = false; 
        }
    }

    vector<int> v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
             if (a[i][j] == '.' && !vis[i][j]) {
                int size = dfs(i, j);  
                v.push_back(size); }
        }
    }

    sort(v.begin(), v.end());
    if (v.empty()) {
        cout << "0" << endl;
    } 
    else {
        for (int val : v) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
