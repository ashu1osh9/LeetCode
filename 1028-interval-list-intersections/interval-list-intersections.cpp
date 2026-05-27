class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {

        int n = firstList.size();
        int m = secondList.size();

        vector<vector<int>> res;

        int i = 0;
        int j = 0;

        while(i < n && j < m) {

            int currentfirst = firstList[i][0];
            int currentsecond = firstList[i][1];

            int nextfirst = secondList[j][0];
            int nextsecond = secondList[j][1];

            // intersection
            int left = max(currentfirst, nextfirst);
            int right = min(currentsecond, nextsecond);

            // valid intersection
            if(left <= right) {

                res.push_back({left, right});
            }

            // move pointer whose interval ends first
            if(currentsecond < nextsecond) {
                i++;
            }
            else {
                j++;
            }
        }

        return res;
    }
};