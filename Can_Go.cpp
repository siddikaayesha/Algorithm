#include <bits/stdc++.h>
using namespace std;
const int N=1005;
int n, m;
char a[N][N];
bool vis[N][N];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

bool valid(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= m || a[i][j] == '#' || vis[i][j]) {
        return false;
    }
    return true;
}

bool dfs(int si, int sj, int di, int dj) {
    if (si == di && sj == dj) {
        return true;
    }
    
    vis[si][sj] = true;
    
    for (int i = 0; i < 4; i++) {
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        
        if (valid(ci, cj) && (a[ci][cj] == '.' || a[ci][cj] == 'B')) {
            if (dfs(ci, cj, di, dj)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    
    int ax = -1, ay = -1, bx = -1, by = -1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'A') {
                ax = i;
                ay = j;
            } else if (a[i][j] == 'B') {
                bx = i;
                by = j;
            }
        }
    }

    if (ax == -1 || ay == -1 || bx == -1 || by == -1) {
        cout << "NO" << endl;
        return 0;
    }
    
    memset(vis, false, sizeof(vis));
    
    if (dfs(ax, ay, bx, by)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}
