// class Solution {
// public:
//     int solve(int i, int j, vector<vector<int>>& triangle,
//               vector<vector<int>>& dp) {

//         // Base Case
//         if (i == triangle.size() - 1)
//             return triangle[i][j];

//         // Already calculated
//         if (dp[i][j] != -1)
//             return dp[i][j];

//         int down = triangle[i][j] + solve(i + 1, j, triangle, dp);

//         int diagonal = triangle[i][j] + solve(i + 1, j + 1, triangle, dp);

//         return dp[i][j] = min(down, diagonal);
//     }

//     int minimumTotal(vector<vector<int>>& triangle) {

//         int n = triangle.size();

//         vector<vector<int>> dp(n, vector<int>(n, -1));

//         return solve(0, 0, triangle, dp);
//     }
// };

// class Solution {
// public:
//     int solve(int i, int j, vector<vector<int>>& triangle) {

//         // Invalid position
//         if (j < 0 || j > i)
//             return 1e9;

//         // Base Case
//         if (i == 0 && j == 0)
//             return triangle[0][0];

//         // Upar wale same column se aao
//         int up = triangle[i][j] + solve(i - 1, j, triangle);

//         // Upar-left (diagonal) se aao
//         int diagonalUp = triangle[i][j] + solve(i - 1, j - 1, triangle);

//         // Dono me se minimum path choose karo
//         return min(up, diagonalUp);
//     }

//     int minimumTotal(vector<vector<int>>& triangle) {

//         int n = triangle.size();

//         int ans = INT_MAX;

//         // Last row ke columns ko right se left traverse karo
//         for (int j = n - 1; j >= 0; j--) {

//             // Har last row element se top tak ka minimum path nikalo
//             ans = min(ans, solve(n - 1, j, triangle));
//         }

//         return ans;
//     }
// };

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& triangle,
              vector<vector<int>>& dp) {

        // Invalid position
        if (j < 0 || j > i)
            return 1e9;

        // Base Case
        if (i == 0 && j == 0)
            return triangle[0][0];

        // Agar pehle se answer calculate hai
        if (dp[i][j] != -1)
            return dp[i][j];

        // Same column ke upar jao
        int up = triangle[i][j] + solve(i - 1, j, triangle, dp);

        // Diagonal up (left) jao
        int diagonalUp = triangle[i][j] + solve(i - 1, j - 1, triangle, dp);

        // Minimum answer store karke return karo
        return dp[i][j] = min(up, diagonalUp);
    }

    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int ans = INT_MAX;

        // Last row ke har element se top tak ka minimum path
        for (int j = n - 1; j >= 0; j--) {
            ans = min(ans, solve(n - 1, j, triangle, dp));
        }

        return ans;
    }
};