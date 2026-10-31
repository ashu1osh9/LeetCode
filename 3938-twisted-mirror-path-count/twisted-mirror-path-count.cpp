class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    int solve(int i, int j, int d, vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();

        if(i >= n || j >= m) return 0;

        if(i == n-1 && j == m-1) return 1;

        if(dp[i][j][d] != -1) return dp[i][j][d];

        if(g[i][j] == 1) {
            if(d == 0)
                return dp[i][j][d] = solve(i+1, j, 1, g);
            else
                return dp[i][j][d] = solve(i, j+1, 0, g);
        }

        int right = solve(i, j+1, 0, g);
        int down = solve(i+1, j, 1, g);

        return dp[i][j][d] = (right + down) % mod;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        dp.assign(n, vector<vector<int>>(m, vector<int>(2, -1)));

        return solve(0, 0, 0, grid);
    }
};