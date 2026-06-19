class Solution {
public: 
// vector<vector<int>>dp;
// // memoization
//  int solve(int m , int n){
//     if(m==0 && n == 0){
//         return 1;

//     }
//     if(m<0 || n<0){
//         return 0;
//     }
//     if(dp[m][n]!=-1){
//         return dp[m][n];
//     }
//     int up = solve(m-1,n);
//     int right = solve(m,n-1);
//     return dp[m][n]= up + right;
    
//  }

// dp top down 

    vector<vector<int>> dp;

    int solve(int m, int n) {

        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0) {
                    continue;
                }

                int up = 0;
                int left = 0;

                if (i > 0) {
                    up = dp[i - 1][j];
                }

                if (j > 0) {
                    left = dp[i][j - 1];
                }

                dp[i][j] = up + left;
            }
        }

        return dp[m - 1][n - 1];
    }

    int uniquePaths(int m, int n) {
        dp.assign(m, vector<int>(n, 0));
        return solve(m, n);
    }
};