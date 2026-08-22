class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {

        int n = points.size();

        // {weight, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<bool> visited(n, false);

        // {cost, starting node}
        pq.push({0, 0});

        int sum = 0;

        while (!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int weight = curr.first;
            int node = curr.second;

            // Already included in MST
            if (visited[node])
                continue;

            visited[node] = true;

            // Add edge cost
            sum += weight;

            // Current node ko baaki points se connect karo
            for (int next = 0; next < n; next++) {

                if (!visited[next]) {

                    int wt = abs(points[node][0] - points[next][0]) +
                             abs(points[node][1] - points[next][1]);

                    pq.push({wt, next});
                }
            }
        }

        return sum;
    }
};