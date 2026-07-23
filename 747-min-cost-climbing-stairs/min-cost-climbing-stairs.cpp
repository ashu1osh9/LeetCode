// class Solution {
// public:
//     int solve(int n ,vector<int>&cost){
//         if(n==0){
//             return cost[0];
//         }
//         if(n==1){
//             return cost[1];
//         }

//         int step1 = cost[n] + solve(n-1,cost);
//         int step2 = cost[n] + solve(n-2,cost);

//         return min(step1,step2);
//     }
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         int st0 = solve(n-1,cost);
//         int st1 = solve(n-2,cost);
//         return min(st0,st1);
        
//     }
// };


//  memoization 
// class Solution {
// public:
// vector<int>dp;
//     int solve(int n ,vector<int>&cost){
//         if(n==0){
//             return cost[0];
//         }
//         if(n==1){
//             return cost[1];
//         }
//         if(dp[n]!= -1){
//             return dp[n];
//         }


//         int step1 = cost[n] + solve(n-1,cost);
//         int step2 = cost[n] + solve(n-2,cost);

//         return dp[n] = min(step1,step2);
//     }
//     int minCostClimbingStairs(vector<int>& cost) {
//         int n = cost.size();
//         dp.assign(n,-1);
//         int st0 = solve(n-1,cost);
//         int st1 = solve(n-2,cost);
//         return min(st0,st1);
        
//     }
// };


// tabulation 

class Solution {
public:
vector<int>dp;
   
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.assign(n,-1);


        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 0;i<n;i++){
            int step1 = 0 ;
            int step2 = 0;
            if(i==0 || i == 1){
                continue;
            }
            if(n-1>0){
                step1 = cost[i] + dp[i-1];
            }
        
            if(n-2>0){

                step2 = cost[i] + dp[i-2];
            }

         dp[i] = min(step1,step2);
        
    }

    return min(dp[n-1],dp[n-2]);
    }
};