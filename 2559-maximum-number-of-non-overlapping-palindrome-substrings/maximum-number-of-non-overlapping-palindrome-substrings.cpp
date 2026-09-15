class Solution {
public:
    vector<vector<int>>dp;
    bool isPalindrome(string &s, int i, int j) {

        while(i < j) {
            if(s[i] != s[j])
                return false;

            i++;
            j--;
        }

        return true;
    }

    int solve(int i, string &s, int k) {

        if(i >= s.size())
            return 0;

            if(dp[i][k] != -1) return dp[i][k];

        int nottake = solve(i + 1, s, k);

        int take = 0;

        for(int j = i + k - 1; j < s.size(); j++) {

            if(isPalindrome(s, i, j)) {

                take = max(take, 1 + solve(j + 1, s, k));
            }
        }

        return dp[i][k] = max(take, nottake);
    }

    int maxPalindromes(string s, int k) {
        dp.assign(s.size()+1, vector<int>(k+1, -1));

        return solve(0, s, k);
    }
};