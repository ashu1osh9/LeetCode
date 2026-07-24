// class Solution {
// public:
//     // memoization
//     vector<int> dp;

//     int solve(vector<int>& nums, int st, int end) {
//         if (st > end) {
//             return 0;
//         }

//         if (dp[st] != -1) {
//             return dp[st];
//         }

//         int take = nums[st] + solve(nums, st + 2, end);
//         int notTake = solve(nums, st + 1, end);

//         return dp[st] = max(take, notTake);
//     }

//     int rob(vector<int>& nums) {
//         int n = nums.size();

//         if (n == 1) {
//             return nums[0];
//         }

//         dp.assign(n, -1);
//         int first = solve(nums, 0, n - 2); // 

//         dp.assign(n, -1);  
//         int last = solve(nums, 1, n - 1); // 

//         return max(first, last);
//     }

   
    
// };

// class Solution {
// public:
//     vector<int> dp;

//     int solve(vector<int>& nums, int start, int end) {
//         if (start == end) {
//             return nums[start];
//         }

//         dp[start] = nums[start];
//         dp[start + 1] = max(nums[start], nums[start + 1]);

//         for (int i = start + 2; i <= end; i++) {
//             int take = nums[i] + dp[i - 2];
//             int notTake = dp[i - 1];

//             dp[i] = max(take, notTake);
//         }

//         return dp[end];
//     }

//     int rob(vector<int>& nums) {
//         int n = nums.size();

//         if (n == 1) {
//             return nums[0];
//         }

//         // Case 1: last house excluded
//         dp.assign(n, 0);
//         int first = solve(nums, 0, n - 2);

//         // Case 2: first house excluded
//         dp.assign(n, 0);
//         int last = solve(nums, 1, n - 1);

//         return max(first, last);
//     }
// };

// recursion 0 to n 
// class Solution {
// public:
//      int solve(vector<int>&nums,int st,int ed){
//         if(st>ed){
//             return 0;

//         }
       

//         int take = nums[st] + solve(nums,st+2,ed);
//         int nottake = solve(nums,st+1,ed);

//         return max(take ,nottake);
//      }

//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if(n==1){
//             return nums[0];
//         }
//         // last house ko bahar kar de 

//         int first = solve(nums,0,n-2);

//         // first house ko bahar kar de 

//         int last = solve(nums,1,n-1);

//         return max(first,last);
        
//     }
// };
// dp size without if condition -- tabulation
class Solution {
public:
    vector<int> dp;

    int solve(vector<int>& nums, int st, int ed)
    {
        int n = nums.size();

        dp.assign(n + 2, 0);

        for(int i = ed; i >= st; i--)
        {
            int take = nums[i] + dp[i + 2];
            int nottake = dp[i + 1];

            dp[i] = max(take, nottake);
        }

        return dp[st];
    }

    int rob(vector<int>& nums)
    {
        int n = nums.size();

        if(n == 1)
        {
            return nums[0];
        }

        int first = solve(nums, 0, n - 2);

        int last = solve(nums, 1, n - 1);

        return max(first, last);
    }
};