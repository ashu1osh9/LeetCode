class Solution {
public:
    vector<int>dp;

    bool solve(int n){

        if(n== 0){
            return false;
        }
        if(dp[n]!= -1){
            return dp[n];
        }

        for(int k = 1 ;k*k<=n;k++){

            bool result = solve(n-k*k); // bob apna baytage ki kya woh jeeta 
            if(result == false){ 
                return dp[n] = true ;
            }
        }
        return dp[n] = false;
    }
    bool winnerSquareGame(int n) {
        dp.clear();
        dp.assign(n+1,-1);

        return solve(n);
        
    }
};