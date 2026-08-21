class Solution {
public:
int dp[105][105];
    int solve(vector<int>& cuts,  int i , int j){


        if(j == i + 1){
            return 0;
        }
        if(dp[i][j] != -1)
            {
                return dp[i][j];
            }
        int res = INT_MAX;

        for(int k = i+1;k<j;k++){

            int cost = cuts[j] - cuts[i] + solve(cuts , i,k) + solve(cuts,k,j);

            res = min(cost,res);
        }        
        
        return dp[i][j]= res;
        
        
        
            }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
      
       memset(dp,-1,sizeof(dp));

        return solve(cuts, 0, cuts.size()-1);
        
    }
};