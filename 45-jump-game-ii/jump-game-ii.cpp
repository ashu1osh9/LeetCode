
// class Solution {
// public:

//     int solve(vector<int>& nums, int index)
//     {
//         if(index >= nums.size() - 1)
//         {
//             return 0;
//         }

//         int ans = INT_MAX;

//         for(int jump = 1; jump <= nums[index]; jump++)
//         {
//             int take = solve(nums, index + jump);

//             if(take != INT_MAX)
//             {
//                 ans = min(ans, 1 + take);
//             }
//         }

//         return ans;
//     }

//     int jump(vector<int>& nums)
//     {
//         return solve(nums, 0);
//     }
// };

class Solution {
public:
    vector<int> dp;

    int solve(vector<int>& nums, int index)
    {
        if(index >= nums.size() - 1)
        {
            return 0;
        }

        if(dp[index] != -1)
        {
            return dp[index];
        }

        int ans = INT_MAX;

        for(int jump = 1; jump <= nums[index]; jump++)
        {
            int take = solve(nums, index + jump);

            if(take != INT_MAX)
            {
                ans = min(ans, 1 + take);
            }
        }

        return dp[index] = ans;
    }

    int jump(vector<int>& nums)
    {
        int n = nums.size();

        dp.assign(n, -1);

        return solve(nums, 0);
    }
};