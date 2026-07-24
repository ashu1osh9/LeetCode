// class Solution {
// public:
//  // memoization
//     vector<int>dp;
//     int solve(vector<int>&nums,int n){
//         if(n==0){
//             return nums[0];
//         }
//         if(n<0){
//             return 0 ;
//         }
//         if(dp[n]!=-1){
//             return dp[n];
//         }
//         int stolen = nums[n] + solve(nums,n-2);
//         int notstolen = solve(nums,n-1);
//         return dp[n] = max(stolen,notstolen);
//     }

//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if(n==1){
//             return nums[0];

//         }
//         if(n==2){
//             return max(nums[0],nums[1]);

//         }
//         dp.assign(n,-1);
//         return solve(nums,n-1);

        
//     }
   
// };


// // recursion n to 0 
// class Solution {
// public:

//     int solve(vector<int>&nums,int n ){
//         if(n==0){
//             return nums[0];
//         }
//         if(n<0){
//             return 0;
//         }
//         if(n==1){
//             return max(nums[0],nums[1]);
//         }

//         int h1 = nums[n] + solve(nums,n-2);
//         int h2 = solve(nums,n-1);

//         return max(h1,h2);
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         return solve(nums,n-1);
        
//     }
// };

// // recursion 0 to n 

// class Solution {
// public:

//     int solve(vector<int>&nums,int n ){
//         if(n>=nums.size()){
//             return 0;
//         }


//         int h1 = nums[n] + solve(nums,n+2);
//         int h2 = solve(nums,n+1);

//         return max(h1,h2);
//     }
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         return solve(nums,0);
        
//     }
// };

// tabulation  with transition state define the table 

class Solution {
public:
    vector<int> dp;

    int rob(vector<int>& nums) {

        int n = nums.size();

        dp.assign(n + 2, 0);

        dp[n] = 0;
        dp[n + 1] = 0;

        for(int i = n - 1; i >= 0; i--) {

            int h1 = nums[i] + dp[i + 2];
            int h2 = dp[i + 1];

            dp[i] = max(h1, h2);
        }

        return dp[0];
    }
};