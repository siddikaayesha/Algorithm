#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> grid;
vector<vector<bool>> visited;
vector<int> directions = {-1, 0, 1, 0, -1, 0};

void bfs(int x, int y, int &area) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    area = 1;

    while (!q.empty()) {
        auto [curr_x, curr_y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int new_x = curr_x + directions[i];
            int new_y = curr_y + directions[i + 1];

            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && 
                !visited[new_x][new_y] && grid[new_x][new_y] == '.') {
                visited[new_x][new_y] = true;
                q.push({new_x, new_y});
                area++;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int minArea = INT_MAX;
    bool found = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == '.') {
                int area = 0;
                bfs(i, j, area);
                found = true;
                minArea = min(minArea, area);
            }
        }
    }

    cout << (found ? minArea : -1) << endl;
    return 0;
}
