// T.C => 0(h) -- finding the safe node thats why ..reverse topology 
// s.c = > O(v)

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        // Reverse Graph
        vector<vector<int>> revGraph(n);

        // Outdegree
        vector<int> outdegree(n, 0);

        for (int i = 0; i < n; i++) {

            outdegree[i] = graph[i].size();

            for (int node : graph[i]) {

                revGraph[node].push_back(i);
            }
        }

        // Queue me sab terminal nodes (outdegree = 0)
        queue<int> que;

        for (int i = 0; i < n; i++) {

            if (outdegree[i] == 0) {

                que.push(i);
            }
        }

        vector<int> ans;

        // BFS (Kahn's Algorithm)
        while (!que.empty()) {

            int curr = que.front();
            que.pop();

            ans.push_back(curr);

            for (int prev : revGraph[curr]) {

                outdegree[prev]--;

                if (outdegree[prev] == 0) {

                    que.push(prev);
                }
            }
        }

        // Ascending order me answer chahiye
        sort(ans.begin(), ans.end());

        return ans;
    }
};