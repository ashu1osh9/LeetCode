
class Solution {
public:
    int mod = 1e9 + 7;

    int solve(int steps, int pos, int arrLen, vector<vector<int>>& dp) {
        if (pos < 0 || pos >= arrLen)
            return 0;
        if (steps == 0)
            return pos == 0 ? 1 : 0;
        if (dp[steps][pos] != -1)
            return dp[steps][pos];
        int left = solve(steps - 1, pos - 1, arrLen, dp);
        int stay = solve(steps - 1, pos, arrLen, dp);
        int right = solve(steps - 1, pos + 1, arrLen, dp);
        return dp[steps][pos] = ((long long)left + stay + right) % mod;
    }

    int numWays(int steps, int arrLen) {

        arrLen = min(arrLen, steps / 2 + 1);
        vector<vector<int>> dp(steps + 1, vector<int>(arrLen, -1));
        return solve(steps, 0, arrLen, dp);
    }
};
