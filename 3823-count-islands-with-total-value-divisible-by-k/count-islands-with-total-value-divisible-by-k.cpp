class Solution {
public:
    vector<vector<int>> direction = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis,
             long long& sum) {

        int n = grid.size();
        int m = grid[0].size();

        vis[i][j] = 1;
        sum += grid[i][j];

        for (auto dir : direction) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (new_i >= 0 && new_i < n && new_j >= 0 && new_j < m &&
                vis[new_i][new_j] == 0 && grid[new_i][new_j] != 0) {

                dfs(new_i, new_j, grid, vis, sum);
            }
        }
    }

    int countIslands(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        stack<pair<int, int>> st;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    st.push({i, j});
                }
            }
        }

        int count = 0;

        while (!st.empty()) {
            auto val = st.top();
            st.pop();

            int i = val.first;
            int j = val.second;

            if (vis[i][j] == 1)
                continue;

            long long sum = 0;
            dfs(i, j, grid, vis, sum);

            if (sum % k == 0) {
                count++;
            }
        }

        return count;
    }
};