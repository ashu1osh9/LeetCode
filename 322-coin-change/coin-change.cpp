class Solution {
public:
    vector<vector<int>>dp;
    int solve(vector<int>& coins, int amount,int n){

           if(amount == 0)
            return 0;

        if(amount < 0)
            return 1e9;

        if(n < 0)
            return 1e9;
    if(dp[n][amount]!= -1) return dp[n][amount];
        int take = 1 +  solve(coins,amount-coins[n],n);
        int nottake = solve(coins,amount, n -1);
        
        return dp[n][amount] = min(take, nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.assign(coins.size(),vector<int>(amount+1, -1));
     int ans = solve(coins, amount, coins.size() - 1);

        if(ans == 1e9)
            return -1;

        return ans;
    }
};