// class Solution {
// public:
//     int solve(int i, bool buy, vector<int>& prices) {
//         if (i == prices.size())
//             return 0;

//         if (buy) {

//             int profit = -prices[i] + solve(i + 1, false, prices);
//             int skip_buy = solve(i + 1, true, prices);

//             return max(profit, skip_buy);

//         } else {

//             int profit = prices[i] + solve(i + 1, true, prices);
//             int skip_sell = solve(i + 1, false, prices);

//             return max(profit, skip_sell);
//         }
//     }
//     int maxProfit(vector<int>& prices) { return solve(0, 1, prices); }
// };


class Solution {
public:
vector<vector<int>>dp;
    int solve(int i, bool buy, vector<int>& prices) {
        if (i == prices.size())
            return 0;
             if(dp[i][buy] != -1)
            return dp[i][buy];

        if (buy) {

            int profit = -prices[i] + solve(i + 1, false, prices);
            int skip_buy = solve(i + 1, true, prices);

            return dp[i][buy] = max(profit, skip_buy);

        } else {

            int profit = prices[i] + solve(i + 1, true, prices);
            int skip_sell = solve(i + 1, false, prices);

            return dp[i][buy] = max(profit, skip_sell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        dp.assign(n,vector<int>(2,-1));
        
         return solve(0, 1, prices); }
};