class Solution {
public:
 // recursion  
//  int solve(vector<vector<int>>& grid,int m,int n){
//     if(m==0 && n == 0){
//         return grid[m][n];
//     }
//     if(m<0 || n<0){
//         return 1e9; // not return 0; kyuki bahar wale path ko bhi recursion maan lega.
//     }
//     int up = grid[m][n] + solve(grid,m-1,n);
//     int left = grid[m][n] + solve(grid,m,n-1);
//     return min(up,left);
//  }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         return solve(grid,m-1,n-1);
        
//     }
 // memoization
    // vector<vector<int>> dp;

    // int solve(vector<vector<int>>& grid, int m, int n) {
    //     if (m == 0 && n == 0) {
    //         return grid[0][0];
    //     }

    //     if (m < 0 || n < 0) {
    //         return 1e9;
    //     }

    //     if (dp[m][n] != -1) {
    //         return dp[m][n];
    //     }

    //     int up = grid[m][n] + solve(grid, m - 1, n);
    //     int left = grid[m][n] + solve(grid, m, n - 1);

    //     return dp[m][n] = min(up, left);
    // }

    // int minPathSum(vector<vector<int>>& grid) {
    //     int m = grid.size();
    //     int n = grid[0].size();

    //     dp.assign(m, vector<int>(n, -1));

    //     return solve(grid, m - 1, n - 1);
    // }
    // top down 

     vector<vector<int>> dp;

    int solve(vector<vector<int>>& grid, int m, int n) {
        dp[0][0] = grid[0][0];
        

    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            if(i==0 && j==0){
                continue;
            }
            int up = 1e9;
            int left =1e9;
            if(i>0){
                  up = grid[i][j] + dp[ i - 1][j];
            }
            if(j>0){
                 left = grid[i][j] + dp [i][j - 1];
            }
         dp[i][j] = min(up, left);
        }
    }
    return dp[m-1][n-1];

    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        dp.assign(m, vector<int>(n, 0));

        return solve(grid, m , n );
    }
};