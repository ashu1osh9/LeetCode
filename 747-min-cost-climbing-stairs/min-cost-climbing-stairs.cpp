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
class Solution {
public:
vector<int>dp;
    int solve(int n ,vector<int>&cost){
        if(n==0){
            return cost[0];
        }
        if(n==1){
            return cost[1];
        }
        if(dp[n]!= -1){
            return dp[n];
        }


        int step1 = cost[n] + solve(n-1,cost);
        int step2 = cost[n] + solve(n-2,cost);

        return dp[n] = min(step1,step2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        dp.assign(n,-1);
        int st0 = solve(n-1,cost);
        int st1 = solve(n-2,cost);
        return min(st0,st1);
        
    }
};