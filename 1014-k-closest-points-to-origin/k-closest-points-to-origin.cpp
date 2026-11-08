class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        vector<pair<int,pair<int,int>>> dis;
        for(int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];

            int val = x*x + y*y;

            dis.push_back({val,{x,y}});
        }

        sort(dis.begin(), dis.end());
        vector<vector<int>> ans;

        for(int i = 0; i < k; i++) {
            int x = dis[i].second.first;
            int y = dis[i].second.second;

            ans.push_back({x,y});
        }

        return ans;
    }
};