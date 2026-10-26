class Solution {
public:
    void dfs(int i, vector<vector<int>>& adj, vector<int>& vis) {
        vis[i] = 1;

        for (auto x : adj[i]) {
            if (vis[x] == 0) {
                dfs(x, adj, vis);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;


        vector<vector<int>> adj(n);

        for (auto x : connections) {
            int i = x[0];
            int j = x[1];

            adj[i].push_back(j);
            adj[j].push_back(i);
        }

        vector<int> vis(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) {
                dfs(i, adj, vis);
                count++;
            }
        }

        return count - 1;
    }
};