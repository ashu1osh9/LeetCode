class Solution {
public:
    vector<int> dp;

    int solve(vector<int>& nums, int st, int end) {
        if (st > end) {
            return 0;
        }

        if (dp[st] != -1) {
            return dp[st];
        }

        int take = nums[st] + solve(nums, st + 2, end);
        int notTake = solve(nums, st + 1, end);

        return dp[st] = max(take, notTake);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) {
            return nums[0];
        }

        dp.assign(n, -1);
        int first = solve(nums, 0, n - 2);

        dp.assign(n, -1);  
        int last = solve(nums, 1, n - 1);

        return max(first, last);
    }
};