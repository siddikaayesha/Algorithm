#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char a[N][N];
bool vis[N][N];
int n, m;
bool valid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '.' && !vis[x][y]);
}

void dfs(int x, int y) {
    vis[x][y] = true; 
    
    for (pair<int,int> p : d) {
        int nx = x + p.first;
        int ny = y + p.second;
        if (valid(nx, ny)) {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            vis[i][j] = false;
        }
    }

    int c = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.' && !vis[i][j]) {
                dfs(i, j);
                c++;
            }
        }
    }
    cout << c << endl;

    return 0;
}
