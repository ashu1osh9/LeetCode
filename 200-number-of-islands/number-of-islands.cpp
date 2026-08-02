// T.C => O(N*M)  S.C => O(N*M)
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> direction = {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1}
        };

        int islands = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == '1') {

                    islands++;

                    queue<pair<int, int>> que;
                    que.push({i, j});

                    // Mark visited
                    grid[i][j] = '0';

                    while (!que.empty()) {

                        pair<int, int> curr = que.front();
                        que.pop();

                        int row = curr.first;
                        int col = curr.second;

                        for (vector<int> dir : direction) {

                            int nr = row + dir[0];
                            int nc = col + dir[1];

                            if (nr >= 0 && nr < n &&
                                nc >= 0 && nc < m &&
                                grid[nr][nc] == '1') {

                                grid[nr][nc] = '0';   // visited
                                que.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }

        return islands;
    }
};