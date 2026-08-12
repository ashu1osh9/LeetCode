class Solution {
public:
    vector<vector<int>>dp;

    int solve(string &word1, string &word2, int n, int m) {

        if(n == word1.size())
            return word2.size() - m;

        if(m == word2.size())
            return word1.size() - n;
    if(dp[n][m] != -1)
    return dp[n][m];

        if(word1[n] != word2[m]) {

            int insert = 1 + solve(word1, word2, n, m + 1);

            int del = 1 + solve(word1, word2, n + 1, m);

            int rep = 1 + solve(word1, word2, n + 1, m + 1);

            return dp[n][m] = min({insert, del, rep});
        }

        else {

            return dp[n][m] = solve(word1, word2, n + 1, m + 1);
        }
    }


    int minDistance(string word1, string word2) {
        dp.clear();
        int n = word1.size();
        int m = word2.size();
        dp.assign(n,vector<int>(m,-1));

        return solve(word1, word2, 0, 0);
    }
};