class Solution {
public:
    // memoniztion
    vector<int>dp;
    

    int solve(int n) {
    if(n == 0 || n == 1) return 1;
    if(n == 2) return 2;
    if(dp[n]!=-1){
        return dp[n];
    }
    

    int ways1 = solve(n - 1);
    int ways2 = solve(n - 2);

    return dp[n]=ways1 + ways2;
}
    int climbStairs(int n) {
        dp.assign(n+1,-1);
        return solve(n);
        
    }
};