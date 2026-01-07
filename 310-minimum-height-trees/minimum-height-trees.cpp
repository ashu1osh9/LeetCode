class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& e) {
        if (n == 1) return {0};
        if (n == 2) return {0, 1};
        
        vector<unordered_set<int>> g(n);
        for (auto& ed : e) {
            int u = ed[0], v = ed[1];
            g[u].insert(v);
            g[v].insert(u);
        }
        
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (g[i].size() == 1) q.push(i);
        }
        
        int cnt = n;
        while (cnt > 2) {
            int sz = q.size();
            cnt -= sz;
            
            for (int i = 0; i < sz; i++) {
                int l = q.front(); q.pop();
                int nb = *g[l].begin();
                
                g[nb].erase(l);
                if (g[nb].size() == 1) q.push(nb);
                
                g[l].clear();
            }
        }
        
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        
        return res;
    }
};
