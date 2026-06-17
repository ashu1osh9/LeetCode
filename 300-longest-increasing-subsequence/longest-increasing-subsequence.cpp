class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& nums, int curr, int prev) {
        if (curr == nums.size()) {
            return 0;
        }

        if (dp[curr][prev + 1] != -1) {
            return dp[curr][prev + 1];
        }

        // Skip current element
        int notTake = solve(nums, curr + 1, prev);

        // Take current element
        int take = 0;
        if (prev == -1 || nums[curr] > nums[prev]) {
            take = 1 + solve(nums, curr + 1, curr);
        }

        return dp[curr][prev + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, vector<int>(n + 1, -1));

        return solve(nums, 0, -1);
    }
};