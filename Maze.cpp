#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>
const int N = 1005;
int vis[N][N];
map<pi, pi> parent;
vector<pi> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, m;

bool isValid(int i, int j) {
    return !vis[i][j] && i >= 0 && i < n && j >= 0 && j < m;
}

void bfs(pi start) {
    queue<pi> q;
    q.push(start);
    vis[start.first][start.second] = true;

    while (!q.empty()) {
        pi current = q.front();
        q.pop();
        int x = current.first, y = current.second;

        for (auto move : directions) {
            int newX = x + move.first;
            int newY = y + move.second;
            if (isValid(newX, newY)) {
                q.push({newX, newY});
                parent[{newX, newY}] = {x, y};
                vis[newX][newY] = true;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    pi start;
    string line;
    char grid[n][m];
    int destX, destY;

    for (int i = 0; i < n; i++) {
        cin >> line;
        for (int j = 0; j < m; j++) {
            grid[i][j] = line[j];
            if (line[j] == '#') {
                vis[i][j] = true;
            }
            if (line[j] == 'R') {
                start = {i, j};
            }
            if (line[j] == 'D') {
                destX = i;
                destY = j;
            }
        }
    }

    bfs(start);

    if (!vis[destX][destY]) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    } else {
        while (destX != start.first || destY != start.second) {
            pi prev = parent[{destX, destY}];
            grid[prev.first][prev.second] = 'X';
            destX = prev.first;
            destY = prev.second;
        }
        grid[start.first][start.second] = 'R';

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
