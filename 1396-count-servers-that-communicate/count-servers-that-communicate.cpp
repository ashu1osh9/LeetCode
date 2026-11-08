class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        stack<pair<int,int>> st;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    st.push({i,j});
                }
            }
        }

        int count = 0;

        while(!st.empty()) {
            auto p = st.top();
            st.pop();

            int i = p.first;
            int j = p.second;
            bool ok = false;

            for(int x = 0; x < n; x++) {
                if(x != i && grid[x][j] == 1) {
                    ok = true;
                    break;
                }
            }

            for(int y = 0; y < m; y++) {
                if(y != j && grid[i][y] == 1) {
                    ok = true;
                    break;
                }
            }

            if(ok) count++;
        }

        return count;
    }
};
