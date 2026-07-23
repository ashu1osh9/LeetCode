// class Solution {
// public:
//     int solve(int n ){
//         if(n==1){
//             return 1;

//         }
//         if(n==2){
//             return 2;
//         }
//      int step1 = solve(n-1);
//      int step2 = solve(n-2);
    
//      return step1 + step2;


//     }
//     int climbStairs(int n) {
//         return solve(n);
        
//     }
// };

class Solution {
public:
vector<int>dp;

    int solve(int n ){
        if(n==1){
            return 1;

        }
        if(n==2){
            return 2;
        }
        if(dp[n]!= -1 ){
            return dp[n];
        }
     int step1 = solve(n-1);
     int step2 = solve(n-2);
    
     return dp[n] = step1 + step2;


    }
    int climbStairs(int n) {
        dp.assign(n+1,-1);
        return solve(n);
        
    }
};




// // class Solution {
// // public:
// //     // memoniztion
// //     vector<int>dp;


// //     int solve(int n) {
// //     if(n == 0 || n == 1) return 1;
// //     if(n == 2) return 2;
// //     if(dp[n]!=-1){
// //         return dp[n];
// //     }
    

// //     int ways1 = solve(n - 1);
// //     int ways2 = solve(n - 2);

// //     return dp[n]=ways1 + ways2;
// // }
// //     int climbStairs(int n) {
// //         dp.assign(n+1,-1);
// //         return solve(n);
        
// //     }

//  // top down approach 

// class Solution {
// public:
//     vector<int> dp;

//     int topdown(int n) {

//         dp[0] = 1;
//         if(n >= 1) dp[1] = 1;
//         if(n >= 2) dp[2] = 2;

//         for(int i = 3; i <= n; i++) {
//             dp[i] = dp[i - 1] + dp[i - 2];  
//         }

//         return dp[n];
//     }

//     int climbStairs(int n) {
//         dp.assign(n + 1, 0);   
//         return topdown(n);
//     }
// };