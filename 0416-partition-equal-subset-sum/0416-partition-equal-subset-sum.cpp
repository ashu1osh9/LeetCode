
// class Solution {
// public:
//     vector<vector<int>>dp;
//     bool solve(vector<int>& nums, int index, int target) {
//         // target mil gaya
//         if (target == 0) {
//             return true;
//         }

//         // saare elements khatam ho gaye
//         if (index >= nums.size()) {
//             return false;
//         }
//     if(dp[index][target]!= -1){
//         return dp[index][target];
//     }
//         // current element lena
//         bool take = false;
//         if (nums[index] <= target) {
//             take = solve(nums, index + 1, target - nums[index]);
//         }

//         // current element na lena
//         bool nottake = solve(nums, index + 1, target);

//         return dp[index][target] = take || nottake;
//     }

//     bool canPartition(vector<int>& nums) {
//         int sum = 0;
//         int n = nums.size();

//         for (int x : nums) {
//             sum += x;
//         }
//         int m = sum;
//         dp.assign(n,vector<int>(m,-1));

//         // odd sum ko equal divide nahi kar sakte
//         if (sum % 2 != 0) {
//             return false;
//         }

//         int target = sum / 2;

//         return solve(nums, 0, target);
//     }
// };

// class Solution {
// public:
//     bool solve(vector<int>&nums,int sum,int n){
//         if(sum==0){
//             return true;
//         }
//         if(n>=nums.size()){
//             return false;
//         }
//         bool take = false;
//         if(nums[n]<=sum){
//             take = solve(nums,sum-nums[n],n+1);
//         }
//         bool nottake = solve(nums,sum,n+1);

//         return take || nottake;
 
//     }
//     bool canPartition(vector<int>& nums) {
//         int total = 0;
//         for(int sum :nums){
//             total+=sum;
//         }
//         if(total %2 != 0){
//             return false;
//         }
//         total = total/2;
//         return solve(nums,total,0);
        
//     }
// };

// tabulation 

class Solution {
public:

    bool isSubsetSum(vector<int>& nums, int target) {

        int n = nums.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));

        // Base Condition 1
        for(int i = 0; i <= n; i++)
        {
            dp[i][0] = true;
        }

        // Base Condition 2
        for(int sum = 1; sum <= target; sum++)
        {
            dp[n][sum] = false;
        }

        // Fill DP Table
        for(int i = n - 1; i >= 0; i--)
        {
            for(int sum = 1; sum <= target; sum++)
            {
                bool take = false;

                if(nums[i] <= sum)
                {
                    take = dp[i + 1][sum - nums[i]];
                }

                bool nottake = dp[i + 1][sum];

                dp[i][sum] = take || nottake;
            }
        }

        return dp[0][target];
    }

    bool canPartition(vector<int>& nums) {

        int totalSum = 0;

        for(int x : nums)
        {
            totalSum += x;
        }

        if(totalSum % 2 != 0)
        {
            return false;
        }

        return isSubsetSum(nums, totalSum / 2);
    }
};