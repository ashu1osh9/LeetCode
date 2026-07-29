class Solution {
public:
    int n, m;

    vector<pair<int, int>> dir = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    void bfs(queue<pair<int, int>> &q,
             vector<vector<int>> &vis,
             vector<vector<int>> &heights) {

        while (!q.empty()) {

            auto node = q.front();
            q.pop();

            int row = node.first;
            int col = node.second;

            for (auto d : dir) {

                int nr = row + d.first;
                int nc = col + d.second;

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < m &&
                    vis[nr][nc] == 0 &&
                    heights[nr][nc] >= heights[row][col]) {

                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        n = heights.size();
        m = heights[0].size();

        vector<vector<int>> vp(n, vector<int>(m, 0));
        vector<vector<int>> va(n, vector<int>(m, 0));

        queue<pair<int, int>> qp;
        queue<pair<int, int>> qa;

        // Pacific (Top Row) 
        for (int j = 0; j < m; j++) {
            qp.push({0, j});
            vp[0][j] = 1;
        }

        // Pacific (Left Column)
        for (int i = 1; i < n; i++) {
            qp.push({i, 0});
            vp[i][0] = 1;
        }

        // Atlantic (Bottom Row)
        for (int j = 0; j < m; j++) {
            qa.push({n - 1, j});
            va[n - 1][j] = 1;
        }

        // Atlantic (Right Column)
        for (int i = 0; i < n - 1; i++) {
            qa.push({i, m - 1});
            va[i][m - 1] = 1;
        }

        bfs(qp, vp, heights);
        bfs(qa, va, heights);

        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (vp[i][j] && va[i][j]) {
                    ans.push_back({i, j});
                }

            }
        }

        return ans;
    }
};