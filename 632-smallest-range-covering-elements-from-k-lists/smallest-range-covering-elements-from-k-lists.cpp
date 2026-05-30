class Solution {
public:

    vector<int> smallestRange(vector<vector<int>>& a) {

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > q;

        int mx = -1e9;

        int k = a.size();

        for (int i = 0; i < k; i++) {

            q.push({a[i][0], i, 0});

            mx = max(mx, a[i][0]);
        }

        int l = 0, r = 1e9;

        while (1) {

            auto t = q.top();
            q.pop();

            int mn = t[0];
            int i = t[1];
            int j = t[2];

            if (mx - mn < r - l) {
                l = mn;
                r = mx;
            }

            if (j + 1 == a[i].size()) break;

            int x = a[i][j + 1];

            q.push({x, i, j + 1});

            mx = max(mx, x);
        }

        return {l, r};
    }
};