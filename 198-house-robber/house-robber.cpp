class Solution {
public:
// memoization
    vector<int>dp;
    int solve(vector<int>&nums,int n){
        if(n==0){
            return nums[0];
        }
        if(n<0){
            return 0 ;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int stolen = nums[n] + solve(nums,n-2);
        int notstolen = solve(nums,n-1);
        return dp[n] = max(stolen,notstolen);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];

        }
        if(n==2){
            return max(nums[0],nums[1]);

        }
        dp.assign(n,-1);
        return solve(nums,n-1);

        
    }
};