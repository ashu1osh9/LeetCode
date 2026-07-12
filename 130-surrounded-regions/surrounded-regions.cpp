class Solution {
public:
    vector<vector<int>> direction = {
        {-1,0},
        {1,0},
        {0,-1},
        {0,1}
    };

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        vector<vector<char>> ans(n, vector<char>(m, 'X'));
        vector<vector<int>> visited(n, vector<int>(m, 0));

        queue<pair<int,int>> que;

        // Boundary cells
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(i == 0 || i == n-1 || j == 0 || j == m-1) {

                    if(board[i][j] == 'O') {
                        visited[i][j] = 1;
                        que.push({i, j});
                        ans[i][j] = 'O';
                    }
                }

                if(board[i][j] == 'X') {
                    visited[i][j] = 1;
                    ans[i][j] = 'X';
                }
            }
        }

        // BFS
        while(!que.empty()) {

            pair<int,int> idx = que.front();
            que.pop();

            int r = idx.first;
            int c = idx.second;

            for(auto &dir : direction) {

                int nr = r + dir[0];
                int nc = c + dir[1];

                if(nr >= 0 && nr < n &&
                   nc >= 0 && nc < m &&
                   board[nr][nc] == 'O' &&
                   !visited[nr][nc]) {

                    visited[nr][nc] = 1;
                    ans[nr][nc] = 'O';
                    que.push({nr, nc});
                }
            }
        }

        board = ans;
    }
};