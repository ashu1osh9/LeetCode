class Solution {
public:
vector<vector<int>>dp;
    int solve(vector<vector<int>>& dungeon, int i, int j) {

        if (i == dungeon.size() - 1 && j == dungeon[0].size() - 1) {
            return max(1, 1 - dungeon[i][j]);
        }

        if (i >= dungeon.size() || j >= dungeon[0].size()) {
            return INT_MAX;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];

        int right = solve(dungeon, i, j + 1);
        int down = solve(dungeon, i + 1, j);

        int next = min(right, down);

        return dp[i][j] = max(1, next - dungeon[i][j]);
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n =dungeon.size();
        int m = dungeon[0].size();
        dp.assign(n+1,vector<int>(m+1,-1));
        return solve(dungeon, 0, 0);
    }
};