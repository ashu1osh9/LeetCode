class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int count = 0;
sort(intervals.begin(), intervals.end());
        for(int i = 0; i < n - 1; i++) {
            int first = intervals[i][1];

            for(int j = i + 1; j < n; j++) {

                int second = intervals[j][0];

                if(first >= second) count++;
            }
        }

        return count;
    }
};