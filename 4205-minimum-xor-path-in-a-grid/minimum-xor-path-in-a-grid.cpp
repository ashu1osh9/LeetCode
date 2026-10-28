class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(vector<vector<int>>& grid,int i , int j , int x){

        int  n = grid.size();
        int m = grid[0].size();

        if(i == n -1 && j == m-1) return x;

        if(dp[i][j][x]!= -1) return dp[i][j][x];
        int ans = INT_MAX;

        if(i+1<n){

            ans = min(ans,solve(grid,i+1,j,x^grid[i+1][j]));

        }
        if(j+1<m){
            ans = min(ans,solve(grid,i,j+1,x^grid[i][j+1]));
        }
        return dp[i][j][x] = ans;;
    }
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        dp.assign(n, vector<vector<int>>(m, vector<int>(1024, -1)));

        return solve(grid,0,0,grid[0][0]);
        
    }
};