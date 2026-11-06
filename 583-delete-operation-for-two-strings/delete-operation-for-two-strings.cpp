class Solution {
public:
    int dp[501][501];

    int solve(int i, int j, string &a, string &b) {
        int n = a.size();
        int m = b.size();

        if(i == n) return m-j;
        if(j == m) return n-i;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(a[i] == b[j])
            return dp[i][j] = solve(i+1, j+1, a, b);

        int x = 1 + solve(i+1, j, a, b);
        int y = 1 + solve(i, j+1, a, b);

        return dp[i][j] = min(x, y);
    }

    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, word1, word2);
    }
};
