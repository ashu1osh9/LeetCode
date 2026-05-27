class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>merged;
        merged.push_back(intervals[0]);
        int  n= intervals.size();
        for(int i = 1;i<n;i++){
            int last = merged.back()[1];
            int nextfirst = intervals[i][0];
            int nextsecond = intervals[i][1];
            // overlap check 
            if(last>=nextfirst){
                merged.back()[1] = max(last,nextsecond); 
            }else{
                merged.push_back(intervals[i]);
            }
        }
        return merged;
    }
};