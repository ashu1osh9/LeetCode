class Solution {
public:
vector<vector<vector<int>>>dp;
    int solve(int i, bool buy, vector<int>& prices,int cap ) {
        if (i == prices.size())
            return 0;

            if(cap==0)
            return 0;
            if(dp[i][buy][cap]!= -1)
            return dp[i][buy][cap];

        if (buy) {

            int profit = -prices[i] + solve(i + 1, false, prices,cap);
            int skip_buy = solve(i + 1, true, prices,cap);

            return dp[i][buy][cap] = max(profit, skip_buy);

        } else {

            int profit = prices[i] + solve(i + 1, true, prices,cap-1);
            int skip_sell = solve(i + 1, false, prices,cap);

            return dp[i][buy][cap]= max(profit, skip_sell);
        }
    }
    int maxProfit(vector<int>& prices) { 
        int n = prices.size();
        // n days × 2 states × 2 transaction capacities
         dp.assign(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, 1, prices,2); }
};
