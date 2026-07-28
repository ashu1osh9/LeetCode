class Solution {
public:

    int n, m;

    vector<vector<int>> dp;

    vector<pair<int,int>> directions = {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };


    int dfs(int i, int j, vector<vector<int>>& matrix) {

        // already calculated
        if(dp[i][j] != -1)
            return dp[i][j];


        int longest = 1;


        for(auto dir : directions) {

            int ni = i + dir.first;
            int nj = j + dir.second;


            if(ni >= 0 && nj >= 0 && ni < n && nj < m &&
               matrix[ni][nj] > matrix[i][j]) {


                int path = 1 + dfs(ni, nj, matrix);

                longest = max(longest, path);
            }
        }


        return dp[i][j] = longest;
    }



    int longestIncreasingPath(vector<vector<int>>& matrix) {

        n = matrix.size();
        m = matrix[0].size();


        dp.assign(n, vector<int>(m, -1));


        int ans = 0;


        for(int i = 0; i < n; i++) {

            for(int j = 0; j < m; j++) {

                ans = max(ans, dfs(i,j,matrix));

            }
        }


        return ans;
    }
};