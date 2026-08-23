class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& color, int node,
               int currcolor) {

        color[node] = currcolor;

        for (auto& e : adj[node]) {

            if (color[e] == currcolor) {
                return false;
            }

            if (color[e] == -1) {

                int colorV = 1 - currcolor;

                if (dfs(adj, color, e, colorV) == false) {
                    return false;
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<vector<int>> adj(n);
        vector<int>color(n,-1);

        for (int i = 0; i < n; i++) {

            for (int x : graph[i]) {
                adj[i].push_back(x);
            }
        }

        for (int i = 0; i < graph.size(); i++) {

            if (color[i] == -1) {
                if(dfs(adj, color, i, 1)==false) return false;
            }
        }

        return true;
    }
};