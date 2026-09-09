class Solution {
public:
vector<int>dp;
    int solve(int n){

        if(n==0) return 0;

        if(dp[n] != -1) {
            return dp[n];
            }
        int ans = INT_MAX;

        for(int i = 1;i*i<=n;i++){

            int sq = i*i;
            int rem = n - sq;

            int curr = 1 + solve(rem);

            ans = min(ans,curr);

        }
        return dp[n] = ans;
    }
    int numSquares(int n) {
        dp.assign(n+1,-1);

        return solve(n);
        
    }
};