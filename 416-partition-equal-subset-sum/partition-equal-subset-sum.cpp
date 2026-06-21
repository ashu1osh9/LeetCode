class Solution {
public:
    vector<vector<int>>dp;
    bool solve(vector<int>& nums, int index, int target) {
        // target mil gaya
        if (target == 0) {
            return true;
        }

        // saare elements khatam ho gaye
        if (index >= nums.size()) {
            return false;
        }
    if(dp[index][target]!= -1){
        return dp[index][target];
    }
        // current element lena
        bool take = false;
        if (nums[index] <= target) {
            take = solve(nums, index + 1, target - nums[index]);
        }

        // current element na lena
        bool nottake = solve(nums, index + 1, target);

        return dp[index][target] = take || nottake;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for (int x : nums) {
            sum += x;
        }
        int m = sum;
        dp.assign(n,vector<int>(m,-1));

        // odd sum ko equal divide nahi kar sakte
        if (sum % 2 != 0) {
            return false;
        }

        int target = sum / 2;

        return solve(nums, 0, target);
    }
};