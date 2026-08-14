// recursion 
// class Solution {
// public:
//     int solve(vector<vector<int>>& grid, int i1, int j1, int i2, int j2) {

//         int n = grid.size();

//         // Out of bound
//         if (i1 >= n || j1 >= n || i2 >= n || j2 >= n)
//             return -1e9;

//         // Thorn / blocked cell
//         if (grid[i1][j1] == -1 || grid[i2][j2] == -1)
//             return -1e9;

//         // Dono end par pahunch gaye
//         if (i1 == n - 1 && j1 == n - 1 && i2 == n - 1 && j2 == n - 1)
//             return grid[i1][j1];

//         // Current contribution
//         int cherries = 0;

//         if (i1 == i2 && j1 == j2) {

//             if (grid[i1][j1] == 1)
//                 cherries++;
//         } else {

//             if (grid[i1][j1] == 1)
//                 cherries++;

//             if (grid[i2][j2] == 1)
//                 cherries++;
//         }

//         // 4 choices

//         int right_right = cherries + solve(grid, i1, j1 + 1, i2, j2 + 1);

//         int right_down = cherries + solve(grid, i1, j1 + 1, i2 + 1, j2);

//         int down_right = cherries + solve(grid, i1 + 1, j1, i2, j2 + 1);

//         int down_down = cherries + solve(grid, i1 + 1, j1, i2 + 1, j2);

//         return max({right_right, right_down, down_right, down_down});
//     }

//     int cherryPickup(vector<vector<int>>& grid) {
//         return max(0, solve(grid, 0, 0, 0, 0));
//     }
// };

// memoization -- 
class Solution {
public:

    vector<vector<vector<vector<int>>>> dp;

    int solve(vector<vector<int>>& grid, int i1, int j1, int i2, int j2) {

        int n = grid.size();

        // Out of bound
        if (i1 >= n || j1 >= n || i2 >= n || j2 >= n)
            return -1e9;

        // Thorn / blocked cell
        if (grid[i1][j1] == -1 || grid[i2][j2] == -1)
            return -1e9;

        // Already calculated
        if (dp[i1][j1][i2][j2] != -1)
            return dp[i1][j1][i2][j2];

        // Dono end par pahunch gaye
        if (i1 == n - 1 && j1 == n - 1 &&
            i2 == n - 1 && j2 == n - 1) {

            return dp[i1][j1][i2][j2] = grid[i1][j1];
        }

        // Current contribution
        int cherries = 0;

        if (i1 == i2 && j1 == j2) {

            if (grid[i1][j1] == 1)
                cherries++;

        } else {

            if (grid[i1][j1] == 1)
                cherries++;

            if (grid[i2][j2] == 1)
                cherries++;
        }

        // 4 choices

        int right_right =
            cherries + solve(grid, i1, j1 + 1, i2, j2 + 1);

        int right_down =
            cherries + solve(grid, i1, j1 + 1, i2 + 1, j2);

        int down_right =
            cherries + solve(grid, i1 + 1, j1, i2, j2 + 1);

        int down_down =
            cherries + solve(grid, i1 + 1, j1, i2 + 1, j2);

        return dp[i1][j1][i2][j2] =
            max({right_right, right_down, down_right, down_down});
    }


    int cherryPickup(vector<vector<int>>& grid) {

        int n = grid.size();

        dp.resize(n,
            vector<vector<vector<int>>>(
                n,
                vector<vector<int>>(
                    n,
                    vector<int>(n, -1)
                )
            )
        );

        return max(0, solve(grid, 0, 0, 0, 0));
    }
};