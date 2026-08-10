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

// 

// class Solution {
// public:
// vector<vector<int>>dp;
//     int solve(int i, bool buy, vector<int>& prices) {
//         if (i == prices.size())
//             return 0;
//              if(dp[i][buy] != -1)
//             return dp[i][buy];

//         if (buy) {

//             int profit = -prices[i] + solve(i + 1, false, prices);
//             int skip_buy = solve(i + 1, true, prices);

//             return dp[i][buy] = max(profit, skip_buy);

//         } else {

//             int profit = prices[i] + solve(i + 1, true, prices);
//             int skip_sell = solve(i + 1, false, prices);

//             return dp[i][buy] = max(profit, skip_sell);
//         }
//     }
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
        
//         dp.assign(n,vector<int>(2,-1));
        
//          return solve(0, 1, prices); }
// };

// tabulation with if and else -- no need to consider the transititaion for the dp table 
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // Base case
        dp[n][0] = 0;
        dp[n][1] = 0;

        for (int i = n - 1; i >= 0; i--) {

            for (int buy = 0; buy <= 1; buy++) {

                if (buy == 1) {

                    // Buy
                    int profit = -prices[i] + dp[i + 1][0];

                    // Skip buying
                    int skip = dp[i + 1][1];

                    dp[i][1] = max(profit, skip);
                }

                else {

                    // Sell
                    int profit = prices[i] + dp[i + 1][1];

                    // Skip selling
                    int skip = dp[i + 1][0];

                    dp[i][0] = max(profit, skip);
                }
            }
        }

        return dp[0][1];
    }
};