class Solution {
public:
    typedef pair<int, int> P;
    vector<vector<int>> direction = {{-1,0},{1,0},{0,-1},{0,1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<P> q;
        int freshOranges = 0;
        int minutes = 0;

        // Push all rotten oranges and count fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                else if (grid[i][j] == 1) {
                    freshOranges++;
                }
            }
        }

        if (freshOranges == 0)
            return 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                P curr = q.front();
                q.pop();

                int i = curr.first;
                int j = curr.second;

                for (vector<int>& dir : direction) {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];

                    if (new_i >= 0 && new_i < n &&
                        new_j >= 0 && new_j < m &&
                        grid[new_i][new_j] == 1) {

                        grid[new_i][new_j] = 2;
                        freshOranges--;
                        q.push({new_i, new_j});
                    }
                }
            }

            minutes++;
        }

        if (freshOranges == 0)
            return minutes - 1;

        return -1;
    }
};