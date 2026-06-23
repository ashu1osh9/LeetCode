class Solution {
public:
vector<int>dp;
    int solve(vector<vector<int>>&jobs,int index){
        if(index>=jobs.size()){
            return 0;
        }
        if(dp[index]!= -1){
            return dp[index];
        }
        int next = NextElement(jobs,index);
        int take = jobs[index][2] + solve(jobs,next);
        int notTaken = solve(jobs,index+1);
        return dp[index]= max(take,notTaken);
    }
    int NextElement(vector<vector<int>>&jobs,int index){
        int l = index + 1;
        int r = jobs.size() - 1;
        int res = jobs.size();
        
        while(l<=r){
            int mid = l + (r-l)/2;
            if(jobs[mid][0]>=jobs[index][1]){
                res = mid;
                r = mid -1;

            }else{
                l = mid + 1; 
            }
        }
        return res;

    }
    static bool comp(vector<int>&a,vector<int>&b){
        return a[0]<b[0]; // {1,2,3}
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>>jobs;
        dp.assign(n,-1);
        for(int i = 0;i<n;i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});

        }
        // sort karo 
        sort(jobs.begin(),jobs.end(),comp);
        return solve(jobs,0);
        
    }
};