// // T.C => O(N)
// class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

//         int n = grid.size();

//         // Agar start ya end blocked hai
//         if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
//             return -1;

//         vector<vector<bool>> visited(n, vector<bool>(n, false));

//         vector<pair<int, int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
//                                       {0, 1},   {1, -1}, {1, 0},  {1, 1}};

//         queue<pair<int, int>> q;

//         q.push({0, 0});
//         visited[0][0] = true;

//         int count = 1;

//         while (!q.empty()) {

//             int levelSize = q.size();

//             while (levelSize--) {

//                 auto front = q.front();
//                 q.pop();

//                 int x = front.first;
//                 int y = front.second;

//                 // Destination mil gaya
//                 if (x == n - 1 && y == n - 1)
//                     return count;

//                 // 8 directions me move karo
//                 for (auto d : dir) {

//                     int nx = x + d.first;
//                     int ny = y + d.second;

//                     if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
//                         grid[nx][ny] == 0 && !visited[nx][ny]) {

//                         visited[nx][ny] = true;
//                         q.push({nx, ny});
//                     }
//                 }
//             }

//             count++;
//         }

//         return -1;
//     }
// };

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        // Start ya End blocked hai
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        vector<pair<int,int>> dir = {
            {-1,-1}, {-1,0}, {-1,1},
            { 0,-1},          { 0,1},
            { 1,-1}, { 1,0},  { 1,1}
        };

        queue<pair<pair<int,int>, int>> q;

        q.push({{0,0}, 1});
        visited[0][0] = true;

        while(!q.empty()) {

            auto front = q.front();
            q.pop();

            int x = front.first.first;
            int y = front.first.second;
            int dist = front.second;

            // Destination mil gaya
            if(x == n-1 && y == n-1)
                return dist;

            for(auto d : dir) {

                int nx = x + d.first;
                int ny = y + d.second;

                if(nx >= 0 && ny >= 0 && nx < n && ny < n &&
                   grid[nx][ny] == 0 &&
                   !visited[nx][ny]) {

                    visited[nx][ny] = true;
                    q.push({{nx, ny}, dist + 1});
                }
            }
        }

        return -1;
    }
};