class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int j = 1;
        int ans = INT_MIN;
        if(nums.size()<2){
            return 0;
        }
        for(int i = 0;i<nums.size()-1;i++){
            int diff = abs(nums[i] - nums[j]);
            ans = max(ans,diff);
            j++;

        }
        return ans;
        
    }
};