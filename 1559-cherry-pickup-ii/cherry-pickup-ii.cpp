// class Solution {
// public:
//     int solve(int r, int c1, int c2, vector<vector<int>>& grid) {

//         // Agar last row ke baad pahunch gaye to koi cherry nahi bachegi
//         if (r >= grid.size()) {
//             return 0;
//         }

//         // Current row ki cherries collect karo
//         int cherry = grid[r][c1];

//         // Agar dono robots alag-alag cell par hain to dono ki cherries lo
//         if (c1 != c2) {
//             cherry += grid[r][c2];
//         }

//         // ye har path se nikali hue value calculate karega aur store karega 
//         int ans = 0;

//         // Robot 1 ke 3 possible moves
//         for (int dir1 = -1; dir1 <= 1; dir1++) {

//             // Robot 2 ke 3 possible moves
//             for (int dir2 = -1; dir2 <= 1; dir2++) {

//                 // Agli row
//                 int new_row = r + 1;

//                 // Robot 1 ka naya column
//                 int new_col1 = c1 + dir1;

//                 // Robot 2 ka naya column
//                 int new_col2 = c2 + dir2;

//                 // Agar dono robots grid ke andar hain
//                 if (new_col1 >= 0 && new_col1 < grid[0].size() &&
//                     new_col2 >= 0 && new_col2 < grid[0].size()) {

//                     // 9 possible moves me se maximum answer nikalo
//                     ans = max(ans,
//                               solve(new_row, new_col1, new_col2, grid)); // ye har path se ans nikale vlaue ans mei store karega . ,aur agli path se nikale answer ka max value store karegaa
//                 }
//             }
//         }

//         // Current row ki cherries + future ka maximum
//         return cherry + ans;
//     }

//     int cherryPickup(vector<vector<int>>& grid) {

//         int m = grid[0].size();

//         // Robot 1 (0,0) se aur Robot 2 (0,m-1) se start karega
//         return solve(0, 0, m - 1, grid);
//     }
// };
 

 // memo 

class Solution {
public:
    vector<vector<vector<int>>> dp;

    int solve(int r, int c1, int c2, vector<vector<int>>& grid) {

        if (r >= grid.size()) {
            return 0;
        }

        if (dp[r][c1][c2] != -1) {
            return dp[r][c1][c2];
        }

        int cherry = grid[r][c1];

        if (c1 != c2) {
            cherry += grid[r][c2];
        }

        int ans = 0;

        for (int dir1 = -1; dir1 <= 1; dir1++) {
            for (int dir2 = -1; dir2 <= 1; dir2++) {

                int new_row = r + 1;
                int new_col1 = c1 + dir1;
                int new_col2 = c2 + dir2;

                if (new_col1 >= 0 && new_col1 < grid[0].size() &&
                    new_col2 >= 0 && new_col2 < grid[0].size()) {

                    ans = max(ans,
                              solve(new_row, new_col1, new_col2, grid));
                }
            }
        }

        return dp[r][c1][c2] = cherry + ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        dp.assign(n, vector<vector<int>>(m, vector<int>(m, -1)));

        return solve(0, 0, m - 1, grid);
    }
};