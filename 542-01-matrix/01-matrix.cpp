class Solution {
public:
    vector<vector<int>> direction = {
        {-1,0},
        {1,0},
        {0,-1},
        {0,1}
    };

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int,int>> que;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    que.push({i, j});
                    vis[i][j] = 1;
                    ans[i][j] = 0;
                }
            }
        }

        int count = 0;

        while(!que.empty()) {

            int sz = que.size();
            count++;

            while(sz--) {

                auto val = que.front();
                que.pop();

                int i = val.first;
                int j = val.second;

                for(auto dir : direction) {

                    int r = i + dir[0];
                    int c = j + dir[1];

                    if(r >= 0 && r < n &&
                       c >= 0 && c < m &&
                       !vis[r][c]) {

                        vis[r][c] = 1;
                        ans[r][c] = count;
                        que.push({r, c});
                    }
                }
            }
        }

        return ans;
    }
};