#include <bits/stdc++.h>
using namespace std;

bool vis[100][100];
int dis[100][100];
vector<pair<int, int>> d = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
                                       {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

bool valid(int i, int j, int n, int m) {
    return i >= 0 && i < n && j >= 0 && j < m;
}

void bfs(int si, int sj, int target_i, int target_j, int n, int m) {
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;

    while (!q.empty()) {
        pair<int, int> par = q.front();
        int x = par.first, y = par.second;
        q.pop();

        if (x == target_i && y == target_j) {
            return;
        }

        for (pair<int,int> child : d) {
            int ci = x + child.first;
            int cj = y + child.second;
            if (valid(ci, cj, n, m) && !vis[ci][cj]) {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[x][y] + 1;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        int knight_x, knight_y;
        cin >> knight_x >> knight_y;

        int queen_x, queen_y;
        cin >> queen_x >> queen_y;

        memset(vis, false, sizeof(vis));
        memset(dis, -1, sizeof(dis));

        bfs(knight_x, knight_y, queen_x, queen_y, n, m);

        cout << dis[queen_x][queen_y] << endl;
    }

    return 0;
}
