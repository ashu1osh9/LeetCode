// class Solution {
// public:
//     // T.C = ]o(Elog(v))
//     bool dfs(vector<vector<int>>& adj, vector<int>& color, int node,
//                int currcolor) {

//         color[node] = currcolor;

//         for (auto& e : adj[node]) {

//             if (color[e] == currcolor) {
//                 return false;
//             }

//             if (color[e] == -1) {

//                 int colorV = 1 - currcolor;

//                 if (dfs(adj, color, e, colorV) == false) {
//                     return false;
//                 }
//             }
//         }

//         return true;
//     }
//     bool isBipartite(vector<vector<int>>& graph) {

//         int n = graph.size();

//         vector<vector<int>> adj(n);
//         vector<int>color(n,-1);
// //
//         for (int i = 0; i < n; i++) {

//             for (int x : graph[i]) {
//                 adj[i].push_back(x);
//             }
//         }
// 
//         for (int i = 0; i < graph.size(); i++) {

//             if (color[i] == -1) {
//                 if(dfs(adj, color, i, 1)==false) return false;
//             }
//         }

//         return true;
//     }
// };

// BFS - -- > T.C => O(Elogv)
class Solution {
public:

    bool bfs(int start, vector<vector<int>>& graph, vector<int>& color) {

        queue<int> q;

        color[start] = 1;
        q.push(start);

        while(!q.empty()) { // O(V)

            int node = q.front();
            q.pop(); // T.C = O(logv)

            for(auto e : graph[node]) { // O(E)

                if(color[e] == color[node]) {
                    return false;
                }

                if(color[e] == -1) {
                    color[e] = 1 - color[node];
                    q.push(e);  // O(logv)
                }
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int v = graph.size();

        vector<int> color(v, -1);

        for(int i = 0; i < v; i++) {

            if(color[i] == -1) {

                bool ans = bfs(i, graph, color);

                if(ans == false) {
                    return false;
                }
            }
        }

        return true;
    }
};