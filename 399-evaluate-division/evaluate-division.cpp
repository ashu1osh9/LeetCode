class Solution {
public:

    unordered_map<string, vector<pair<string, double>>> graph;

    double solve(string curr, string target, unordered_set<string>& visited) {

        if(curr == target)
            return 1.0;

        visited.insert(curr);

        for(auto it : graph[curr]) {

            string next = it.first;
            double weight = it.second;

            if(visited.count(next))
                continue;

            double ans = solve(next, target, visited);

            if(ans != -1.0)
                return weight * ans;
        }

        return -1.0;
    }

    vector<double> calcEquation(
        vector<vector<string>>& equations,
        vector<double>& values,
        vector<vector<string>>& queries) {

        for(int i = 0; i < equations.size(); i++) {

            string a = equations[i][0];
            string b = equations[i][1];

            double value = values[i];

            graph[a].push_back({b, value});
            graph[b].push_back({a, 1.0 / value});
        }

        vector<double> ans;

        for(auto q : queries) {

            string a = q[0];
            string b = q[1];

            if(graph.find(a) == graph.end() ||
               graph.find(b) == graph.end()) {

                ans.push_back(-1.0);
                continue;
            }

            unordered_set<string> visited;

            double value = solve(a, b, visited);

            ans.push_back(value);
        }

        return ans;
    }
};