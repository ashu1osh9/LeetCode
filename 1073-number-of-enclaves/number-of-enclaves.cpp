class Solution {
public:
    vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int numEnclaves(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> que;

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1) {
                    count++;

                    if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) &&
                        !visited[i][j]) {
                        visited[i][j] = 1;
                        que.push({i, j});
                        count--;
                    }
                }
            }
        }

        while (!que.empty()) {

            auto idx = que.front();
            que.pop();

            int r = idx.first;
            int c = idx.second;

            for (auto& dir : direction) {

                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    grid[nr][nc] == 1 && !visited[nr][nc]) {

                    visited[nr][nc] = 1;
                    que.push({nr, nc});
                    count--;
                }
            }
        }

        return count;
    }
};