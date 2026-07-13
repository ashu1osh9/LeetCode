class Solution {
public:
    vector<pair<int, int>> directions = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1}
    };

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int islands = 0;
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == '1') {
                    islands++;
                    q.push({i, j});
                    grid[i][j] = '0';

                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();

                        for (auto dir : directions) {
                            int nx = x + dir.first;
                            int ny = y + dir.second;

                            if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                                grid[nx][ny] == '1') {

                                grid[nx][ny] = '0';
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }

        return islands;
    }
};