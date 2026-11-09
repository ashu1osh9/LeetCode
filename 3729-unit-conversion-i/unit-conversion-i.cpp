class Solution {
public:

     int mod = 1e9 + 7;

    void dfs(int u, vector<vector<pair<int,int>>>& adj,
             vector<int>& ans) {

        for(auto x : adj[u]) {
            int v = x.first;
            int w = x.second;

            ans[v] = (1LL * ans[u] * w) % mod;

            dfs(v, adj, ans);
        }
    }
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size() + 1;

        vector<vector<pair<int,int>>> adj(n);
   for(auto x : conversions) {
            int u = x[0];
            int v = x[1];
            int w = x[2];

            adj[u].push_back({v, w});
        }

        vector<int> ans(n, 0);
        ans[0] = 1;

        dfs(0, adj, ans);

        return ans;
    }
};